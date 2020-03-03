#include "UiUpdata.h"
//2020/2/26 江海涛 统一将set——num和set——stand2改为SetItem，并优化函数
//  添加SetLable，统一整合了Lable的创建

//void set_num(int i, QStandardItemModel *standItemModel)
//{
//    QStandardItem *standItem0 = new QStandardItem();
//    QStandardItem *standItem1 = new QStandardItem();
//    QStandardItem *standItem2 = new QStandardItem();
//    QStandardItem *standItem3 = new QStandardItem();
//    QStandardItem *standItem4 = new QStandardItem();
//    QStandardItem *standItem5 = new QStandardItem();
//    QStandardItem *standItem6 = new QStandardItem();
//    QStandardItem *standItem7 = new QStandardItem();
//    QStandardItem *standItem8 = new QStandardItem();
//    QStandardItem *standItem9 = new QStandardItem();
//    QStandardItem *standItem10 = new QStandardItem();

//    standItemModel->setItem(i,0,standItem0);
//    standItemModel->setItem(i,1,standItem1);
//    standItemModel->setItem(i,2,standItem2);
//    standItemModel->setItem(i,3,standItem3);
//    standItemModel->setItem(i,4,standItem4);
//    standItemModel->setItem(i,5,standItem5);
//    standItemModel->setItem(i,6,standItem6);
//    standItemModel->setItem(i,7,standItem7);
//    standItemModel->setItem(i,8,standItem8);
//    standItemModel->setItem(i,9,standItem9);
//    standItemModel->setItem(i,10,standItem10);
//}


void set_col(QLabel *label,QString s)
{
    label->setScaledContents(true);
    label->setPixmap(QPixmap(QString(PATH_PCITURE) + s));
}

//void set_stand2(QStandardItemModel *standItemModel,int cnt_leftpowerline)
//{
//    QStandardItem *standItem0 = new QStandardItem();
//    QStandardItem *standItem1 = new QStandardItem();
//    QStandardItem *standItem2 = new QStandardItem();
//    QStandardItem *standItem3 = new QStandardItem();
//    QStandardItem *standItem4 = new QStandardItem();
//    QStandardItem *standItem5 = new QStandardItem();
//    QStandardItem *standItem6 = new QStandardItem();
//    QStandardItem *standItem7 = new QStandardItem();
//    QStandardItem *standItem8 = new QStandardItem();
//    QStandardItem *standItem9 = new QStandardItem();
//    QStandardItem *standItem10 = new QStandardItem();

//    standItemModel->setItem(cnt_leftpowerline,0,standItem0);
//    standItemModel->setItem(cnt_leftpowerline,1,standItem1);
//    standItemModel->setItem(cnt_leftpowerline,2,standItem2);
//    standItemModel->setItem(cnt_leftpowerline,3,standItem3);
//    standItemModel->setItem(cnt_leftpowerline,4,standItem4);
//    standItemModel->setItem(cnt_leftpowerline,5,standItem5);
//    standItemModel->setItem(cnt_leftpowerline,6,standItem6);
//    standItemModel->setItem(cnt_leftpowerline,7,standItem7);
//    standItemModel->setItem(cnt_leftpowerline,8,standItem8);
//    standItemModel->setItem(cnt_leftpowerline,9,standItem9);
//    standItemModel->setItem(cnt_leftpowerline,10,standItem10);
//}

void SetItem(QStandardItemModel *standItemModel,int cnt_leftpowerline)
{
    QStandardItem *standItem[12];
    for(int i = 0; i < 11; i++)
    {
        standItem[i] = new QStandardItem();
        standItemModel->setItem(cnt_leftpowerline,i,standItem[i]);
    }
}

void SetLabel(QStandardItemModel *standItemModel, Ui::MainWindow *ui, int x, int y, QString picture, QString name)
{
    QLabel *label = new QLabel;
//    set_col(label,name);
    label->setStyleSheet(QString("border-image:url(%1);color:rgb(128,128,128);").arg(QString(PATH_PCITURE)+picture));
    label->setContentsMargins(25,0,0,25);
    label->setText(name);
    ui->tableView->setIndexWidget(standItemModel->index(x, y),label);
}
