/********************************************************************************
** Form generated from reading UI file 'accountmanagewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTMANAGEWINDOW_H
#define UI_ACCOUNTMANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountManageWindow
{
public:
    QLabel *label;

    void setupUi(QWidget *AccountManageWindow)
    {
        if (AccountManageWindow->objectName().isEmpty())
            AccountManageWindow->setObjectName("AccountManageWindow");
        AccountManageWindow->resize(1030, 730);
        label = new QLabel(AccountManageWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 240, 501, 191));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        retranslateUi(AccountManageWindow);

        QMetaObject::connectSlotsByName(AccountManageWindow);
    } // setupUi

    void retranslateUi(QWidget *AccountManageWindow)
    {
        AccountManageWindow->setWindowTitle(QCoreApplication::translate("AccountManageWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("AccountManageWindow", "THIS IS ACCOUNTMANAGEWINDOW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountManageWindow: public Ui_AccountManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTMANAGEWINDOW_H