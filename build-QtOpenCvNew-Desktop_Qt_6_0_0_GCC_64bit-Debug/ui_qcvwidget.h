/********************************************************************************
** Form generated from reading UI file 'qcvwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCVWIDGET_H
#define UI_QCVWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCvWidget
{
public:
    QLabel *labelViewOriginal;
    QLabel *labelViewProcessed;
    QLabel *labelBin;
    QFrame *line;
    QLabel *label_4;
    QSpinBox *spinBoxBinThresh;
    QSpinBox *spinBoxHmin;
    QLabel *labelHue;
    QSpinBox *spinBoxHmax;
    QLabel *labelHmin;
    QLabel *labelHmax;
    QLabel *labelSmin;
    QLabel *labelSmax;
    QSpinBox *spinBoxSmin;
    QSpinBox *spinBoxSmax;
    QLabel *labelSat;
    QLabel *labelVmin;
    QLabel *labelVmax;
    QSpinBox *spinBoxVmin;
    QSpinBox *spinBoxVmax;
    QLabel *labelValue;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditStream;
    QPushButton *pushButtonPlay;
    QLabel *label_15;
    QComboBox *comboBoxColorScheme;
    QSpinBox *spinBoxBmin;
    QSpinBox *spinBoxRmin;
    QLabel *labelRmax;
    QLabel *labelGmin;
    QLabel *labelBlue;
    QLabel *labelBmax;
    QSpinBox *spinBoxBmax;
    QLabel *labelRed;
    QLabel *labelGmax;
    QSpinBox *spinBoxGmin;
    QLabel *labelGreen;
    QSpinBox *spinBoxRmax;
    QLabel *labelRmin;
    QSpinBox *spinBoxGmax;
    QLabel *labelBmin;
    QCheckBox *checkBoxBinFilterOn;

    void setupUi(QWidget *QCvWidget)
    {
        if (QCvWidget->objectName().isEmpty())
            QCvWidget->setObjectName(QString::fromUtf8("QCvWidget"));
        QCvWidget->resize(1213, 596);
        labelViewOriginal = new QLabel(QCvWidget);
        labelViewOriginal->setObjectName(QString::fromUtf8("labelViewOriginal"));
        labelViewOriginal->setGeometry(QRect(20, 10, 571, 401));
        labelViewOriginal->setStyleSheet(QString::fromUtf8("border: 1px solid;"));
        labelViewProcessed = new QLabel(QCvWidget);
        labelViewProcessed->setObjectName(QString::fromUtf8("labelViewProcessed"));
        labelViewProcessed->setGeometry(QRect(620, 10, 571, 401));
        labelViewProcessed->setStyleSheet(QString::fromUtf8("border: 1px solid;"));
        labelBin = new QLabel(QCvWidget);
        labelBin->setObjectName(QString::fromUtf8("labelBin"));
        labelBin->setGeometry(QRect(510, 430, 191, 81));
        labelBin->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelBin->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        line = new QFrame(QCvWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 570, 1241, 16));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMaximumSize(QSize(16777215, 16777215));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(QCvWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 580, 201, 16));
        spinBoxBinThresh = new QSpinBox(QCvWidget);
        spinBoxBinThresh->setObjectName(QString::fromUtf8("spinBoxBinThresh"));
        spinBoxBinThresh->setGeometry(QRect(550, 460, 121, 25));
        spinBoxBinThresh->setMaximum(255);
        spinBoxHmin = new QSpinBox(QCvWidget);
        spinBoxHmin->setObjectName(QString::fromUtf8("spinBoxHmin"));
        spinBoxHmin->setGeometry(QRect(320, 450, 121, 25));
        spinBoxHmin->setMaximum(255);
        labelHue = new QLabel(QCvWidget);
        labelHue->setObjectName(QString::fromUtf8("labelHue"));
        labelHue->setGeometry(QRect(280, 430, 191, 81));
        labelHue->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelHue->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        spinBoxHmax = new QSpinBox(QCvWidget);
        spinBoxHmax->setObjectName(QString::fromUtf8("spinBoxHmax"));
        spinBoxHmax->setGeometry(QRect(320, 480, 121, 25));
        spinBoxHmax->setMaximum(255);
        labelHmin = new QLabel(QCvWidget);
        labelHmin->setObjectName(QString::fromUtf8("labelHmin"));
        labelHmin->setGeometry(QRect(290, 460, 58, 16));
        labelHmax = new QLabel(QCvWidget);
        labelHmax->setObjectName(QString::fromUtf8("labelHmax"));
        labelHmax->setGeometry(QRect(290, 490, 31, 16));
        labelSmin = new QLabel(QCvWidget);
        labelSmin->setObjectName(QString::fromUtf8("labelSmin"));
        labelSmin->setGeometry(QRect(520, 460, 58, 16));
        labelSmax = new QLabel(QCvWidget);
        labelSmax->setObjectName(QString::fromUtf8("labelSmax"));
        labelSmax->setGeometry(QRect(520, 490, 31, 16));
        spinBoxSmin = new QSpinBox(QCvWidget);
        spinBoxSmin->setObjectName(QString::fromUtf8("spinBoxSmin"));
        spinBoxSmin->setGeometry(QRect(550, 450, 121, 25));
        spinBoxSmax = new QSpinBox(QCvWidget);
        spinBoxSmax->setObjectName(QString::fromUtf8("spinBoxSmax"));
        spinBoxSmax->setGeometry(QRect(550, 480, 121, 25));
        labelSat = new QLabel(QCvWidget);
        labelSat->setObjectName(QString::fromUtf8("labelSat"));
        labelSat->setGeometry(QRect(510, 430, 191, 81));
        labelSat->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelSat->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        labelVmin = new QLabel(QCvWidget);
        labelVmin->setObjectName(QString::fromUtf8("labelVmin"));
        labelVmin->setGeometry(QRect(740, 460, 58, 16));
        labelVmax = new QLabel(QCvWidget);
        labelVmax->setObjectName(QString::fromUtf8("labelVmax"));
        labelVmax->setGeometry(QRect(740, 490, 31, 16));
        spinBoxVmin = new QSpinBox(QCvWidget);
        spinBoxVmin->setObjectName(QString::fromUtf8("spinBoxVmin"));
        spinBoxVmin->setGeometry(QRect(770, 450, 121, 25));
        spinBoxVmax = new QSpinBox(QCvWidget);
        spinBoxVmax->setObjectName(QString::fromUtf8("spinBoxVmax"));
        spinBoxVmax->setGeometry(QRect(770, 480, 121, 25));
        labelValue = new QLabel(QCvWidget);
        labelValue->setObjectName(QString::fromUtf8("labelValue"));
        labelValue->setGeometry(QRect(730, 430, 191, 81));
        labelValue->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelValue->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        layoutWidget = new QWidget(QCvWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 530, 1141, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditStream = new QLineEdit(layoutWidget);
        lineEditStream->setObjectName(QString::fromUtf8("lineEditStream"));

        horizontalLayout->addWidget(lineEditStream);

        pushButtonPlay = new QPushButton(layoutWidget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));

        horizontalLayout->addWidget(pushButtonPlay);

        label_15 = new QLabel(QCvWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 430, 111, 16));
        comboBoxColorScheme = new QComboBox(QCvWidget);
        comboBoxColorScheme->addItem(QString());
        comboBoxColorScheme->addItem(QString());
        comboBoxColorScheme->addItem(QString());
        comboBoxColorScheme->setObjectName(QString::fromUtf8("comboBoxColorScheme"));
        comboBoxColorScheme->setGeometry(QRect(20, 450, 151, 24));
        comboBoxColorScheme->setMaxVisibleItems(2);
        spinBoxBmin = new QSpinBox(QCvWidget);
        spinBoxBmin->setObjectName(QString::fromUtf8("spinBoxBmin"));
        spinBoxBmin->setGeometry(QRect(770, 450, 121, 25));
        spinBoxRmin = new QSpinBox(QCvWidget);
        spinBoxRmin->setObjectName(QString::fromUtf8("spinBoxRmin"));
        spinBoxRmin->setGeometry(QRect(320, 450, 121, 25));
        spinBoxRmin->setMaximum(255);
        labelRmax = new QLabel(QCvWidget);
        labelRmax->setObjectName(QString::fromUtf8("labelRmax"));
        labelRmax->setGeometry(QRect(290, 490, 31, 16));
        labelGmin = new QLabel(QCvWidget);
        labelGmin->setObjectName(QString::fromUtf8("labelGmin"));
        labelGmin->setGeometry(QRect(520, 460, 58, 16));
        labelBlue = new QLabel(QCvWidget);
        labelBlue->setObjectName(QString::fromUtf8("labelBlue"));
        labelBlue->setGeometry(QRect(730, 430, 191, 81));
        labelBlue->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelBlue->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        labelBmax = new QLabel(QCvWidget);
        labelBmax->setObjectName(QString::fromUtf8("labelBmax"));
        labelBmax->setGeometry(QRect(740, 490, 31, 16));
        spinBoxBmax = new QSpinBox(QCvWidget);
        spinBoxBmax->setObjectName(QString::fromUtf8("spinBoxBmax"));
        spinBoxBmax->setGeometry(QRect(770, 480, 121, 25));
        labelRed = new QLabel(QCvWidget);
        labelRed->setObjectName(QString::fromUtf8("labelRed"));
        labelRed->setGeometry(QRect(280, 430, 191, 81));
        labelRed->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelRed->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        labelGmax = new QLabel(QCvWidget);
        labelGmax->setObjectName(QString::fromUtf8("labelGmax"));
        labelGmax->setGeometry(QRect(520, 490, 31, 16));
        spinBoxGmin = new QSpinBox(QCvWidget);
        spinBoxGmin->setObjectName(QString::fromUtf8("spinBoxGmin"));
        spinBoxGmin->setGeometry(QRect(550, 450, 121, 25));
        labelGreen = new QLabel(QCvWidget);
        labelGreen->setObjectName(QString::fromUtf8("labelGreen"));
        labelGreen->setGeometry(QRect(510, 430, 191, 81));
        labelGreen->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        labelGreen->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        spinBoxRmax = new QSpinBox(QCvWidget);
        spinBoxRmax->setObjectName(QString::fromUtf8("spinBoxRmax"));
        spinBoxRmax->setGeometry(QRect(320, 480, 121, 25));
        spinBoxRmax->setMaximum(255);
        spinBoxRmax->setValue(0);
        labelRmin = new QLabel(QCvWidget);
        labelRmin->setObjectName(QString::fromUtf8("labelRmin"));
        labelRmin->setGeometry(QRect(290, 460, 58, 16));
        spinBoxGmax = new QSpinBox(QCvWidget);
        spinBoxGmax->setObjectName(QString::fromUtf8("spinBoxGmax"));
        spinBoxGmax->setGeometry(QRect(550, 480, 121, 25));
        spinBoxGmax->setMaximum(255);
        spinBoxGmax->setValue(0);
        labelBmin = new QLabel(QCvWidget);
        labelBmin->setObjectName(QString::fromUtf8("labelBmin"));
        labelBmin->setGeometry(QRect(740, 460, 58, 16));
        checkBoxBinFilterOn = new QCheckBox(QCvWidget);
        checkBoxBinFilterOn->setObjectName(QString::fromUtf8("checkBoxBinFilterOn"));
        checkBoxBinFilterOn->setGeometry(QRect(550, 490, 83, 22));
        labelBin->raise();
        labelBlue->raise();
        labelGreen->raise();
        labelRed->raise();
        labelSat->raise();
        labelValue->raise();
        layoutWidget->raise();
        labelHue->raise();
        labelViewOriginal->raise();
        labelViewProcessed->raise();
        line->raise();
        label_4->raise();
        spinBoxHmin->raise();
        spinBoxHmax->raise();
        labelHmin->raise();
        labelHmax->raise();
        labelSmin->raise();
        labelSmax->raise();
        spinBoxSmin->raise();
        spinBoxSmax->raise();
        labelVmin->raise();
        labelVmax->raise();
        spinBoxVmin->raise();
        spinBoxVmax->raise();
        label_15->raise();
        comboBoxColorScheme->raise();
        spinBoxBmin->raise();
        spinBoxRmin->raise();
        labelRmax->raise();
        labelGmin->raise();
        labelBmax->raise();
        spinBoxBmax->raise();
        labelGmax->raise();
        spinBoxGmin->raise();
        spinBoxRmax->raise();
        labelRmin->raise();
        spinBoxGmax->raise();
        labelBmin->raise();
        checkBoxBinFilterOn->raise();
        spinBoxBinThresh->raise();

        retranslateUi(QCvWidget);

        comboBoxColorScheme->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QCvWidget);
    } // setupUi

    void retranslateUi(QWidget *QCvWidget)
    {
        QCvWidget->setWindowTitle(QCoreApplication::translate("QCvWidget", "QCvWidget", nullptr));
        labelViewOriginal->setText(QString());
        labelViewProcessed->setText(QString());
        labelBin->setText(QCoreApplication::translate("QCvWidget", "Binary Threshold", nullptr));
        label_4->setText(QCoreApplication::translate("QCvWidget", "Jo\303\243o Costa | Aveiro | 31 Jan 2021", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxBinThresh->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBoxHmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelHue->setText(QCoreApplication::translate("QCvWidget", "Hue Threshold", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxHmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelHmin->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        labelHmax->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
        labelSmin->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        labelSmax->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxSmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBoxSmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelSat->setText(QCoreApplication::translate("QCvWidget", "Saturation Threshold", nullptr));
        labelVmin->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        labelVmax->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxVmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBoxVmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelValue->setText(QCoreApplication::translate("QCvWidget", "Value Threshold", nullptr));
        lineEditStream->setPlaceholderText(QCoreApplication::translate("QCvWidget", "Enter here a stream source Examples: For webcam --> 0  |  For rtsp stream--> rtsp://192.168.1.123/stream?user=admin&psw=admin", nullptr));
        pushButtonPlay->setText(QCoreApplication::translate("QCvWidget", "Play", nullptr));
        label_15->setText(QCoreApplication::translate("QCvWidget", "Color Scheme", nullptr));
        comboBoxColorScheme->setItemText(0, QCoreApplication::translate("QCvWidget", "RGB", nullptr));
        comboBoxColorScheme->setItemText(1, QCoreApplication::translate("QCvWidget", "Grayscale", nullptr));
        comboBoxColorScheme->setItemText(2, QCoreApplication::translate("QCvWidget", "HSV", nullptr));

#if QT_CONFIG(accessibility)
        comboBoxColorScheme->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        comboBoxColorScheme->setCurrentText(QCoreApplication::translate("QCvWidget", "RGB", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxBmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBoxRmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelRmax->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
        labelGmin->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        labelBlue->setText(QCoreApplication::translate("QCvWidget", "Blue", nullptr));
        labelBmax->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxBmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelRed->setText(QCoreApplication::translate("QCvWidget", "Red", nullptr));
        labelGmax->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxGmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelGreen->setText(QCoreApplication::translate("QCvWidget", "Green", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelRmin->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxGmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        labelBmin->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        checkBoxBinFilterOn->setText(QCoreApplication::translate("QCvWidget", "Enable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QCvWidget: public Ui_QCvWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCVWIDGET_H
