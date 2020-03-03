#ifndef UI_JHT_H
#define UI_JHT_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newstruct.h"
#include "QDebug"
extern int cpu_mdl;
//extern vector<Network>Networks;
//extern int cnt_networks;
//extern QList<components>networks;
extern QList<networks>programs;




//void set_num(int i, QStandardItemModel *standItemModel);

void set_col(QLabel *label,QString s);

//void set_stand2(QStandardItemModel *standItemModel,int cnt_leftpowerline);

//void set_stand3(QStandardItemModel *standItemModel,int cnt_leftpowerline);

void SetItem(QStandardItemModel *standItemModel,int cnt_leftpowerline);

void SetLabel(QStandardItemModel *standItemModel, Ui::MainWindow *ui,int x, int y, QString picture, QString name);







#endif // UI_JHT_H
