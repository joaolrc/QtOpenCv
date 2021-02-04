#include "qcvwidget.h"
#include "ui_qcvwidget.h"
#include <QMessageBox>


QCvWidget::QCvWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::QCvWidget),
    myCvAgent(nullptr)
{
    ui->setupUi(this);



    ui->pushButtonPlay->setEnabled(!ui->lineEditStream->text().isEmpty());
    //ui->labelViewOriginal->setScaledContents(true); //?


    ui->spinBoxBinThresh->setMaximum(UINT8_MAX);
    ui->spinBoxHmax->setMaximum(OCA_MAXVAL_HUE);
    ui->spinBoxSmax->setMaximum(OCA_MAXVAL_SAT);
    ui->spinBoxVmax->setMaximum(OCA_MAXVAL_VAL);
    ui->spinBoxRmax->setMaximum(OCA_MAXVAL_RED);
    ui->spinBoxGmax->setMaximum(OCA_MAXVAL_GREEN);
    ui->spinBoxBmax->setMaximum(OCA_MAXVAL_BLUE);
    ui->spinBoxHmax->setValue(OCA_HSVRGB_MAX_DEFAULT_VAL);
    ui->spinBoxSmax->setValue(OCA_HSVRGB_MAX_DEFAULT_VAL);
    ui->spinBoxVmax->setValue(OCA_HSVRGB_MAX_DEFAULT_VAL);
    ui->spinBoxRmax->setValue(OCA_HSVRGB_MAX_DEFAULT_VAL);
    ui->spinBoxGmax->setValue(OCA_HSVRGB_MAX_DEFAULT_VAL);
    ui->spinBoxBmax->setValue(OCA_HSVRGB_MAX_DEFAULT_VAL);
    setBinVisibility(false);
    setHsvVisibility(false);
    setRgbVisibility(true);

    myCvAgent = new OpenCvAgent;
    _init();
}

QCvWidget::~QCvWidget()
{
    delete myCvAgent;
    delete ui;

}


void QCvWidget::_init(){
    //dont let Push Play if no stream Src specified
    connect(ui->lineEditStream, &QLineEdit::textChanged, [this](const QString & text) {
      ui->pushButtonPlay->setEnabled(!text.isEmpty());
    });

    connect(this, SIGNAL(signalSendStreamSrc(const QString &)), myCvAgent, SLOT(slotPlayStreamSource(const QString &)));

    connect(ui->pushButtonPlay, &QPushButton::clicked,this, [this]() {
       qDebug("Send Stream Src: %s", qUtf8Printable(ui->lineEditStream->text()));
       ui->pushButtonPlay->text()=="Play" ? ui->pushButtonPlay->setText("Pause") : ui->pushButtonPlay->setText("Play");
       emit signalSendStreamSrc(ui->lineEditStream->text());
    });

    //set/unset bin filter
    connect(ui->checkBoxBinFilterOn,  &QCheckBox::toggled, this, [this](bool enabled){
        myCvAgent->slotSetBinThreshEn(enabled);
    });

    //on new frame
    connect(myCvAgent, SIGNAL(signalSendFrames(QImage &,QImage &)), this, SLOT(slotRcvNewFrames(QImage &, QImage &)));


    connect( myCvAgent, SIGNAL(signalWarnInvalidCaptureDevice(void)),this,SLOT(slotRcvInvalidCapDev(void)));

    connect(ui->comboBoxColorScheme, &QComboBox::currentIndexChanged, this, [this](int index){
        myCvAgent->setColorScheme(index);
        switch (index) {
        case OCA_COLORSCHEME_GRAY:
            setBinVisibility(true);
            setRgbVisibility(false);
            setHsvVisibility(false);
            break;
        case OCA_COLORSCHEME_RGB:
            setRgbVisibility(true);
            setBinVisibility(false);
            setHsvVisibility(false);
            break;
        case OCA_COLORSCHEME_HSV:
            setRgbVisibility(false);
            setBinVisibility(false);
            setHsvVisibility(true);
            break;
        default:
            break;
        }
    } );


    //SpinBoxes TODO could set pairs instead of one by one to avoid code duplication
    connect(ui->spinBoxHmin, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setHmin(int)));
    connect(ui->spinBoxHmax, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setHmax(int)));
    connect(ui->spinBoxSmin, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setSmin(int)));
    connect(ui->spinBoxSmax, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setSmax(int)));
    connect(ui->spinBoxVmin, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setVmin(int)));
    connect(ui->spinBoxVmax, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setVmax(int)));
    connect(ui->spinBoxRmin, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setRmin(int)));
    connect(ui->spinBoxRmax, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setRmax(int)));
    connect(ui->spinBoxGmin, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setGmin(int)));
    connect(ui->spinBoxGmax, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setGmax(int)));
    connect(ui->spinBoxBmin, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setBmin(int)));
    connect(ui->spinBoxBmax, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setBmax(int)));
    connect(ui->spinBoxBinThresh, SIGNAL(valueChanged(int)), myCvAgent, SLOT(setBinaryThresh(int)));

}


