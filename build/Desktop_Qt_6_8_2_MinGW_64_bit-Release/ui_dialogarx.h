/********************************************************************************
** Form generated from reading UI file 'dialogarx.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGARX_H
#define UI_DIALOGARX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogARX
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_15;
    QDoubleSpinBox *doubleSpinBoxARX_A;
    QPushButton *btnARXAdd_A;
    QPushButton *btnARXClear_A;
    QLineEdit *lineEditARXView_A;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_19;
    QDoubleSpinBox *doubleSpinBoxARX_B_2;
    QPushButton *btnARXAdd_B_2;
    QPushButton *btnARXClear_B_2;
    QLineEdit *lineEditARXView_B_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QSpinBox *spinBoxARX_k;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *checkBoxARZ_z;
    QDoubleSpinBox *doubleSpinBoxARX_z;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAccept;
    QPushButton *btnCancel;

    void setupUi(QDialog *DialogARX)
    {
        if (DialogARX->objectName().isEmpty())
            DialogARX->setObjectName("DialogARX");
        DialogARX->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogARX);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_3 = new QGroupBox(DialogARX);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        verticalLayoutWidget_6 = new QWidget(groupBox_3);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(0, 20, 381, 61));
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
        doubleSpinBoxARX_A->setValue(0.000000000000000);

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
        lineEditARXView_A->setFrame(true);
        lineEditARXView_A->setReadOnly(false);

        verticalLayout_10->addWidget(lineEditARXView_A);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(DialogARX);
        groupBox_4->setObjectName("groupBox_4");
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        verticalLayoutWidget_8 = new QWidget(groupBox_4);
        verticalLayoutWidget_8->setObjectName("verticalLayoutWidget_8");
        verticalLayoutWidget_8->setGeometry(QRect(0, 20, 381, 61));
        verticalLayout_12 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_12->setSpacing(5);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        doubleSpinBoxARX_B_2 = new QDoubleSpinBox(verticalLayoutWidget_8);
        doubleSpinBoxARX_B_2->setObjectName("doubleSpinBoxARX_B_2");
        doubleSpinBoxARX_B_2->setMinimum(-100.000000000000000);
        doubleSpinBoxARX_B_2->setMaximum(100.000000000000000);
        doubleSpinBoxARX_B_2->setSingleStep(0.100000000000000);
        doubleSpinBoxARX_B_2->setValue(0.000000000000000);

        horizontalLayout_19->addWidget(doubleSpinBoxARX_B_2);

        btnARXAdd_B_2 = new QPushButton(verticalLayoutWidget_8);
        btnARXAdd_B_2->setObjectName("btnARXAdd_B_2");

        horizontalLayout_19->addWidget(btnARXAdd_B_2);

        btnARXClear_B_2 = new QPushButton(verticalLayoutWidget_8);
        btnARXClear_B_2->setObjectName("btnARXClear_B_2");

        horizontalLayout_19->addWidget(btnARXClear_B_2);


        verticalLayout_12->addLayout(horizontalLayout_19);

        lineEditARXView_B_2 = new QLineEdit(verticalLayoutWidget_8);
        lineEditARXView_B_2->setObjectName("lineEditARXView_B_2");
        lineEditARXView_B_2->setReadOnly(true);

        verticalLayout_12->addWidget(lineEditARXView_B_2);


        verticalLayout->addWidget(groupBox_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_16 = new QLabel(DialogARX);
        label_16->setObjectName("label_16");

        horizontalLayout_14->addWidget(label_16);

        spinBoxARX_k = new QSpinBox(DialogARX);
        spinBoxARX_k->setObjectName("spinBoxARX_k");
        spinBoxARX_k->setMinimum(1);
        spinBoxARX_k->setMaximum(100);

        horizontalLayout_14->addWidget(spinBoxARX_k);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(-1, 0, -1, 0);
        checkBoxARZ_z = new QCheckBox(DialogARX);
        checkBoxARZ_z->setObjectName("checkBoxARZ_z");
        checkBoxARZ_z->setChecked(false);

        horizontalLayout_16->addWidget(checkBoxARZ_z);

        doubleSpinBoxARX_z = new QDoubleSpinBox(DialogARX);
        doubleSpinBoxARX_z->setObjectName("doubleSpinBoxARX_z");
        doubleSpinBoxARX_z->setEnabled(false);
        doubleSpinBoxARX_z->setDecimals(3);
        doubleSpinBoxARX_z->setMaximum(10000.000000000000000);
        doubleSpinBoxARX_z->setSingleStep(0.010000000000000);
        doubleSpinBoxARX_z->setStepType(QAbstractSpinBox::StepType::DefaultStepType);

        horizontalLayout_16->addWidget(doubleSpinBoxARX_z);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAccept = new QPushButton(DialogARX);
        btnAccept->setObjectName("btnAccept");

        horizontalLayout->addWidget(btnAccept);

        btnCancel = new QPushButton(DialogARX);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogARX);

        QMetaObject::connectSlotsByName(DialogARX);
    } // setupUi

    void retranslateUi(QDialog *DialogARX)
    {
        DialogARX->setWindowTitle(QCoreApplication::translate("DialogARX", "Dialog", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogARX", "Wsp\303\263\305\202czynniki a:", nullptr));
        btnARXAdd_A->setText(QCoreApplication::translate("DialogARX", "Dodaj", nullptr));
        btnARXClear_A->setText(QCoreApplication::translate("DialogARX", "Wyczy\305\233\304\207", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DialogARX", "Wsp\303\263\305\202czynniki b:", nullptr));
        btnARXAdd_B_2->setText(QCoreApplication::translate("DialogARX", "Dodaj", nullptr));
        btnARXClear_B_2->setText(QCoreApplication::translate("DialogARX", "Wyczy\305\233\304\207", nullptr));
        label_16->setText(QCoreApplication::translate("DialogARX", "Op\303\263\305\272nienie (w krokach):", nullptr));
        checkBoxARZ_z->setText(QCoreApplication::translate("DialogARX", "Uwzgl\304\231dnij zak\305\202\303\263cenie", nullptr));
        btnAccept->setText(QCoreApplication::translate("DialogARX", "Zatwierd\305\272", nullptr));
        btnCancel->setText(QCoreApplication::translate("DialogARX", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogARX: public Ui_DialogARX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGARX_H
