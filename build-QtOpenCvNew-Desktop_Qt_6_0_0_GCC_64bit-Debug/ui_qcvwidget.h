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
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QSpinBox *spinBoxBinThresh;
    QSpinBox *spinBoxHmin;
    QLabel *label_5;
    QSpinBox *spinBoxHmax;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QLabel *label_13;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditStream;
    QPushButton *pushButtonPlay;
    QComboBox *comboBoxFilterType;
    QLabel *label_14;

    void setupUi(QWidget *QCvWidget)
    {
        if (QCvWidget->objectName().isEmpty())
            QCvWidget->setObjectName(QString::fromUtf8("QCvWidget"));
        QCvWidget->resize(1213, 717);
        labelViewOriginal = new QLabel(QCvWidget);
        labelViewOriginal->setObjectName(QString::fromUtf8("labelViewOriginal"));
        labelViewOriginal->setGeometry(QRect(20, 10, 571, 401));
        labelViewOriginal->setStyleSheet(QString::fromUtf8("border: 1px solid;"));
        labelViewProcessed = new QLabel(QCvWidget);
        labelViewProcessed->setObjectName(QString::fromUtf8("labelViewProcessed"));
        labelViewProcessed->setGeometry(QRect(620, 10, 571, 401));
        labelViewProcessed->setStyleSheet(QString::fromUtf8("border: 1px solid;"));
        label_3 = new QLabel(QCvWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 490, 191, 81));
        label_3->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        line = new QFrame(QCvWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 690, 1241, 16));
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
        label_4->setGeometry(QRect(510, 700, 201, 16));
        spinBoxBinThresh = new QSpinBox(QCvWidget);
        spinBoxBinThresh->setObjectName(QString::fromUtf8("spinBoxBinThresh"));
        spinBoxBinThresh->setGeometry(QRect(270, 520, 121, 25));
        spinBoxHmin = new QSpinBox(QCvWidget);
        spinBoxHmin->setObjectName(QString::fromUtf8("spinBoxHmin"));
        spinBoxHmin->setGeometry(QRect(500, 510, 121, 25));
        label_5 = new QLabel(QCvWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(460, 490, 191, 81));
        label_5->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        label_5->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        spinBoxHmax = new QSpinBox(QCvWidget);
        spinBoxHmax->setObjectName(QString::fromUtf8("spinBoxHmax"));
        spinBoxHmax->setGeometry(QRect(500, 540, 121, 25));
        label_6 = new QLabel(QCvWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 520, 58, 16));
        label_7 = new QLabel(QCvWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 550, 31, 16));
        label_8 = new QLabel(QCvWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(700, 520, 58, 16));
        label_9 = new QLabel(QCvWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(700, 550, 31, 16));
        spinBox_4 = new QSpinBox(QCvWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(730, 510, 121, 25));
        spinBox_5 = new QSpinBox(QCvWidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(730, 540, 121, 25));
        label_10 = new QLabel(QCvWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(690, 490, 191, 81));
        label_10->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        label_10->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_11 = new QLabel(QCvWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(920, 520, 58, 16));
        label_12 = new QLabel(QCvWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(920, 550, 31, 16));
        spinBox_6 = new QSpinBox(QCvWidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(950, 510, 121, 25));
        spinBox_7 = new QSpinBox(QCvWidget);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(950, 540, 121, 25));
        label_13 = new QLabel(QCvWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(910, 490, 191, 81));
        label_13->setStyleSheet(QString::fromUtf8("border: 1px solid"));
        label_13->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        layoutWidget = new QWidget(QCvWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 650, 1141, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditStream = new QLineEdit(layoutWidget);
        lineEditStream->setObjectName(QString::fromUtf8("lineEditStream"));

        horizontalLayout->addWidget(lineEditStream);

        pushButtonPlay = new QPushButton(layoutWidget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));

        horizontalLayout->addWidget(pushButtonPlay);

        comboBoxFilterType = new QComboBox(QCvWidget);
        comboBoxFilterType->addItem(QString());
        comboBoxFilterType->addItem(QString());
        comboBoxFilterType->addItem(QString());
        comboBoxFilterType->setObjectName(QString::fromUtf8("comboBoxFilterType"));
        comboBoxFilterType->setGeometry(QRect(40, 490, 151, 24));
        comboBoxFilterType->setMaxVisibleItems(2);
        label_14 = new QLabel(QCvWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 470, 101, 16));
        layoutWidget->raise();
        label_5->raise();
        label_3->raise();
        labelViewOriginal->raise();
        labelViewProcessed->raise();
        line->raise();
        label_4->raise();
        spinBoxBinThresh->raise();
        spinBoxHmin->raise();
        spinBoxHmax->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        spinBox_4->raise();
        spinBox_5->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        spinBox_6->raise();
        spinBox_7->raise();
        label_13->raise();
        comboBoxFilterType->raise();
        label_14->raise();

        retranslateUi(QCvWidget);

        comboBoxFilterType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QCvWidget);
    } // setupUi

    void retranslateUi(QWidget *QCvWidget)
    {
        QCvWidget->setWindowTitle(QCoreApplication::translate("QCvWidget", "QCvWidget", nullptr));
        labelViewOriginal->setText(QString());
        labelViewProcessed->setText(QString());
        label_3->setText(QCoreApplication::translate("QCvWidget", "Binary Threshold", nullptr));
        label_4->setText(QCoreApplication::translate("QCvWidget", "Jo\303\243o Costa | Aveiro | 31 Jan 2021", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxBinThresh->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBoxHmin->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("QCvWidget", "Hue Threshold", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxHmax->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        label_7->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
        label_8->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        label_9->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_4->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBox_5->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_10->setText(QCoreApplication::translate("QCvWidget", "Saturation Threshold", nullptr));
        label_11->setText(QCoreApplication::translate("QCvWidget", "min", nullptr));
        label_12->setText(QCoreApplication::translate("QCvWidget", "Max", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_6->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinBox_7->setToolTip(QCoreApplication::translate("QCvWidget", "Set here the threshold value [1,255] or 0 to disable filter", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("QCvWidget", "Value Threshold", nullptr));
        lineEditStream->setPlaceholderText(QCoreApplication::translate("QCvWidget", "Enter here a stream source Examples: For webcam --> 0  |  For rtsp stream--> rtsp://192.168.1.123/stream?user=admin&psw=admin", nullptr));
        pushButtonPlay->setText(QCoreApplication::translate("QCvWidget", "PushButton", nullptr));
        comboBoxFilterType->setItemText(0, QCoreApplication::translate("QCvWidget", "None", nullptr));
        comboBoxFilterType->setItemText(1, QCoreApplication::translate("QCvWidget", "Binary", nullptr));
        comboBoxFilterType->setItemText(2, QCoreApplication::translate("QCvWidget", "HSV", nullptr));

#if QT_CONFIG(accessibility)
        comboBoxFilterType->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        comboBoxFilterType->setCurrentText(QCoreApplication::translate("QCvWidget", "None", nullptr));
        label_14->setText(QCoreApplication::translate("QCvWidget", "Filter Type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QCvWidget: public Ui_QCvWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCVWIDGET_H
