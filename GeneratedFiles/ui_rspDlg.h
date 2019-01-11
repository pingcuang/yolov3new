/********************************************************************************
** Form generated from reading UI file 'rspDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSPDLG_H
#define UI_RSPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_rspManage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *rspText;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *describeText;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *rspManage)
    {
        if (rspManage->objectName().isEmpty())
            rspManage->setObjectName(QStringLiteral("rspManage"));
        rspManage->resize(561, 125);
        gridLayout = new QGridLayout(rspManage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(rspManage);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label);

        rspText = new QLineEdit(rspManage);
        rspText->setObjectName(QStringLiteral("rspText"));

        horizontalLayout->addWidget(rspText);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(rspManage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_2);

        describeText = new QLineEdit(rspManage);
        describeText->setObjectName(QStringLiteral("describeText"));

        horizontalLayout_2->addWidget(describeText);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 20, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okBtn = new QPushButton(rspManage);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setMinimumSize(QSize(60, 25));
        okBtn->setMaximumSize(QSize(60, 25));

        horizontalLayout_3->addWidget(okBtn);

        cancelBtn = new QPushButton(rspManage);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(60, 25));
        cancelBtn->setMaximumSize(QSize(60, 25));

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 6);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(rspManage);

        QMetaObject::connectSlotsByName(rspManage);
    } // setupUi

    void retranslateUi(QDialog *rspManage)
    {
        rspManage->setWindowTitle(QApplication::translate("rspManage", "rspManage", nullptr));
        label->setText(QApplication::translate("rspManage", "rtsp\357\274\232 ", nullptr));
        label_2->setText(QApplication::translate("rspManage", "\346\217\217\350\277\260\357\274\232", nullptr));
        okBtn->setText(QApplication::translate("rspManage", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QApplication::translate("rspManage", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rspManage: public Ui_rspManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSPDLG_H
