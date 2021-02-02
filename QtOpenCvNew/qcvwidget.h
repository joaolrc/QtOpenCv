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
    void _init();
    OpenCvAgent *myCvAgent;

private slots:
//    void slotButtonPlayPressed();
//    void slotRcvOriginalFrame(QImage frame);
    void slotRcvNewFrames(QImage &inpFr, QImage &outFr);
    void slotRcvInvalidCapDev(void);

signals:
    /**
     * @brief Signal to send the stream source, typed in lineEditStreamSrd. Also acts like a play Stream callback
     * @param stream const ref to stream
     */
    void signalSendStreamSrc(const QString &stream);

    //void rcvNewFrame(QImage frame);


};
#endif // QCVWIDGET_H
