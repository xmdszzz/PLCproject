/********************************************************************************
** Form generated from reading UI file 'panel_add_component.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_ADD_COMPONENT_H
#define UI_PANEL_ADD_COMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Panel_add_component
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Panel_add_component)
    {
        if (Panel_add_component->objectName().isEmpty())
            Panel_add_component->setObjectName(QString::fromUtf8("Panel_add_component"));
        Panel_add_component->resize(584, 534);
        pushButton = new QPushButton(Panel_add_component);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 400, 93, 28));
        pushButton_2 = new QPushButton(Panel_add_component);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 400, 93, 28));

        retranslateUi(Panel_add_component);

        QMetaObject::connectSlotsByName(Panel_add_component);
    } // setupUi

    void retranslateUi(QDialog *Panel_add_component)
    {
        Panel_add_component->setWindowTitle(QCoreApplication::translate("Panel_add_component", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Panel_add_component", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Panel_add_component", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Panel_add_component: public Ui_Panel_add_component {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_ADD_COMPONENT_H
