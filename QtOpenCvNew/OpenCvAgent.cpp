#include "OpenCvAgent.h"
#include <opencv2/imgproc.hpp>


OpenCvAgent::OpenCvAgent(QObject *parent) :
    QObject(parent),
    _cap(nullptr),
    _isStreamEnabled(false),
    _isBinThreshEnabled(false),
    _streamSrc(""),
    _colorScheme(OCA_COLORSCHEME_RGB),
    _myFilterValues({0, 0, OCA_HSVRGB_MAX_DEFAULT_VAL, 0, OCA_HSVRGB_MAX_DEFAULT_VAL, 0,OCA_HSVRGB_MAX_DEFAULT_VAL, 0, OCA_HSVRGB_MAX_DEFAULT_VAL, 0, OCA_HSVRGB_MAX_DEFAULT_VAL, 0, OCA_HSVRGB_MAX_DEFAULT_VAL})
{}

OpenCvAgent::~OpenCvAgent(){
    freeProcessingResources();
}


void OpenCvAgent::slotPlayStreamSource(const QString &stream){
    if (_streamSrc.compare(stream)!=0){
        qDebug("RCV new StreamSrc: %s", qUtf8Printable(stream));
        _streamSrc = stream;
    }

    _isStreamEnabled = !_isStreamEnabled;
    if (_isStreamEnabled){
        qDebug("Will enable stream");
        bool aux_isStrInt;
        int aux_intStr = _streamSrc.toInt(&aux_isStrInt, 10);
        aux_isStrInt ? _cap = new cv::VideoCapture(aux_intStr) : _cap = new cv::VideoCapture(qUtf8Printable(_streamSrc));
        if (!_cap->isOpened()){
            qDebug("Invalid Stream Source");
            _isStreamEnabled = false;
            if (_cap) delete _cap;
            emit signalWarnInvalidCaptureDevice();
            return;
        }

        _imgProcThread = new QThread();
        QTimer *workerTrigger = new QTimer();
        workerTrigger->setInterval(OCA_WORKER_TRIGGER_TIME_MS);
        connect(workerTrigger, SIGNAL(timeout()), this, SLOT(slotProcessNewFrame()) );
        workerTrigger->start();
        workerTrigger->moveToThread(_imgProcThread);
        _imgProcThread->start();
        qDebug("Started worker");
        return;
    }


    //If code reaches here its to disable stream and cap
    freeProcessingResources();
}



void OpenCvAgent::slotProcessNewFrame(){
    if (!_cap || !_cap->isOpened())return;
    (*_cap)>>_frameOriginal;
    if (_frameOriginal.empty()){
        qDebug("Empty Frame");
        return;
    }
    uint8_t convertFmt = applyFilters();
    QImage inputFr((const unsigned char *) _frameOriginal.data, _frameOriginal.cols, _frameOriginal.rows, QImage::Format_RGB888);
    QImage outputFr((const unsigned char *) _frameProcessed.data, _frameProcessed.cols, _frameProcessed.rows, (QImage::Format) convertFmt);
    emit signalSendFrames(inputFr, outputFr);
}

void OpenCvAgent::slotSetBinThreshEn(bool isEnable){
    _isBinThreshEnabled = isEnable;
}

uint8_t OpenCvAgent::applyFilters(){
    Q_ASSERT(!_frameOriginal.empty());
    cv::cvtColor( _frameOriginal, _frameOriginal, cv::COLOR_BGR2RGB );
    switch (_colorScheme) {
    case OCA_COLORSCHEME_GRAY:
        cv::cvtColor( _frameOriginal, _frameProcessed, cv::COLOR_BGR2GRAY );
        if (_isBinThreshEnabled) cv::threshold( _frameProcessed, _frameProcessed, _myFilterValues.binThresh, 255, cv::THRESH_BINARY );
        return QImage::Format_Indexed8;
    case OCA_COLORSCHEME_RGB:
        cv::cvtColor( _frameOriginal, _frameProcessed, cv::COLOR_BGR2RGB );
        cv::inRange(_frameProcessed, cv::Scalar(_myFilterValues.rmin, _myFilterValues.gmin, _myFilterValues.bmin), cv::Scalar(_myFilterValues.rmax, _myFilterValues.gmax, _myFilterValues.bmax), _frameProcessed);
        return QImage::Format_Indexed8;
    case OCA_COLORSCHEME_HSV:
        cv::cvtColor( _frameOriginal, _frameProcessed, cv::COLOR_BGR2HSV );
        cv::inRange(_frameProcessed, cv::Scalar(_myFilterValues.hmin, _myFilterValues.smin, _myFilterValues.vmin), cv::Scalar(_myFilterValues.hmax, _myFilterValues.smax, _myFilterValues.vmax), _frameProcessed);
        return QImage::Format_Indexed8;
    default:
        break;
    }
    return QImage::Format_Indexed8;

}


void OpenCvAgent::freeProcessingResources(){
    if (_imgProcThread){
        if (_imgProcThread->isRunning()) _imgProcThread->quit();
        while (!_imgProcThread->isFinished());
        delete _imgProcThread;
    }
    if (_cap){
        if (_cap->isOpened()) _cap->release();
        delete _cap;
    }

    qDebug("Gracefully Freed all resources");
}



/////////////////////////// Helpers ///////////////////////////
bool OpenCvAgent::_isValidUint8(int &val){
    return (val<=UINT8_MAX && val>=0);
}



void OpenCvAgent::setColorScheme(int colorScheme){
    Q_ASSERT_X(colorScheme>=OCA_COLORSCHEME_RGB && colorScheme<=OCA_COLORSCHEME_HSV, Q_FUNC_INFO, "Invalid Color Scheme");
    qDebug("Setting Color Scheme to %d", colorScheme);
    _colorScheme = colorScheme;
    return;

}

void OpenCvAgent::setBinaryThresh(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, Q_FUNC_INFO, "Binary thresh must be within [0,255]");
    _myFilterValues.binThresh = thresh;

}


void OpenCvAgent::setHmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.hmin = thresh;
}

void OpenCvAgent::setHmax(int thresh){
    Q_ASSERT(thresh>=0 && thresh<=255),
    _myFilterValues.hmax = thresh;
}

void OpenCvAgent::setSmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.smin = thresh;
}

void OpenCvAgent::setSmax(int thresh){
    Q_ASSERT(thresh>=0 && thresh<=255),
    _myFilterValues.smax = thresh;
}

void OpenCvAgent::setVmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.vmin = thresh;
}

void OpenCvAgent::setVmax(int thresh){
    Q_ASSERT(thresh>=0 && thresh<=255),
    _myFilterValues.vmax = thresh;
}




void OpenCvAgent::setRmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.rmin = thresh;
}

void OpenCvAgent::setRmax(int thresh){
    Q_ASSERT(thresh>=0 && thresh<=255),
    _myFilterValues.rmax = thresh;
}

void OpenCvAgent::setGmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.gmin = thresh;
}

void OpenCvAgent::setGmax(int thresh){
    Q_ASSERT(thresh>=0 && thresh<=255),
    _myFilterValues.gmax = thresh;
}

void OpenCvAgent::setBmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.bmin = thresh;
}

void OpenCvAgent::setBmax(int thresh){
    Q_ASSERT(thresh>=0 && thresh<=255),
    _myFilterValues.bmax = thresh;
}
