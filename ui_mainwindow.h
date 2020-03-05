/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ladder;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QTreeView *treeView;
    QTableView *tableView_2;
    QLabel *label_program_info;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_14;
    QPushButton *pushButton_9;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *button_open;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 687);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_ladder = new QLabel(centralWidget);
        label_ladder->setObjectName(QStringLiteral("label_ladder"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_ladder->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("3ds"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_ladder->setFont(font);
        label_ladder->setScaledContents(true);

        verticalLayout_2->addWidget(label_ladder);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QLatin1String("selection-background-color: rgb(255, 128, 0);\n"
""));

        horizontalLayout_3->addWidget(tableView);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        horizontalLayout_3->addWidget(treeView);

        tableView_2 = new QTableView(centralWidget);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));

        horizontalLayout_3->addWidget(tableView_2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        label_program_info = new QLabel(centralWidget);
        label_program_info->setObjectName(QStringLiteral("label_program_info"));

        verticalLayout_2->addWidget(label_program_info);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_12);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_10);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_13);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy1.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_15);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy1.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_16);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy1.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_14);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_9);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 12);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 2);

        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(17);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_7);

        button_open = new QPushButton(centralWidget);
        button_open->setObjectName(QStringLiteral("button_open"));
        sizePolicy1.setHeightForWidth(button_open->sizePolicy().hasHeightForWidth());
        button_open->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(button_open);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 11);
        horizontalLayout_2->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_ladder->setText(QApplication::translate("MainWindow", "\346\242\257\345\275\242\345\233\276", 0));
        label_program_info->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\344\277\241\346\201\257", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "\345\267\245\347\250\213\347\256\241\347\220\206", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\346\250\241\345\274\217", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\210\227\350\241\250", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\345\210\227\350\241\250", 0));
        pushButton_15->setText(QString());
        pushButton_16->setText(QString());
        pushButton_14->setText(QString());
        pushButton_9->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "\344\270\200\347\272\247\347\250\213\345\272\217", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\344\272\214\347\272\247\347\250\213\345\272\217", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\255\220\347\250\213\345\272\217", 0));
        pushButton_5->setText(QString());
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", 0));
        pushButton_7->setText(QString());
        button_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
