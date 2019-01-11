/********************************************************************************
** Form generated from reading UI file 'monitorManage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORMANAGE_H
#define UI_MONITORMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_monitorManage
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableView *tableViewAllMonitor;
    QVBoxLayout *verticalLayout;
    QPushButton *monitorRightMoveBtn;
    QPushButton *monitorLeftMoveBtn;
    QTableView *tableViewPlayMonitor;

    void setupUi(QDialog *monitorManage)
    {
        if (monitorManage->objectName().isEmpty())
            monitorManage->setObjectName(QStringLiteral("monitorManage"));
        monitorManage->resize(1029, 464);
        gridLayout = new QGridLayout(monitorManage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableViewAllMonitor = new QTableView(monitorManage);
        tableViewAllMonitor->setObjectName(QStringLiteral("tableViewAllMonitor"));

        horizontalLayout->addWidget(tableViewAllMonitor);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        monitorRightMoveBtn = new QPushButton(monitorManage);
        monitorRightMoveBtn->setObjectName(QStringLiteral("monitorRightMoveBtn"));

        verticalLayout->addWidget(monitorRightMoveBtn);

        monitorLeftMoveBtn = new QPushButton(monitorManage);
        monitorLeftMoveBtn->setObjectName(QStringLiteral("monitorLeftMoveBtn"));

        verticalLayout->addWidget(monitorLeftMoveBtn);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableViewPlayMonitor = new QTableView(monitorManage);
        tableViewPlayMonitor->setObjectName(QStringLiteral("tableViewPlayMonitor"));

        gridLayout->addWidget(tableViewPlayMonitor, 0, 1, 1, 1);


        retranslateUi(monitorManage);

        QMetaObject::connectSlotsByName(monitorManage);
    } // setupUi

    void retranslateUi(QDialog *monitorManage)
    {
        monitorManage->setWindowTitle(QApplication::translate("monitorManage", "\347\233\221\346\216\247\347\256\241\347\220\206", nullptr));
        monitorRightMoveBtn->setText(QApplication::translate("monitorManage", ">>", nullptr));
        monitorLeftMoveBtn->setText(QApplication::translate("monitorManage", "<<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monitorManage: public Ui_monitorManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORMANAGE_H
