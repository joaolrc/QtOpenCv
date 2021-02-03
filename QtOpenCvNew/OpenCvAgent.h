#ifndef OPENCVAGENT_H
#define OPENCVAGENT_H

#include <QObject>
#include <QImage>
#include <QThread>
#include <QTimer>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/core.hpp>

#define OCA_FILTERTYPE_NONE 0
#define OCA_FILTERTYPE_BIN 1
#define OCA_FILTERTYPE_HSV 2

#define OCA_WORKER_TRIGGER_TIME_MS 100

#define OCA_COLORSCHEME_RGB 0   ///< Default
#define OCA_COLORSCHEME_GRAY 1
#define OCA_COLORSCHEME_HSV 2

#define OCA_HSVRGB_MAX_DEFAULT_VAL 130

struct imageFilterValues_t {
  uint8_t binThresh;
  uint8_t hmin;
  uint8_t hmax;
  uint8_t smin;
  uint8_t smax;
  uint8_t vmin;
  uint8_t vmax;
  uint8_t rmin;
  uint8_t rmax;
  uint8_t gmin;
  uint8_t gmax;
  uint8_t bmin;
  uint8_t bmax;
};

class OpenCvAgent : public QObject
{
    Q_OBJECT
public:
    explicit OpenCvAgent(QObject *parent = nullptr);
    ~OpenCvAgent();


    void processStream();
    void setColorScheme(int colorScheme);

private:
    cv::Mat _frameOriginal;                 ///< Original frame grabbed from cap dev without processing
    cv::Mat _frameProcessed;                ///< _frameOriginal after applyFilters()
    cv::VideoCapture *_cap;                 ///< capture handler

    bool _isStreamEnabled;
    bool _isBinThreshEnabled;               ///< if false-> processBin is not called
    QString _streamSrc;                     ///< input for VideoCapture
    uint8_t _colorScheme;                   ///< color scheme to convert _frameOriginal to
    imageFilterValues_t _myFilterValues;    ///< filter values to be applied to _frameOriginal
    QThread *_imgProcThread;                ///< thread which will have the img processing func


    /**
     * @brief Applies myFilterValues to _frameOriginal and saves it into _frameProcessed
     * returns QImage::format to be applied in conversion for QImage of _frameProcessed
     */
    uint8_t applyFilters();


    /**
     * @brief Free mem occupied by video capture and image processment and also release cap dev
     */
    void freeProcessingResources();


    /**
     * @brief checks wether an int var can be casted to uint8_t without being truncated
     * @param val in variable to be casted
     * @return true if can be converted. False otherwise
     */
    bool _isValidUint8(int &val);



signals:
    /**
     * @brief send Signal to UI if invalid capture device was selected
     * @param device device that triggered error condition
     */
    void signalWarnInvalidCaptureDevice();

    /**
     * @brief send both original and processed frames as QImages to whatever module is observing
     * @param frameOriginal original frame without filters
     * @param frameProcessed frameOriginal after filters applied
     */
    void signalSendFrames(QImage &frameOriginal, QImage &frameProcessed);


private slots:
    void slotProcessNewFrame();



public slots:
    /**
     * @brief Enable/Disable Binary threshold
     */
    void slotSetBinThreshEn(bool isEnable);

    /**
     * @brief Set Stream source and Play. Only allowed when not streaming
     */
    void slotPlayStreamSource(const QString &stream);


    /**
     *  \defgroup HsvRangeSetters Functions to set HSV filter ranges
     *  @{
     */
    void setHmin(int thresh);
    void setHmax(int thresh);
    void setSmin(int thresh);
    void setSmax(int thresh);
    void setVmin(int thresh);
    void setVmax(int thresh);
    /**@}*/

    /**
     *  \defgroup RgbRangeSetters Functions to set RGB filter ranges
     *  @{
     */
    void setRmin(int thresh);
    void setRmax(int thresh);
    void setGmin(int thresh);
    void setGmax(int thresh);
    void setBmin(int thresh);
    void setBmax(int thresh);
    /**@}*/



    /**
     * @brief sends signal to main thread when stream input dev is invalid
     */
   // void signalWarnInvalidCaptureDevice(void);

    /**
     * @brief Sets Binary threshold to be applied to Binary filter
     * @param thresh 0 to 255
     * @return true if valid threshold. False otherwise
     */
    void setBinaryThresh(int thresh);


};

#endif // OPENCVAGENT_H
