#include "windows.h"
#include "ui_windows.h"
#include "QString"
#include "QStringList"
#include <QDebug>

windows::windows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windows)
{
    ui->setupUi(this);

    this->setWindowTitle("1");

    this->setWindowFlags (Qt::FramelessWindowHint);

    this->ui_label_2();

    ui->plainTextEdit->setEnabled(false);
}

windows::~windows()
{
    delete ui;
}

void windows::on_pushButton_open_clicked()
{
    QString name=ui->lineEdit->text();
    QString a=name.mid(0,1);
    if(name.startsWith('A'))
    {
        qDebug()<<name<<endl;
        this->close();
    }
    else
    {
        qDebug()<<"输入� �式错误"<<endl;
    }

}

void windows::on_pushButton_close_2_clicked()
{
    this->close();
}
void windows::ui_label_2()
{
    QPalette palette;
    palette.setColor(QPalette::Background, QColor (0, 152, 227, 255));
    palette.setColor(QPalette::WindowText, Qt::white);

    ui->label_2->setAutoFillBackground(true);
    ui->label_2->setPalette(palette);

    QFont font;
    font.setPointSize(10);
    ui->label_2->setFont(font);
}
