#ifndef QCVWIDGET_H
#define QCVWIDGET_H

#include <QWidget>
#include <OpenCvAgent.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QCvWidget; }
QT_END_NAMESPACE

class QCvWidget : public QWidget
{
    Q_OBJECT

public:
    QCvWidget(QWidget *parent = nullptr);
    ~QCvWidget();

private:
    Ui::QCvWidget *ui;
    OpenCvAgent *myCvAgent;

    /**
     * @brief intialize ui components
     */
    void _init();

    /**
     *  \defgroup FiltersVisibilitySetters Set visibility of Filter setters
     *  @{
     */
    void setRgbVisibility(bool isVisible);
    void setHsvVisibility(bool isVisible);
    void setBinVisibility(bool isVisible);
    /**@}*/

private slots:

    /**
     * @brief Receive new frames from OpenCv worker and display in UI
     * @param inpFr Frame without processement
     * @param outFr inpFr processed
     */
    void slotRcvNewFrames(QImage &inpFr, QImage &outFr);

    /**
     * @brief If invalid capture device specified, this will receive a signal to display warning
     */
    void slotRcvInvalidCapDev(void);

signals:
    /**
     * @brief Signal to send the stream source, typed in lineEditStreamSrd. Also acts like a play Stream callback
     * @param stream const ref to stream
     */
    void signalSendStreamSrc(const QString &stream);




};
#endif // QCVWIDGET_H
