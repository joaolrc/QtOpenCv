#include "OpenCvAgent.h"
#include <opencv2/imgproc.hpp>


OpenCvAgent::OpenCvAgent(QObject *parent) :
    QObject(parent),
    _cap(nullptr),
    _isStreamEnabled(false),
    _streamSrc(""),
    _filterType(OCA_FILTERTYPE_NONE),
    _myFilterValues({0,0,0,0,0,0,0})
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
    applyFilters();
    QImage inputFr((const unsigned char *) _frameOriginal.data, _frameOriginal.cols, _frameOriginal.rows, QImage::Format_Indexed8);
    QImage outputFr((const unsigned char *) _frameProcessed.data, _frameProcessed.cols, _frameProcessed.rows, QImage::Format_Indexed8);
    qDebug("Will Emit new Frame");
    emit signalSendFrames(inputFr, outputFr);
}



void OpenCvAgent::applyFilters(){
    switch (_filterType) {
        case OCA_FILTERTYPE_NONE:
            qDebug("No filter");
            _frameProcessed = _frameOriginal;
            return;
        case OCA_FILTERTYPE_BIN:
            cv::cvtColor( _frameOriginal, _frameProcessed, cv::COLOR_BGR2GRAY );
            cv::threshold( _frameProcessed, _frameProcessed, _myFilterValues.binThresh, 255, cv::THRESH_BINARY );
            return;
        case OCA_FILTERTYPE_HSV:
            return;
    }
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

void OpenCvAgent::setBinaryThresh(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, Q_FUNC_INFO, "Binary thresh must be within [0,255]");

    _myFilterValues.binThresh = thresh;

}


void OpenCvAgent::setHmin(int thresh){
    Q_ASSERT_X(thresh>=0 && thresh<=255, "setHmin", "H min Value must be within [0,255]");
    _myFilterValues.hmin = thresh;
}



/////////////////////////// Helpers ///////////////////////////
bool OpenCvAgent::_isValidUint8(int &val){
    return (val<=UINT8_MAX && val>=0);
}

void OpenCvAgent::setFilterType(int filterType){
    Q_ASSERT_X(filterType>=OCA_FILTERTYPE_NONE &&filterType<=OCA_FILTERTYPE_HSV, "setFilterType", "Invalid FIlter Type");
    qDebug("Setting filter to %d", filterType);
    _filterType =filterType;
    return;

}
