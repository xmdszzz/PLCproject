#include "UiUpdata.h"
//2020/2/26 江海涛 统一将set——num和set——stand2改为SetItem，并优化函数
//  添加SetLable，统一整合了Lable的创建


void set_col(QLabel *label,QString s)
{
    label->setScaledContents(true);
    label->setPixmap(QPixmap(QString(PATH_PCITURE) + s));
}

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


void SetLabel(QStandardItemModel *standItemModel, Ui::MainWindow *ui, int x, int y, QString picture, QString name, QString cell)
{
    QLabel *label = new QLabel;
    label->setStyleSheet(QString("border-image:url(%1);color:rgb(128,128,128);").arg(QString(PATH_PCITURE)+picture));
    label->setContentsMargins(25,0,0,13);
    label->setText(name+"\n"+cell);
//    label->setContentsMargins(25,0,0,0);
//    label->setText(cell);
    ui->tableView->setIndexWidget(standItemModel->index(x, y),label);
}

void ShowRowName(QString name)
{

}
