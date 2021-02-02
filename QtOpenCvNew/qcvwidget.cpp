#include "qcvwidget.h"
#include "ui_qcvwidget.h"
#include <QMessageBox>

QCvWidget::QCvWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QCvWidget),
      myCvAgent(nullptr)
{
    ui->setupUi(this);
    ui->pushButtonPlay->setEnabled(!ui->lineEditStream->text().isEmpty());
    ui->labelViewOriginal->setScaledContents(true);
    ui->labelViewOriginal->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    _init();
}

QCvWidget::~QCvWidget()
{
    delete ui;
    delete myCvAgent;
}


void QCvWidget::_init(){
    myCvAgent = new OpenCvAgent;
    //dont let Push Play if no stream Src specified
    //ui->pushButtonPlay->setEnabled(ui->lineEditStream->isEnabled());
    connect(ui->lineEditStream, &QLineEdit::textChanged, [this](const QString & text) {
      ui->pushButtonPlay->setEnabled(!text.isEmpty());
    });
    connect(this, SIGNAL(signalSendStreamSrc(const QString &)), myCvAgent, SLOT(slotPlayStreamSource(const QString &)));
    connect(ui->comboBoxFilterType, SIGNAL(currentIndexChanged(int)), myCvAgent, SLOT(setFilterType(int)) );
    connect(ui->pushButtonPlay, &QPushButton::clicked,this, [this]() {
       qDebug("Send Stream Src: %s", qUtf8Printable(ui->lineEditStream->text()));
       emit signalSendStreamSrc(ui->lineEditStream->text());
    });

    connect(myCvAgent, SIGNAL(signalSendFrames(QImage &,QImage &)), this, SLOT(slotRcvNewFrames(QImage &, QImage &)));
    connect(ui->spinBoxBinThresh, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setBinaryThresh(int)));
    connect( myCvAgent, SIGNAL(signalWarnInvalidCaptureDevice(void)),this,SLOT(slotRcvInvalidCapDev(void)));



//    _thread = new QThread();
//    OpenCvWorker * worker = new OpenCvWorker();
//    QTimer *workerTrigger = new QTimer();
//    workerTrigger->setInterval(1); //test 0 here

    //try to grab a new frame every time timeout triggers
  //  connect(workerTrigger, SIGNAL(timeout()), worker, SLOT(rcvGrabFrame()) );

    //connect(this, SIGNAL(sendSetup(int)), myCvAgent, SLOT(rcvGrabFrame()));


    //call func everytime PushButton is clicked
    //connect(ui->pushButtonPlay, SIGNAL(clicked(bool)), this, SLOT(rcvButtonPlayPressed()) );
    //send EnableBinThresh checkbox value everytime it updates
    //connect(_ui->checkBoxEnableBinaryThreshold, SIGNAL(toggled(bool)), worker, SLOT(rcvEnableBinaryThreshold()));
    //send new thresh each time spinbox updates
    //connect(_ui->spinBoxBinaryThreshold, SIGNAL(valueChanged(int)), worker, SLOT(rcvBinaryThreshold(int)));
    //rcv each frame sent by openCv module and render on UI
    //connect(myCvAgent, SIGNAL(sendFrame(QImage)), this, SLOT(rcvOriginalFrame(QImage)));
    //When play button pressed-> send textbox value
    //connect(this, SIGNAL(sendStreamSrc(const QString &)), myCvAgent, SLOT(rcvPlayStreamSrc(const QString &)));
    //When invalid capture dev is specified
    //connect( worker, SIGNAL(sendWarnInvalidCaptureDevice(const QString &)), this, SLOT(rcvInvalidCapDev(const QString &)) );


//    workerTrigger->start();
//    worker->moveToThread(_thread);
//    workerTrigger->moveToThread(_thread);
//    _thread->start();
  //  emit sendSetup(0);


}

//void QCvWidget::rcvButtonPlayPressed(){
//    emit sendStreamSrc(ui->lineEditStream->text());
//}

void QCvWidget::slotRcvNewFrames(QImage &inpFr, QImage &outFr){
    qDebug("RCV frames");
    ui->labelViewOriginal->setPixmap(QPixmap::fromImage(inpFr).scaled(ui->labelViewOriginal->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->labelViewProcessed->setPixmap(QPixmap::fromImage(outFr));

}

void QCvWidget::slotRcvInvalidCapDev(void){
    char aux_warnMsg[200];
    sprintf(aux_warnMsg, "The Capture device specified \"%s\" is invalid.\nPlease input another one and retry", qUtf8Printable(ui->lineEditStream->text()));
    QMessageBox::warning(0, QString("Invalid Capture Device"), aux_warnMsg, QMessageBox::Ok);

}

