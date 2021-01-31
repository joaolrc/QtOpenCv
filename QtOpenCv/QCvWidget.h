#ifndef QCVWIDGET_H
#define QCVWIDGET_H

#include <QWidget>
#include <QThread>

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
    Ui::QCvWidget *_ui;
    QThread *_thread; ///< thread for running frame processing function

    /**
     * @brief Initialize main window
     */
    void _init();
    void _toggleVisualBottomBar();

signals:
    void sendSetup(int device);

    /**
     * @brief Signal to send the stream source, typed in lineEditStreamSrd. Also acts like a play Stream callback
     * @param stream const ref to stream
     */
    void sendStreamSrc(const QString &stream);

private slots:
    void rcvFrame(QImage frame);
    void rcvToggleStream();
    void rcvInvalidCapDev(const QString &device);
};
#endif // QCVWIDGET_H
