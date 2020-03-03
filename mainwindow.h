#ifndef MAINWINDOW_H
#define MAINWINDOW_H


//QT headers:
#include <QMainWindow>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <dialog.h>
#include "parseld2.h"
#include "editld2.h"
#include "windows.h"
#include "stable.h"

//cpp headers:
#include <iostream>


//custom headers:





#define PATH_PCITURE "pictures/"
using namespace std;
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//members functions:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void UI_Init();
    void load_Ladder();
    void resizeEvent(QResizeEvent *event);
    void load_ld2(int);
    void reFreshLd2(int);
    void hidetreeView();

//members:
    QStandardItemModel *standItemModel;
    Dialog dialog;

private slots:
    void on_pushButton_6_clicked();

    void on_button_open_clicked();

    void on_pushButton_9_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void slot_treeView_pressed(QModelIndex modeIndex);

    void slot_start_window();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
