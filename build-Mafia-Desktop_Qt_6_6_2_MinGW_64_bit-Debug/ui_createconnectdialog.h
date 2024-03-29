/********************************************************************************
** Form generated from reading UI file 'createconnectdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONNECTDIALOG_H
#define UI_CREATECONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *CreateConnectDialog)
    {
        if (CreateConnectDialog->objectName().isEmpty())
            CreateConnectDialog->setObjectName("CreateConnectDialog");
        CreateConnectDialog->resize(333, 95);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateConnectDialog->sizePolicy().hasHeightForWidth());
        CreateConnectDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(CreateConnectDialog);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(CreateConnectDialog);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(CreateConnectDialog);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CreateConnectDialog);

        QMetaObject::connectSlotsByName(CreateConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateConnectDialog)
    {
        CreateConnectDialog->setWindowTitle(QCoreApplication::translate("CreateConnectDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateConnectDialog", "Text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateConnectDialog: public Ui_CreateConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECTDIALOG_H
