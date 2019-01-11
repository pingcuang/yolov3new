/********************************************************************************
** Form generated from reading UI file 'CMS.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMS_H
#define UI_CMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMSClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *maxBtn;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QSpacerItem *verticalSpacer;
    QPushButton *rspManageBtn;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *monitor1;
    QLabel *monitor_label_1;
    QVBoxLayout *verticalLayout_4;
    QLabel *monitor2;
    QLabel *monitor_label_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *monitor3;
    QLabel *monitor_label_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *monitor4;
    QLabel *monitor_label_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *monitor5;
    QLabel *monitor_label_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *monitor6;
    QLabel *monitor_label_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *monitor7;
    QLabel *monitor_label_7;
    QVBoxLayout *verticalLayout_10;
    QLabel *monitor8;
    QLabel *monitor_label_8;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *monitor9;
    QLabel *monitor_label_9;
    QVBoxLayout *verticalLayout_11;
    QLabel *monitor10;
    QLabel *monitor_label_10;
    QVBoxLayout *verticalLayout_12;
    QLabel *monitor11;
    QLabel *monitor_label_11;
    QVBoxLayout *verticalLayout_13;
    QLabel *monitor12;
    QLabel *monitor_label_12;
    QWidget *widget_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *fullScreenBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMSClass)
    {
        if (CMSClass->objectName().isEmpty())
            CMSClass->setObjectName(QStringLiteral("CMSClass"));
        CMSClass->resize(1182, 732);
        centralWidget = new QWidget(CMSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 9, -1, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minBtn = new QPushButton(widget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMaximumSize(QSize(18, 18));

        horizontalLayout->addWidget(minBtn);

        maxBtn = new QPushButton(widget);
        maxBtn->setObjectName(QStringLiteral("maxBtn"));
        maxBtn->setMaximumSize(QSize(18, 18));

        horizontalLayout->addWidget(maxBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMaximumSize(QSize(18, 18));

        horizontalLayout->addWidget(closeBtn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(214, 621));
        widget_3->setMaximumSize(QSize(214, 16777215));
        widget_3->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        treeWidget = new QTreeWidget(widget_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        verticalSpacer = new QSpacerItem(60, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        rspManageBtn = new QPushButton(widget_3);
        rspManageBtn->setObjectName(QStringLiteral("rspManageBtn"));
        rspManageBtn->setMinimumSize(QSize(77, 78));
        rspManageBtn->setMaximumSize(QSize(77, 78));
        rspManageBtn->setLayoutDirection(Qt::LeftToRight);
        rspManageBtn->setAutoRepeat(false);
        rspManageBtn->setAutoExclusive(false);
        rspManageBtn->setAutoRepeatInterval(100);

        verticalLayout->addWidget(rspManageBtn);

        verticalSpacer_2 = new QSpacerItem(60, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(3, 1);

        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        monitor1 = new QLabel(widget_4);
        monitor1->setObjectName(QStringLiteral("monitor1"));
        monitor1->setMinimumSize(QSize(224, 126));
        QFont font;
        font.setPointSize(12);
        monitor1->setFont(font);
        monitor1->setFocusPolicy(Qt::NoFocus);
        monitor1->setLayoutDirection(Qt::LeftToRight);
        monitor1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(monitor1);

        monitor_label_1 = new QLabel(widget_4);
        monitor_label_1->setObjectName(QStringLiteral("monitor_label_1"));

        verticalLayout_3->addWidget(monitor_label_1);

        verticalLayout_3->setStretch(0, 9);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        monitor2 = new QLabel(widget_4);
        monitor2->setObjectName(QStringLiteral("monitor2"));
        monitor2->setMinimumSize(QSize(224, 126));
        monitor2->setFont(font);
        monitor2->setFocusPolicy(Qt::NoFocus);
        monitor2->setLayoutDirection(Qt::LeftToRight);
        monitor2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(monitor2);

        monitor_label_2 = new QLabel(widget_4);
        monitor_label_2->setObjectName(QStringLiteral("monitor_label_2"));

        verticalLayout_4->addWidget(monitor_label_2);

        verticalLayout_4->setStretch(0, 9);
        verticalLayout_4->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        monitor3 = new QLabel(widget_4);
        monitor3->setObjectName(QStringLiteral("monitor3"));
        monitor3->setMinimumSize(QSize(224, 126));
        monitor3->setFont(font);
        monitor3->setFocusPolicy(Qt::NoFocus);
        monitor3->setLayoutDirection(Qt::LeftToRight);
        monitor3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(monitor3);

        monitor_label_3 = new QLabel(widget_4);
        monitor_label_3->setObjectName(QStringLiteral("monitor_label_3"));

        verticalLayout_5->addWidget(monitor_label_3);

        verticalLayout_5->setStretch(0, 9);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        monitor4 = new QLabel(widget_4);
        monitor4->setObjectName(QStringLiteral("monitor4"));
        monitor4->setMinimumSize(QSize(224, 126));
        monitor4->setFont(font);
        monitor4->setFocusPolicy(Qt::NoFocus);
        monitor4->setLayoutDirection(Qt::LeftToRight);
        monitor4->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(monitor4);

        monitor_label_4 = new QLabel(widget_4);
        monitor_label_4->setObjectName(QStringLiteral("monitor_label_4"));

        verticalLayout_6->addWidget(monitor_label_4);

        verticalLayout_6->setStretch(0, 9);
        verticalLayout_6->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_6);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        monitor5 = new QLabel(widget_4);
        monitor5->setObjectName(QStringLiteral("monitor5"));
        monitor5->setMinimumSize(QSize(224, 126));
        monitor5->setMaximumSize(QSize(16777215, 16777215));
        monitor5->setFont(font);
        monitor5->setFocusPolicy(Qt::NoFocus);
        monitor5->setLayoutDirection(Qt::LeftToRight);
        monitor5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(monitor5);

        monitor_label_5 = new QLabel(widget_4);
        monitor_label_5->setObjectName(QStringLiteral("monitor_label_5"));

        verticalLayout_2->addWidget(monitor_label_5);

        verticalLayout_2->setStretch(0, 9);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        monitor6 = new QLabel(widget_4);
        monitor6->setObjectName(QStringLiteral("monitor6"));
        monitor6->setMinimumSize(QSize(224, 126));
        monitor6->setFont(font);
        monitor6->setFocusPolicy(Qt::NoFocus);
        monitor6->setLayoutDirection(Qt::LeftToRight);
        monitor6->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(monitor6);

        monitor_label_6 = new QLabel(widget_4);
        monitor_label_6->setObjectName(QStringLiteral("monitor_label_6"));

        verticalLayout_8->addWidget(monitor_label_6);

        verticalLayout_8->setStretch(0, 9);
        verticalLayout_8->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        monitor7 = new QLabel(widget_4);
        monitor7->setObjectName(QStringLiteral("monitor7"));
        monitor7->setMinimumSize(QSize(224, 126));
        monitor7->setFont(font);
        monitor7->setFocusPolicy(Qt::NoFocus);
        monitor7->setLayoutDirection(Qt::LeftToRight);
        monitor7->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(monitor7);

        monitor_label_7 = new QLabel(widget_4);
        monitor_label_7->setObjectName(QStringLiteral("monitor_label_7"));

        verticalLayout_9->addWidget(monitor_label_7);

        verticalLayout_9->setStretch(0, 9);
        verticalLayout_9->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        monitor8 = new QLabel(widget_4);
        monitor8->setObjectName(QStringLiteral("monitor8"));
        monitor8->setMinimumSize(QSize(224, 126));
        monitor8->setFont(font);
        monitor8->setFocusPolicy(Qt::NoFocus);
        monitor8->setLayoutDirection(Qt::LeftToRight);
        monitor8->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(monitor8);

        monitor_label_8 = new QLabel(widget_4);
        monitor_label_8->setObjectName(QStringLiteral("monitor_label_8"));

        verticalLayout_10->addWidget(monitor_label_8);

        verticalLayout_10->setStretch(0, 9);
        verticalLayout_10->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_10);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        monitor9 = new QLabel(widget_4);
        monitor9->setObjectName(QStringLiteral("monitor9"));
        monitor9->setMinimumSize(QSize(224, 126));
        monitor9->setFont(font);
        monitor9->setFocusPolicy(Qt::NoFocus);
        monitor9->setLayoutDirection(Qt::LeftToRight);
        monitor9->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(monitor9);

        monitor_label_9 = new QLabel(widget_4);
        monitor_label_9->setObjectName(QStringLiteral("monitor_label_9"));

        verticalLayout_7->addWidget(monitor_label_9);

        verticalLayout_7->setStretch(0, 9);
        verticalLayout_7->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        monitor10 = new QLabel(widget_4);
        monitor10->setObjectName(QStringLiteral("monitor10"));
        monitor10->setMinimumSize(QSize(224, 126));
        monitor10->setFont(font);
        monitor10->setFocusPolicy(Qt::NoFocus);
        monitor10->setLayoutDirection(Qt::LeftToRight);
        monitor10->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(monitor10);

        monitor_label_10 = new QLabel(widget_4);
        monitor_label_10->setObjectName(QStringLiteral("monitor_label_10"));

        verticalLayout_11->addWidget(monitor_label_10);

        verticalLayout_11->setStretch(0, 9);
        verticalLayout_11->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        monitor11 = new QLabel(widget_4);
        monitor11->setObjectName(QStringLiteral("monitor11"));
        monitor11->setMinimumSize(QSize(224, 126));
        monitor11->setFont(font);
        monitor11->setFocusPolicy(Qt::NoFocus);
        monitor11->setLayoutDirection(Qt::LeftToRight);
        monitor11->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(monitor11);

        monitor_label_11 = new QLabel(widget_4);
        monitor_label_11->setObjectName(QStringLiteral("monitor_label_11"));

        verticalLayout_12->addWidget(monitor_label_11);

        verticalLayout_12->setStretch(0, 9);
        verticalLayout_12->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        monitor12 = new QLabel(widget_4);
        monitor12->setObjectName(QStringLiteral("monitor12"));
        monitor12->setMinimumSize(QSize(224, 126));
        monitor12->setFont(font);
        monitor12->setFocusPolicy(Qt::NoFocus);
        monitor12->setLayoutDirection(Qt::LeftToRight);
        monitor12->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(monitor12);

        monitor_label_12 = new QLabel(widget_4);
        monitor_label_12->setObjectName(QStringLiteral("monitor_label_12"));

        verticalLayout_13->addWidget(monitor_label_12);

        verticalLayout_13->setStretch(0, 9);
        verticalLayout_13->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout_13);


        gridLayout_4->addLayout(horizontalLayout_6, 2, 0, 1, 1);


        horizontalLayout_5->addWidget(widget_4);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget_2, 1, 0, 1, 1);

        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_2 = new QGridLayout(widget_5);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        fullScreenBtn = new QPushButton(widget_5);
        fullScreenBtn->setObjectName(QStringLiteral("fullScreenBtn"));
        fullScreenBtn->setMinimumSize(QSize(24, 24));
        fullScreenBtn->setMaximumSize(QSize(24, 24));
        fullScreenBtn->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(fullScreenBtn);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget_5, 2, 0, 1, 1);

        CMSClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CMSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMSClass->setStatusBar(statusBar);

        retranslateUi(CMSClass);

        QMetaObject::connectSlotsByName(CMSClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMSClass)
    {
        CMSClass->setWindowTitle(QApplication::translate("CMSClass", "\345\214\272\345\237\237\344\272\272\346\225\260\347\273\237\350\256\241\347\263\273\347\273\237001", nullptr));
        label->setText(QApplication::translate("CMSClass", "001", nullptr));
        minBtn->setText(QString());
        maxBtn->setText(QString());
        closeBtn->setText(QString());
        rspManageBtn->setText(QString());
        monitor1->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2471", nullptr));
        monitor_label_1->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor2->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2472", nullptr));
        monitor_label_2->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor3->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2473", nullptr));
        monitor_label_3->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor4->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2474", nullptr));
        monitor_label_4->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor5->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2475", nullptr));
        monitor_label_5->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor6->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2476", nullptr));
        monitor_label_6->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor7->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2477", nullptr));
        monitor_label_7->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor8->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2478", nullptr));
        monitor_label_8->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor9->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\2479", nullptr));
        monitor_label_9->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor10->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\24710", nullptr));
        monitor_label_10->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor11->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\24711", nullptr));
        monitor_label_11->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        monitor12->setText(QApplication::translate("CMSClass", "\347\233\221\346\216\24712", nullptr));
        monitor_label_12->setText(QApplication::translate("CMSClass", "RSP:", nullptr));
        fullScreenBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CMSClass: public Ui_CMSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMS_H
