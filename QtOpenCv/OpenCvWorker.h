/**
  *\file OpenCvWorker.h
  *\brief Genereal Module to capture stream and do some proccessment, fone in a Qt style with signals and slots insteadof plain old callbacks
  *\author João Costa
  *\date 31 Jan 2021
  */

#ifndef OPENCVWORKER_H
#define OPENCVWORKER_H

#include <QObject>
#include <QImage>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/core.hpp>

#define MAX_STREAM_SRC_LEN 200

class OpenCvWorker : public QObject
{
    Q_OBJECT


public:
    explicit OpenCvWorker(QObject *parent = nullptr);
    ~OpenCvWorker();

private:
    cv::Mat _frameOriginal;                 ///< Original frame grabbed from cap dev without processing
    cv::Mat _frameProcessed;                ///< _frameOriginal after process()
    cv::VideoCapture *_cap = nullptr;                 ///< capture handler

    bool _status;
    bool _isStreamEnabled;
    bool _isBinThreshEnabled;               ///< if false-> processBin is not called
    int _binThresh;                         ///< the value of threshold input in UI
    QString _streamSrc;
    //char _streamSrc[MAX_STREAM_SRC_LEN];    ///< stream source to capture

    void processFrame();



signals:
    void sendFrame(QImage frameProcessed);
    void sendWarnInvalidCaptureDevice(const QString &device);
    //void sendStatus(QString msg, int code);



public slots:
    void rcvGrabFrame();
    void rcvSetup(const int device);

    /**
     * @brief Enable Binary filter
     */
    void rcvEnableBinaryThreshold();

    /**
     * @brief Set Binary threshold to be applied to _frameOriginal if _isBinThreshEnabled
     * @param Threshold 0-255 int value to binarize frames
     */
    void rcvBinaryThreshold(int Threshold);

    /**
     * @brief Set Stream source and Play. Only allowed when not streaming
     * @param stream
     */
    void rcvPlayStreamSrc(const QString &stream);





};

#endif // OPENCVWORKER_H
