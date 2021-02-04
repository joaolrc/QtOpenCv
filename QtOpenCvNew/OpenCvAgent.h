#ifndef OPENCVAGENT_H
#define OPENCVAGENT_H

#include <QObject>
#include <QImage>
#include <QThread>
#include <QTimer>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/core.hpp>

//Max values for HSV thresh
#define OCA_MAXVAL_HUE 179              ///< should be 360 but openCv thinks different
#define OCA_MAXVAL_SAT 255              ///< should be 100 but..
#define OCA_MAXVAL_VAL 255              ///< should be 100 but..

//Max values for RGB thresh
#define OCA_MAXVAL_RED 255
#define OCA_MAXVAL_GREEN 255
#define OCA_MAXVAL_BLUE 255

// Color schemes/spaces. Could use enum for this
#define OCA_COLORSCHEME_RGB 0
#define OCA_COLORSCHEME_GRAY 1
#define OCA_COLORSCHEME_HSV 2

#define OCA_HSVRGB_MAX_DEFAULT_VAL 130  ///< which max value to start with

#define OCA_WORKER_TRIGGER_TIME_MS 100  ///< Timer to call slotProcessNewFrame() when stream enabled

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


    /**
     * @brief set Color Scheme which will be applied in 1st conversion from _frameOriginal into _frameProcessed
     * @param colorScheme check defines above OCA_COLORSCHEME_...
     */
    void setColorScheme(int colorScheme);

private:
    cv::Mat _frameOriginal;                 ///< Original frame grabbed from cap dev without processing
    cv::Mat _frameProcessed;                ///< _frameOriginal after applyFilters()
    cv::VideoCapture *_cap;                 ///< capture handler

    bool _isStreamEnabled;                  ///< enable/disable stream processment
    bool _isBinThreshEnabled;               ///< if false-> processBin is not called
    QString _streamSrc;                     ///< input for VideoCapture
    uint8_t _colorScheme;                   ///< color scheme to convert _frameOriginal to
    imageFilterValues_t _myFilterValues;    ///< filter values to be applied to _frameOriginal
    QThread *_imgProcThread;                ///< thread which will have the img processing func


    /**
     * @brief Applies myFilterValues to _frameOriginal and saves it into _frameProcessed
     * returns QImage::format to be applied in conversion for QImage of _frameProcessed
     */
    QImage::Format applyFilters();


    /**
     * @brief Free mem occupied by video capture and image processment and also release cap dev
     */
    void freeProcessingResources();


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
    /**
     * @brief Grab a new frame from capture device, process it and emit signal with it
     * Should be called by timer or within while loop
     */
    void slotProcessNewFrame();



public slots:
    /**
     * @brief Enable/Disable Binary threshold
     */
    void slotSetBinThreshEn(bool isEnable);

    /**
     * @brief Set Stream source and Play. If streaming, it will pause it
     * @param stream argument passed to cv::VideoCapture(stream)
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