void QCvWidget::slotRcvNewFrames(QImage &inpFr, QImage &outFr){
    ui->labelViewOriginal->setPixmap(QPixmap::fromImage(inpFr).scaled(ui->labelViewOriginal->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->labelViewProcessed->setPixmap(QPixmap::fromImage(outFr));

}
void QCvWidget::setRgbVisibility(bool isVisible){
    ui->labelRed->setVisible(isVisible);
    ui->spinBoxRmin->setVisible(isVisible);
    ui->spinBoxRmax->setVisible(isVisible);
    ui->labelRmin->setVisible(isVisible);
    ui->labelRmax->setVisible(isVisible);
    ui->labelGreen->setVisible(isVisible);
    ui->labelGmin->setVisible(isVisible);
    ui->labelGmax->setVisible(isVisible);
    ui->spinBoxGmin->setVisible(isVisible);
    ui->spinBoxGmax->setVisible(isVisible);
    ui->labelBlue->setVisible(isVisible);
    ui->labelBmin->setVisible(isVisible);
    ui->labelBmax->setVisible(isVisible);
    ui->spinBoxBmin->setVisible(isVisible);
    ui->spinBoxBmax->setVisible(isVisible);

}

void QCvWidget::setHsvVisibility(bool isVisible){
    ui->labelHue->setVisible(isVisible);
    ui->labelHmin->setVisible(isVisible);
    ui->labelHmax->setVisible(isVisible);
    ui->spinBoxHmin->setVisible(isVisible);
    ui->spinBoxHmax->setVisible(isVisible);
    ui->labelSat->setVisible(isVisible);
    ui->labelSmin->setVisible(isVisible);
    ui->labelSmax->setVisible(isVisible);
    ui->spinBoxSmin->setVisible(isVisible);
    ui->spinBoxSmax->setVisible(isVisible);
    ui->labelValue->setVisible(isVisible);
    ui->labelVmin->setVisible(isVisible);
    ui->labelVmax->setVisible(isVisible);
    ui->spinBoxVmin->setVisible(isVisible);
    ui->spinBoxVmax->setVisible(isVisible);
}

void QCvWidget::setBinVisibility(bool isVisible){
    ui->labelBin->setVisible(isVisible);
    ui->spinBoxBinThresh->setVisible(isVisible);
    ui->checkBoxBinFilterOn->setVisible(isVisible);
}

void QCvWidget::slotRcvInvalidCapDev(void){
    char aux_warnMsg[200];
    sprintf(aux_warnMsg, "The Capture device specified \"%s\" is invalid.\nPlease input another one and retry", qUtf8Printable(ui->lineEditStream->text()));
    QMessageBox::warning(0, QString("Invalid Capture Device"), aux_warnMsg, QMessageBox::Ok);
    ui->pushButtonPlay->setText("Play");
    ui->lineEditStream->setText("");

}

