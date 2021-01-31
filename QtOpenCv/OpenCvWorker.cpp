#include "OpenCvWorker.h"
#include <opencv2/imgproc.hpp>

OpenCvWorker::OpenCvWorker(QObject *parent) :
    QObject(parent),
    _status(false),
    _isStreamEnabled(false),
    _isBinThreshEnabled(false),
    _binThresh(127),
    _streamSrc("")


{
   // _cap = nullptr;//new cv::VideoCapture(0);
}


OpenCvWorker::~OpenCvWorker(){
    //release heap mem if capture is open
    if (_cap->isOpened()) _cap->release();
    delete _cap;
}


void OpenCvWorker::rcvGrabFrame(){
    if (!_isStreamEnabled) return; //if grab next frame

    (*_cap)>>_frameOriginal;
    if(_frameOriginal.empty()) return; //chek if empty frame. Could throw some error in this case

    processFrame();

    QImage output((const unsigned char *) _frameProcessed.data, _frameProcessed.cols, _frameProcessed.rows, QImage::Format_Indexed8); //lastParameter = grayscale
    //output.scaled()
    emit sendFrame(output);
}



void OpenCvWorker::processFrame(){
    cv::cvtColor( _frameOriginal, _frameProcessed, cv::COLOR_BGR2GRAY );

    if(_isBinThreshEnabled){
        cv::threshold( _frameProcessed, _frameProcessed, _binThresh, 255, cv::THRESH_BINARY );
    }

}


void OpenCvWorker::rcvSetup(const int device){
    if (_cap->isOpened()) _cap->release();
    _cap->open(device);
    if (!_cap->isOpened()){
        _status = false;
        return;
    }
    _status = true;
}



void OpenCvWorker::rcvEnableBinaryThreshold(){
    _isBinThreshEnabled = !_isBinThreshEnabled;
    _isBinThreshEnabled ? qDebug("Binary Thresh ON") : qDebug("Binary Thresh OFF");

}


void OpenCvWorker::rcvBinaryThreshold(int threshold){
    _binThresh = threshold;
}


void OpenCvWorker::rcvPlayStreamSrc(const QString &stream){

    //if (_streamSrc.compare(stream)) return;

    qDebug("RCV new StreamSrc: %s", qUtf8Printable(stream));
    _streamSrc = stream;
    bool aux_isStrInt;
    int aux_intStr = _streamSrc.toInt(&aux_isStrInt, 10);
    if (_cap) delete _cap;
    if (aux_isStrInt) _cap = new cv::VideoCapture(aux_intStr);
    else _cap = new cv::VideoCapture(qUtf8Printable(_streamSrc));

    if (!_cap->isOpened()){
        qWarning("Invalid capture device");
        emit sendWarnInvalidCaptureDevice(_streamSrc);
        return;
    }
    _isStreamEnabled = !_isStreamEnabled;
    _isStreamEnabled ? qDebug("Stream Enabled") : qDebug("Stream Disabled");
}



