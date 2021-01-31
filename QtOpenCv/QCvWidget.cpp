#include "QCvWidget.h"
#include "ui_qcvwidget.h"
#include "OpenCvWorker.h"
#include <QTimer>
#include <QMessageBox>

QCvWidget::QCvWidget(QWidget *parent):
    QWidget(parent),
    _ui(new Ui::QCvWidget)
{
    _ui->setupUi(this);
    _ui->labelView->setScaledContents(true);
    //_ui->label
    _init();
}

QCvWidget::~QCvWidget(){
    if (_thread->isRunning()) {
        qDebug("Quitting OpenCv worker thread");
        _thread->quit();
    }
    while (!_thread->isFinished());

    delete _thread;
    delete _ui;
}

void QCvWidget::_init(){
    //dont let Push Play if no stream Src specified
    _ui->pushButtonPlay->setEnabled(!_ui->lineEditStream->isEnabled());
    connect(_ui->lineEditStream, &QLineEdit::textChanged, [this](const QString & text) {
      _ui->pushButtonPlay->setEnabled(!text.isEmpty());
    });

    _thread = new QThread();
    OpenCvWorker * worker = new OpenCvWorker();
    QTimer *workerTrigger = new QTimer();
    workerTrigger->setInterval(1); //test 0 here

    //try to grab a new frame every time timeout triggers
    connect(workerTrigger, SIGNAL(timeout()), worker, SLOT(rcvGrabFrame()) );

    connect(this, SIGNAL(sendSetup(int)), worker, SLOT(rcvGrabFrame()));


    //call func everytime PushButton is clicked
    connect(_ui->pushButtonPlay, SIGNAL(clicked(bool)), this, SLOT(rcvToggleStream()) );
    //send EnableBinThresh checkbox value everytime it updates
    connect(_ui->checkBoxEnableBinaryThreshold, SIGNAL(toggled(bool)), worker, SLOT(rcvEnableBinaryThreshold()));
    //send new thresh each time spinbox updates
    connect(_ui->spinBoxBinaryThreshold, SIGNAL(valueChanged(int)), worker, SLOT(rcvBinaryThreshold(int)));
    //rcv each frame sent by openCv module and render on UI
    connect(worker, SIGNAL(sendFrame(QImage)), this, SLOT(rcvFrame(QImage)));
    //When play button pressed-> send textbox value
    connect(this, SIGNAL(sendStreamSrc(const QString &)), worker, SLOT(rcvPlayStreamSrc(const QString &)));
    //When invalid capture dev is specified
    connect( worker, SIGNAL(sendWarnInvalidCaptureDevice(const QString &)), this, SLOT(rcvInvalidCapDev(const QString &)) );


    workerTrigger->start();
    worker->moveToThread(_thread);
    workerTrigger->moveToThread(_thread);
    _thread->start();
    emit sendSetup(0);


}



void QCvWidget::rcvFrame(QImage frame){
    _ui->labelView->setPixmap(QPixmap::fromImage(frame));
}

void QCvWidget::rcvInvalidCapDev(const QString &device){
    char aux_warnMsg[200];
    sprintf(aux_warnMsg, "The Capture device specified \"%s\" is invalid.\nPlease input another one and retry", qUtf8Printable(device));
    QMessageBox::warning(0, QString("Invalid Capture Device"), aux_warnMsg, QMessageBox::Ok);
    _toggleVisualBottomBar();

}


void QCvWidget::rcvToggleStream(){

    _toggleVisualBottomBar();
    emit sendStreamSrc(_ui->lineEditStream->text());
}

void QCvWidget::_toggleVisualBottomBar(){
    if(!_ui->pushButtonPlay->text().compare("Play")){
        _ui->pushButtonPlay->setText("Pause");
        _ui->lineEditStream->setReadOnly(true);
        _ui->lineEditStream->setStyleSheet("background: grey;");

    } else{
        _ui->pushButtonPlay->setText("Play");
        _ui->lineEditStream->setReadOnly(false);
        _ui->lineEditStream->setStyleSheet("background: white;");
    }

}
