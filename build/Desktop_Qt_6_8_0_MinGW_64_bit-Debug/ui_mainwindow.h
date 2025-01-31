/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *SYMULACJA;
    QPushButton *btnStart;
    QPushButton *btnReset;
    QLabel *label_4;
    QLabel *labelStatus;
    QPushButton *btnStop;
    QToolBox *toolBox;
    QWidget *pageSygnaly;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxSkok;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *spinBoxSkokAkt;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxSkokAmp;
    QGroupBox *groupBoxKwad;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QSpinBox *spinBoxKwadAkt;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBoxKwadWyp;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBoxKwadAmp;
    QGroupBox *groupBoxSin;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QSpinBox *spinBoxSinOkr;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBoxSinAmp;
    QWidget *pagePID;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxP;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxI;
    QPushButton *btnResetI;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxD;
    QPushButton *btnResetD;
    QWidget *pageARX;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_15;
    QDoubleSpinBox *doubleSpinBoxARX_A;
    QPushButton *btnARXAdd_A;
    QPushButton *btnARXClear_A;
    QLineEdit *lineEditARXView_A;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_18;
    QDoubleSpinBox *doubleSpinBoxARX_B;
    QPushButton *btnARXAdd_B;
    QPushButton *btnARXClear_B;
    QLineEdit *lineEditARXView_B;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QSpinBox *spinBoxARX_k;
    QCheckBox *checkBoxARZ_z;
    QWidget *pageSymulacja;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QSpinBox *spinBoxInterwal;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QSpinBox *spinBoxWidokKrokow;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_21;
    QCustomPlot *graphUAR;
    QHBoxLayout *horizontalLayout_20;
    QCustomPlot *graphUchyb;
    QCustomPlot *graphPidSum;
    QCustomPlot *graphPID;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(966, 682);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 680));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        SYMULACJA = new QGroupBox(centralwidget);
        SYMULACJA->setObjectName("SYMULACJA");
        sizePolicy.setHeightForWidth(SYMULACJA->sizePolicy().hasHeightForWidth());
        SYMULACJA->setSizePolicy(sizePolicy);
        SYMULACJA->setMinimumSize(QSize(255, 196));
        SYMULACJA->setMaximumSize(QSize(16777215, 196));
        btnStart = new QPushButton(SYMULACJA);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(80, 30, 91, 24));
        btnReset = new QPushButton(SYMULACJA);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(80, 90, 91, 24));
        label_4 = new QLabel(SYMULACJA);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 130, 131, 20));
        label_4->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelStatus = new QLabel(SYMULACJA);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(60, 150, 131, 20));
        labelStatus->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        labelStatus->setTextFormat(Qt::TextFormat::PlainText);
        labelStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnStop = new QPushButton(SYMULACJA);
        btnStop->setObjectName("btnStop");
        btnStop->setGeometry(QRect(80, 60, 91, 24));

        verticalLayout->addWidget(SYMULACJA);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy1);
        toolBox->setMinimumSize(QSize(255, 0));
        pageSygnaly = new QWidget();
        pageSygnaly->setObjectName("pageSygnaly");
        pageSygnaly->setGeometry(QRect(0, 0, 255, 290));
        horizontalLayoutWidget = new QWidget(pageSygnaly);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(5, -1, 241, 291));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 5, -1, -1);
        groupBoxSkok = new QGroupBox(horizontalLayoutWidget);
        groupBoxSkok->setObjectName("groupBoxSkok");
        groupBoxSkok->setFlat(false);
        groupBoxSkok->setCheckable(true);
        groupBoxSkok->setChecked(true);
        verticalLayoutWidget = new QWidget(groupBoxSkok);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 20, 231, 62));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(5, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        spinBoxSkokAkt = new QSpinBox(verticalLayoutWidget);
        spinBoxSkokAkt->setObjectName("spinBoxSkokAkt");
        spinBoxSkokAkt->setMinimum(0);
        spinBoxSkokAkt->setMaximum(100);
        spinBoxSkokAkt->setValue(0);

        horizontalLayout_5->addWidget(spinBoxSkokAkt);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        doubleSpinBoxSkokAmp = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBoxSkokAmp->setObjectName("doubleSpinBoxSkokAmp");
        doubleSpinBoxSkokAmp->setDecimals(2);
        doubleSpinBoxSkokAmp->setMinimum(0.000000000000000);
        doubleSpinBoxSkokAmp->setMaximum(100000.000000000000000);
        doubleSpinBoxSkokAmp->setSingleStep(0.100000000000000);
        doubleSpinBoxSkokAmp->setValue(0.000000000000000);

        horizontalLayout_6->addWidget(doubleSpinBoxSkokAmp);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBoxSkok);

        groupBoxKwad = new QGroupBox(horizontalLayoutWidget);
        groupBoxKwad->setObjectName("groupBoxKwad");
        groupBoxKwad->setFlat(false);
        groupBoxKwad->setCheckable(true);
        groupBoxKwad->setChecked(false);
        verticalLayoutWidget_3 = new QWidget(groupBoxKwad);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 20, 231, 87));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(5, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_19 = new QLabel(verticalLayoutWidget_3);
        label_19->setObjectName("label_19");

        horizontalLayout_17->addWidget(label_19);

        spinBoxKwadAkt = new QSpinBox(verticalLayoutWidget_3);
        spinBoxKwadAkt->setObjectName("spinBoxKwadAkt");
        spinBoxKwadAkt->setMaximum(1000);

        horizontalLayout_17->addWidget(spinBoxKwadAkt);


        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBoxKwadWyp = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBoxKwadWyp->setObjectName("doubleSpinBoxKwadWyp");
        doubleSpinBoxKwadWyp->setMinimum(0.000000000000000);
        doubleSpinBoxKwadWyp->setMaximum(1.000000000000000);
        doubleSpinBoxKwadWyp->setSingleStep(0.100000000000000);

        horizontalLayout_7->addWidget(doubleSpinBoxKwadWyp);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName("label_9");

        horizontalLayout_8->addWidget(label_9);

        doubleSpinBoxKwadAmp = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBoxKwadAmp->setObjectName("doubleSpinBoxKwadAmp");
        doubleSpinBoxKwadAmp->setMinimum(0.000000000000000);
        doubleSpinBoxKwadAmp->setMaximum(100000.000000000000000);
        doubleSpinBoxKwadAmp->setSingleStep(0.100000000000000);

        horizontalLayout_8->addWidget(doubleSpinBoxKwadAmp);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_2->addWidget(groupBoxKwad);

        groupBoxSin = new QGroupBox(horizontalLayoutWidget);
        groupBoxSin->setObjectName("groupBoxSin");
        groupBoxSin->setCheckable(true);
        groupBoxSin->setChecked(false);
        verticalLayoutWidget_4 = new QWidget(groupBoxSin);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(0, 20, 231, 58));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(5, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_11 = new QLabel(verticalLayoutWidget_4);
        label_11->setObjectName("label_11");

        horizontalLayout_10->addWidget(label_11);

        spinBoxSinOkr = new QSpinBox(verticalLayoutWidget_4);
        spinBoxSinOkr->setObjectName("spinBoxSinOkr");
        spinBoxSinOkr->setMaximum(1000);

        horizontalLayout_10->addWidget(spinBoxSinOkr);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName("label_10");

        horizontalLayout_9->addWidget(label_10);

        doubleSpinBoxSinAmp = new QDoubleSpinBox(verticalLayoutWidget_4);
        doubleSpinBoxSinAmp->setObjectName("doubleSpinBoxSinAmp");
        doubleSpinBoxSinAmp->setMaximum(100000.000000000000000);
        doubleSpinBoxSinAmp->setSingleStep(0.100000000000000);

        horizontalLayout_9->addWidget(doubleSpinBoxSinAmp);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_2->addWidget(groupBoxSin);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 4);
        verticalLayout_2->setStretch(2, 3);

        horizontalLayout_11->addLayout(verticalLayout_2);

        toolBox->addItem(pageSygnaly, QString::fromUtf8("Sygna\305\202 wej\305\233ciowy"));
        pagePID = new QWidget();
        pagePID->setObjectName("pagePID");
        pagePID->setGeometry(QRect(0, 0, 255, 290));
        sizePolicy.setHeightForWidth(pagePID->sizePolicy().hasHeightForWidth());
        pagePID->setSizePolicy(sizePolicy);
        pagePID->setMinimumSize(QSize(0, 207));
        groupBox = new QGroupBox(pagePID);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 231, 211));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        doubleSpinBoxP = new QDoubleSpinBox(groupBox);
        doubleSpinBoxP->setObjectName("doubleSpinBoxP");
        doubleSpinBoxP->setMaximum(100.000000000000000);
        doubleSpinBoxP->setSingleStep(0.100000000000000);
        doubleSpinBoxP->setValue(0.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBoxP);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBoxI = new QDoubleSpinBox(groupBox);
        doubleSpinBoxI->setObjectName("doubleSpinBoxI");
        doubleSpinBoxI->setMaximum(100.000000000000000);
        doubleSpinBoxI->setSingleStep(0.100000000000000);
        doubleSpinBoxI->setValue(0.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBoxI);


        verticalLayout_3->addLayout(horizontalLayout_3);

        btnResetI = new QPushButton(groupBox);
        btnResetI->setObjectName("btnResetI");

        verticalLayout_3->addWidget(btnResetI);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setFrameShadow(QFrame::Shadow::Raised);
        label_3->setWordWrap(true);

        horizontalLayout_4->addWidget(label_3);

        doubleSpinBoxD = new QDoubleSpinBox(groupBox);
        doubleSpinBoxD->setObjectName("doubleSpinBoxD");
        doubleSpinBoxD->setMaximum(100.000000000000000);
        doubleSpinBoxD->setSingleStep(0.100000000000000);
        doubleSpinBoxD->setValue(0.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBoxD);


        verticalLayout_3->addLayout(horizontalLayout_4);

        btnResetD = new QPushButton(groupBox);
        btnResetD->setObjectName("btnResetD");

        verticalLayout_3->addWidget(btnResetD);

        toolBox->addItem(pagePID, QString::fromUtf8("Regulator PID"));
        pageARX = new QWidget();
        pageARX->setObjectName("pageARX");
        pageARX->setGeometry(QRect(0, 0, 255, 290));
        verticalLayoutWidget_2 = new QWidget(pageARX);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 251, 291));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(verticalLayoutWidget_2);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        verticalLayoutWidget_6 = new QWidget(groupBox_3);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(0, 20, 249, 91));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_10->setSpacing(5);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        doubleSpinBoxARX_A = new QDoubleSpinBox(verticalLayoutWidget_6);
        doubleSpinBoxARX_A->setObjectName("doubleSpinBoxARX_A");
        doubleSpinBoxARX_A->setMinimum(-100.000000000000000);
        doubleSpinBoxARX_A->setMaximum(100.000000000000000);
        doubleSpinBoxARX_A->setSingleStep(0.100000000000000);

        horizontalLayout_15->addWidget(doubleSpinBoxARX_A);

        btnARXAdd_A = new QPushButton(verticalLayoutWidget_6);
        btnARXAdd_A->setObjectName("btnARXAdd_A");

        horizontalLayout_15->addWidget(btnARXAdd_A);

        btnARXClear_A = new QPushButton(verticalLayoutWidget_6);
        btnARXClear_A->setObjectName("btnARXClear_A");

        horizontalLayout_15->addWidget(btnARXClear_A);


        verticalLayout_10->addLayout(horizontalLayout_15);

        lineEditARXView_A = new QLineEdit(verticalLayoutWidget_6);
        lineEditARXView_A->setObjectName("lineEditARXView_A");
        lineEditARXView_A->setEnabled(true);
        lineEditARXView_A->setReadOnly(false);

        verticalLayout_10->addWidget(lineEditARXView_A);


        verticalLayout_7->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(verticalLayoutWidget_2);
        groupBox_4->setObjectName("groupBox_4");
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        verticalLayoutWidget_7 = new QWidget(groupBox_4);
        verticalLayoutWidget_7->setObjectName("verticalLayoutWidget_7");
        verticalLayoutWidget_7->setGeometry(QRect(0, 20, 249, 91));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_11->setSpacing(5);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        doubleSpinBoxARX_B = new QDoubleSpinBox(verticalLayoutWidget_7);
        doubleSpinBoxARX_B->setObjectName("doubleSpinBoxARX_B");
        doubleSpinBoxARX_B->setMinimum(-100.000000000000000);
        doubleSpinBoxARX_B->setMaximum(100.000000000000000);
        doubleSpinBoxARX_B->setSingleStep(0.100000000000000);

        horizontalLayout_18->addWidget(doubleSpinBoxARX_B);

        btnARXAdd_B = new QPushButton(verticalLayoutWidget_7);
        btnARXAdd_B->setObjectName("btnARXAdd_B");

        horizontalLayout_18->addWidget(btnARXAdd_B);

        btnARXClear_B = new QPushButton(verticalLayoutWidget_7);
        btnARXClear_B->setObjectName("btnARXClear_B");

        horizontalLayout_18->addWidget(btnARXClear_B);


        verticalLayout_11->addLayout(horizontalLayout_18);

        lineEditARXView_B = new QLineEdit(verticalLayoutWidget_7);
        lineEditARXView_B->setObjectName("lineEditARXView_B");
        lineEditARXView_B->setReadOnly(true);

        verticalLayout_11->addWidget(lineEditARXView_B);


        verticalLayout_7->addWidget(groupBox_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_16 = new QLabel(verticalLayoutWidget_2);
        label_16->setObjectName("label_16");

        horizontalLayout_14->addWidget(label_16);

        spinBoxARX_k = new QSpinBox(verticalLayoutWidget_2);
        spinBoxARX_k->setObjectName("spinBoxARX_k");
        spinBoxARX_k->setMinimum(1);
        spinBoxARX_k->setMaximum(100);

        horizontalLayout_14->addWidget(spinBoxARX_k);


        verticalLayout_7->addLayout(horizontalLayout_14);

        checkBoxARZ_z = new QCheckBox(verticalLayoutWidget_2);
        checkBoxARZ_z->setObjectName("checkBoxARZ_z");
        checkBoxARZ_z->setChecked(false);

        verticalLayout_7->addWidget(checkBoxARZ_z);

        toolBox->addItem(pageARX, QString::fromUtf8("Obiekt regulacji ARX"));
        pageSymulacja = new QWidget();
        pageSymulacja->setObjectName("pageSymulacja");
        pageSymulacja->setGeometry(QRect(0, 0, 255, 290));
        verticalLayoutWidget_5 = new QWidget(pageSymulacja);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(0, 0, 241, 101));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_14 = new QLabel(verticalLayoutWidget_5);
        label_14->setObjectName("label_14");

        horizontalLayout_12->addWidget(label_14);

        spinBoxInterwal = new QSpinBox(verticalLayoutWidget_5);
        spinBoxInterwal->setObjectName("spinBoxInterwal");
        spinBoxInterwal->setMinimum(100);
        spinBoxInterwal->setMaximum(10000);
        spinBoxInterwal->setValue(500);

        horizontalLayout_12->addWidget(spinBoxInterwal);


        verticalLayout_9->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_15 = new QLabel(verticalLayoutWidget_5);
        label_15->setObjectName("label_15");

        horizontalLayout_13->addWidget(label_15);

        spinBoxWidokKrokow = new QSpinBox(verticalLayoutWidget_5);
        spinBoxWidokKrokow->setObjectName("spinBoxWidokKrokow");
        spinBoxWidokKrokow->setMinimum(1);
        spinBoxWidokKrokow->setMaximum(100000);
        spinBoxWidokKrokow->setValue(100);

        horizontalLayout_13->addWidget(spinBoxWidokKrokow);

        horizontalLayout_13->setStretch(0, 4);
        horizontalLayout_13->setStretch(1, 2);

        verticalLayout_9->addLayout(horizontalLayout_13);

        toolBox->addItem(pageSymulacja, QString::fromUtf8("Nastawy symulacji"));

        verticalLayout->addWidget(toolBox);

        verticalLayout->setStretch(0, 3);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        graphUAR = new QCustomPlot(centralwidget);
        graphUAR->setObjectName("graphUAR");
        graphUAR->setMinimumSize(QSize(500, 0));

        horizontalLayout_21->addWidget(graphUAR);


        verticalLayout_8->addLayout(horizontalLayout_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        graphUchyb = new QCustomPlot(centralwidget);
        graphUchyb->setObjectName("graphUchyb");

        horizontalLayout_20->addWidget(graphUchyb);

        graphPidSum = new QCustomPlot(centralwidget);
        graphPidSum->setObjectName("graphPidSum");

        horizontalLayout_20->addWidget(graphPidSum);

        graphPID = new QCustomPlot(centralwidget);
        graphPID->setObjectName("graphPID");

        horizontalLayout_20->addWidget(graphPID);


        verticalLayout_8->addLayout(horizontalLayout_20);

        verticalLayout_8->setStretch(0, 3);
        verticalLayout_8->setStretch(1, 2);

        horizontalLayout->addLayout(verticalLayout_8);

        horizontalLayout->setStretch(1, 50);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 966, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Symulator UAR", nullptr));
        SYMULACJA->setTitle(QCoreApplication::translate("MainWindow", "SYMULACJA", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Resetuj", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Stan symulacji:", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Wy\305\202\304\205czona", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        groupBoxSkok->setTitle(QCoreApplication::translate("MainWindow", "Sygna\305\202 jednostkowy", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Chwila aktywacji", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        groupBoxKwad->setTitle(QCoreApplication::translate("MainWindow", "Sygna\305\202 prostok\304\205tny", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Okres (w krokach)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Wype\305\202nienie", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        groupBoxSin->setTitle(QCoreApplication::translate("MainWindow", "Sygna\305\202 sinusoidalny", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Okres (w krokach)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        toolBox->setItemText(toolBox->indexOf(pageSygnaly), QCoreApplication::translate("MainWindow", "Sygna\305\202 wej\305\233ciowy", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Nastawy", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Proporcjonalna", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ca\305\202kuj\304\205ca", nullptr));
        btnResetI->setText(QCoreApplication::translate("MainWindow", "Zresetuj pami\304\231\304\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "R\303\263\305\272niczkuj\304\205ca", nullptr));
        btnResetD->setText(QCoreApplication::translate("MainWindow", "Zresetuj pami\304\231\304\207", nullptr));
        toolBox->setItemText(toolBox->indexOf(pagePID), QCoreApplication::translate("MainWindow", "Regulator PID", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Wsp\303\263\305\202czynniki a:", nullptr));
        btnARXAdd_A->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        btnARXClear_A->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Wsp\303\263\305\202czynniki b:", nullptr));
        btnARXAdd_B->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        btnARXClear_B->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Op\303\263\305\272nienie (w krokach):", nullptr));
        checkBoxARZ_z->setText(QCoreApplication::translate("MainWindow", "Uwzgl\304\231dnij zak\305\202\303\263cenie", nullptr));
        toolBox->setItemText(toolBox->indexOf(pageARX), QCoreApplication::translate("MainWindow", "Obiekt regulacji ARX", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202 czasowy [ms]:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Liczba wy\305\233w. krok\303\263w:", nullptr));
        toolBox->setItemText(toolBox->indexOf(pageSymulacja), QCoreApplication::translate("MainWindow", "Nastawy symulacji", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
