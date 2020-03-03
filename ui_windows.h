/********************************************************************************
** Form generated from reading UI file 'windows.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWS_H
#define UI_WINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windows
{
public:
    QPushButton *pushButton_open;
    QPushButton *pushButton_close_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *windows)
    {
        if (windows->objectName().isEmpty())
            windows->setObjectName(QStringLiteral("windows"));
        windows->resize(462, 130);
        pushButton_open = new QPushButton(windows);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setGeometry(QRect(80, 70, 61, 28));
        pushButton_close_2 = new QPushButton(windows);
        pushButton_close_2->setObjectName(QStringLiteral("pushButton_close_2"));
        pushButton_close_2->setGeometry(QRect(80, 100, 61, 28));
        plainTextEdit = new QPlainTextEdit(windows);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(160, 40, 291, 87));
        label_2 = new QLabel(windows);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 471, 31));
        widget = new QWidget(windows);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 40, 141, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(windows);

        QMetaObject::connectSlotsByName(windows);
    } // setupUi

    void retranslateUi(QDialog *windows)
    {
        windows->setWindowTitle(QApplication::translate("windows", "Dialog", 0));
        pushButton_open->setText(QApplication::translate("windows", "\347\241\256\345\256\232", 0));
        pushButton_close_2->setText(QApplication::translate("windows", "\345\217\226\346\266\210", 0));
        plainTextEdit->setPlainText(QApplication::translate("windows", "\345\217\202\346\225\260\346\263\250\351\207\212\357\274\232\n"
"\345\234\260\345\235\200\347\254\246\345\217\267\n"
"\345\234\260\345\235\200/\345\200\274\345\205\201\350\256\270\357\274\232\n"
"X.1\357\274\214Y.1\357\274\214F.1\357\274\214G.1\357\274\214R.1\357\274\214K.1\357\274\214A.1", 0));
        label_2->setText(QApplication::translate("windows", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("windows", "\345\234\260\345\235\200/\347\254\246\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class windows: public Ui_windows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWS_H
