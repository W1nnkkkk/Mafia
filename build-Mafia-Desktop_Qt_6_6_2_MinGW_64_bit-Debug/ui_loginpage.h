/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *login;
    QLabel *label_2;
    QLineEdit *password;
    QFormLayout *formLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(360, 211);
        centralwidget = new QWidget(LoginPage);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        login = new QLineEdit(centralwidget);
        login->setObjectName("login");

        formLayout->setWidget(0, QFormLayout::FieldRole, login);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, password);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pushButton);

        horizontalSpacer = new QSpacerItem(183, 26, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        formLayout_2->setItem(0, QFormLayout::FieldRole, horizontalSpacer);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(183, 26, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        formLayout_2->setItem(1, QFormLayout::FieldRole, horizontalSpacer_2);


        verticalLayout->addLayout(formLayout_2);

        LoginPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 360, 25));
        LoginPage->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginPage);
        statusbar->setObjectName("statusbar");
        LoginPage->setStatusBar(statusbar);

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QMainWindow *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "LoginPage", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginPage", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
