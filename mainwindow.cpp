#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newstruct.h"
#include "QDebug"
#include "UiUpdata.h"
#include "QMessageBox"
extern int cpu_mdl;
//extern vector<Network>Networks;
//extern int cnt_networks;
//extern QList<components>networks;
extern QList<networks>programs;

int DefaultSet = 0;//默认状态
int Engineering = 1;//工程管理
int EditMode = 21;//编辑模式
int DataList = 3;//数据列表
int StateList = 4;//状态列表
int NetworkOperat = 22;//网络/行操作
int Functional = 23;//功能指令
int Displacement = 232;//位移/旋转
int Jobnumber = 0;//工程编号，开始为0，第一个
const int Jobnumber_0 = 0;//工程编号，默认0
const int Jobnumber_1 = 1;//工程编号，默认1
const int Jobnumber_2 = 2;//工程编号，默认2

int click_status = DefaultSet;//全局变量
int row,colunm;//光标所在的行列数
int aRow = 10;//总行数

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("APP_PLC");

    this->UI_Init();

    this->load_Ladder();

    this->hidetreeView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_start_window()
{
    windows *win=new windows();
    win->show();
}

void MainWindow::UI_Init()
{
    QPalette palette;
    palette.setColor(QPalette::Background, QColor (0, 152, 227, 255));
    palette.setColor(QPalette::WindowText, Qt::white);

    ui->label_ladder->setAutoFillBackground(true);
    ui->label_ladder->setPalette(palette);

    palette.setColor(QPalette::Background, QColor (168, 197, 215, 255));
    ui->label_program_info->setAutoFillBackground(true);
    ui->label_program_info->setPalette(palette);

    QFont font;
    font.setPointSize(16);
    ui->label_ladder->setFont(font);
    ui->label_program_info->setFont(font);
}

void MainWindow::hidetreeView()
{
    ui->treeView->hide();
    ui->tableView_2->hide();
    ui->pushButton_12->setEnabled(false);//没有打开文件，禁用工程管理
}

void MainWindow::load_Ladder()
{
    standItemModel = new QStandardItemModel();
    standItemModel->setColumnCount(12);



//        QStandardItem *standItem1 = new QStandardItem();



        for(int i = 0; i < 20 ; i ++)
        {
            SetItem(standItemModel,i);

        }




    ui->tableView->setModel(standItemModel);
//    for(int i = 0 ; i <= 10 ; i ++)
//    {
//        if(i == 0)
//        {
//         ui->tableView->setColumnWidth(i,this->size().width()/36);
//        }
//        else
//        {
//         ui->tableView->setColumnWidth(i,this->size().width()/12);
//        }
//    }

//    for(int i = 0 ; i <= 19 ; i ++)
//    {
//         ui->tableView->setRowHeight(i,this->size().width()/24);
//    }


    //1 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_left.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 1),label);
    }


    //2 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 2),label);
    }


    //3 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 3),label);
    }

    //4 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 4),label);
    }

    //5 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 5),label);
    }

    //6 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 6),label);
    }

    //7 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 7),label);
    }


    //8 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 8),label);
    }


    //9 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_1.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 9),label);
    }

    //10 col
    for(int i = 0 ; i < 10 ;i += 2)
    {
        QLabel *label = new QLabel;
        set_col(label,"_right.png");
        ui->tableView->setIndexWidget(this->standItemModel->index(i, 10),label);
    }


//fill 0
    for(int i = 1 ;i < 10 ; i += 2)
    {
        for(int j = 0; j <= 10 ; j ++)
        {


            QLabel *label = new QLabel;
            label->setScaledContents(true);

            if(j == 1)
            {
                label->setPixmap(QPixmap(QString(PATH_PCITURE) + QString("_2.png")));
            }
            else if(j == 10)
            {
                label->setPixmap(QPixmap(QString(PATH_PCITURE) + QString("_2.png")));
            }
//            else
//            {
//                label->setPixmap(QPixmap(QString(PATH_PCITURE) + QString("0.tif")));
//            }

            ui->tableView->setIndexWidget(this->standItemModel->index(i, j),label);
        }
    }


//fill 0 finished

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setShowGrid(false);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->verticalHeader()->setVisible(false);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    for(int i = 0 ; i <= aRow ; i ++)
    {
        if(i == 0)
        {
            ui->tableView->setColumnWidth(i,this->size().width()/36);
        }
        else
        {
         ui->tableView->setColumnWidth(i,this->size().width()/12);
        }
    }

    for(int i = 0 ; i <= aRow ; i ++) //bug
    {
         ui->tableView->setRowHeight(i,this->size().width()/24);
    }
}

void MainWindow::on_pushButton_6_clicked()//工程管理状态下查找，默认状态下查找，编辑状态下取反,网络/行删除行
{
    if(click_status == DefaultSet)
    {
        this->dialog.show();
    }
    else if(click_status == Engineering)
    {
        this->project.setWindowTitle("工程管理信息");
        this->project.show();
    }
    else if(click_status == EditMode)
    {
        TheNot(row,colunm);//取反
        MainWindow::load_ld2(0);
    }
    else if(click_status == NetworkOperat)
    {
        d_row(row);
        MainWindow::load_ld2(Jobnumber);
    }
}

void MainWindow::on_button_open_clicked()//默认状态下打开文件，其他状态下为返回
{
    QObject::disconnect(this->ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slot_start_window()));
    if(click_status==DefaultSet)
    {
        QString path;
        path = QFileDialog::getOpenFileName(this,"open xml file","","xml Files(*.ld2)");
        cout << "The fileName is :"<< path.toStdString() << endl;
        if(path != "")
        {
            //*************************
            // deleteALL_ld2();报错
            //*************************
        parse_ld2file(path.toStdString().data());
        ui->pushButton_12->setEnabled(true);//打开文件后，开启工程管理
        ui->pushButton_3->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        ui->pushButton_2->setStyleSheet(0);//恢复颜色
        ui->pushButton_4->setStyleSheet(0);//恢复颜色
        this->load_ld2(Jobnumber);
        }
    }
    else if(click_status == Engineering)
    {
        click_status = DefaultSet;
        if(Jobnumber == Jobnumber_0) ui->pushButton_3->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        else if(Jobnumber == Jobnumber_1) ui->pushButton_2->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        else if(Jobnumber == Jobnumber_2) ui->pushButton_4->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        ui->treeView->hide();
        ui->pushButton_3->setText("一级程序");
        ui->pushButton_2->setText("二级程序");
        ui->pushButton_4->setText("子程序");
        ui->pushButton_5->setText(" ");
        ui->pushButton_3->setEnabled(true);//启动控件
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_6->setText("查找");
        ui->pushButton_7->setText(" ");
        ui->pushButton_16->setText(" ");
        ui->button_open->setText("打开");
        ui->pushButton_12->setStyleSheet(0);//恢复颜色
        ui->tableView_2->hide();
        ui->tableView->show();
    }
    else
    {
        qDebug()<<Jobnumber<<"saddddddddddddddddddddddddddddddddd";
        if(Jobnumber == Jobnumber_0) ui->pushButton_3->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        else if(Jobnumber == Jobnumber_1) ui->pushButton_2->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        else if(Jobnumber == Jobnumber_2) ui->pushButton_4->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        ui->pushButton_3->setText("一级程序");
        ui->pushButton_2->setText("二级程序");
        ui->pushButton_4->setText("子程序");
        ui->pushButton_5->setText(" ");
        ui->pushButton_6->setText("查找");
        ui->pushButton_7->setText(" ");
        ui->button_open->setText("打开");
        ui->pushButton_12->setText("工程管理");
        ui->pushButton_11->setText("编辑模式");
        ui->pushButton_10->setText("数据列表");
        ui->pushButton_13->setText("状态列表");
        click_status=DefaultSet;
    }
}

void MainWindow::reFreshLd2(int temp = 0)
{
    int cnt_leftpowerline = 0;

    for(int i = 0 ;i < programs[temp].network.size() ; i ++)
    {
//        取消了额外加一行，改成j<= -江海涛
//        SetItem(standItemModel,cnt_leftpowerline);
//        cnt_leftpowerline ++;

        for(int j = 0;j <= programs[temp].network[i].component[0].size();j ++,cnt_leftpowerline ++)
        {
//            QStandardItem *standItem0;
//            if(j == 0)
//            {
//                standItem0 = new QStandardItem(QString::number(i+1));
//            }
//            else
//            {
//                standItem0 = new QStandardItem();
//            }

            SetItem(standItemModel,cnt_leftpowerline);

            //standItem0->setBackground(QColor (0, 152, 227, 255));
//            standItem0->setSelectable(0);
//            standItem0->setEditable(0);

            QString sl,sr ;
            sl = "_left.png";
            sr = "_right.png";
            if(j == 0)
            {
                sl = "_nleft.png";
                sr = "_nright.png";
            }
            //1 col
            QLabel *label = new QLabel;
            set_col(label,sl);
            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_leftpowerline, 1),label);

            //10 col
            QLabel *label2 = new QLabel;
            set_col(label2,sr);
            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_leftpowerline, 10),label2);
        }

    }

    ui->tableView->setModel(standItemModel);
    int cnt_passrow = 0;
    cnt_passrow++;
    QString name;

    for(int i = 0 ; i < programs[temp].network.size() ; i ++)
    {
        QLabel *label = new QLabel;
        label->setStyleSheet("background-color: rgb(0, 255, 0)");
        label->setText(QString("network %1").arg(i+1));
        ui->tableView->setIndexWidget(standItemModel->index(cnt_passrow-1, 2),label);
        for(int j = 0 ; j < programs[temp].network[i].component[0].size() ; j ++)
        {
            for(int k = 0 ; k < 8 ; k ++)
            {
                name = programs[temp].network[i].component[k][j].Name;

                if(k == 0 && programs[temp].network[i].component[k][j].Type == 0)
                {
                    QLabel *label = new QLabel;
                    set_col(label,"_nleft.png");
                    ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1),label);
                }

                if(k == 7 && programs[temp].network[i].component[k][j].Type == 0)
                {
                    QLabel *label = new QLabel;
                    set_col(label,"_nright.png");
                    ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 3),label);
                }
//                if(programs[temp].network[i].component[k][j].Type == 0)
//                {

//                    if(j != 0 && programs[temp].network[i].component[k][j - 1].Data0 == 2 && programs[temp].network[i].component[k - 1][j].Type == 1)
//                    {
////                            QLabel *label = new QLabel;
////                            set_col(label,"_2_left_up.png");
////                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
//                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_up.png",name);
//                    }
//                    if(j != 0 && programs[temp].network[i].component[k][j - 1].Type == 2 && programs[temp].network[i].component[k - 1][j].Type == 1)
//                    {
////                            QLabel *label = new QLabel;
////                            set_col(label,"_2_left_up.png");
////                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
//                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_up.png",name);
//                    }
////                    if(k == 6)
////                    {
////                        QLabel *label = new QLabel;
////                        set_col(label,"_2.png");
////                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, 10),label);
////                    }


//                }

                if(programs[temp].network[i].component[k][j].Type == 1)//横线
                {

                    if(k>=2 && programs[temp].network[i].component[k][j].Data0 == 2 && programs[temp].network[i].component[k - 1][j].Data0 != 2)
                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,"_1_left_down.png");
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_1_left_down.png",name);
                    }

                    else
                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,"_1.png");
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label); //table右移一列，额外+1
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_1.png",name);
                    }
                }



                if(programs[temp].network[i].component[k][j].Type == 2)//竖线
                {
                    if(programs[temp].network[i].component[k - 1][j].Type == 1)
                    {
                        if(j != 0 && programs[temp].network[i].component[k][j - 1].Data0 == 2)
                        {
//                            QLabel *label = new QLabel;
//                            set_col(label,"_2_left_updown.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_updown.png",name);
                        }

                        else if(j != 0 && programs[temp].network[i].component[k][j - 1].Type == 2)
                        {
//                            QLabel *label = new QLabel;
//                            set_col(label,"_2_left_updown.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_updown.png",name);
                        }
                        else
                        {
//                            QLabel *label = new QLabel;
//                            set_col (label,"_2_left_down.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_down.png",name);
                        }
                    }

                }



                if(programs[temp].network[i].component[k][j].Type == 3)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 &&
                                (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,"_62.png");
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label); //table右移一列，额外+1
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_62.png",name);
                    }
                    if(j>=1)//两个并联情况
                    {
                        if(k==0)
                        {
                            if(programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_66.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_66.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_68.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_68.png",name);
                            }
                        }
//                        else if(k==7)
//                        {
//                            if(programs[temp].network[i].component[k][j-1].Data0==2)
//                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"6.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"7.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                            }
//                        }
                        if(k!=0 && k!=7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2 &&
                                    (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_65.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_65.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_63.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_63.png",name);
                            }
                        }
                    }
                    if(j>=2)//三个并联情况
                    {
                        if(k==0)
                        {
                           if((programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)&&
                                   (programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))
                           {
//                               QLabel *label1 = new QLabel;
//                               set_col(label1,"_67.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                               SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_67.png",name);
//                               QLabel *label2 = new QLabel;
//                               set_col(label2,"_68.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                               SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_68.png",name);
                           }
                        }
//                        else if(k==7)
//                        {
//                            if(programs[temp].network[i].component[k][j-1].Data0==2 && programs[temp].network[i].component[k][j-2].Data0==2)
//                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"8.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"7.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                            }
//                        }
                        if(k!=0 && k!=7)
                        {
                            if((programs[temp].network[i].component[k][j-2].Data0==2 &&
                                (programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))&&
                                    (programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_64.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_64.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_63.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_63.png",name);
                            }
                        }
                    }
                }
                if(programs[temp].network[i].component[k][j].Type == 4)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,"_69.png");
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label); //table右移一列，额外+1
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_69.png",name);
                    }
                    if(j>=1)//两个并联情况
                    {
                        if(k==0)
                        {
                            if(programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_72.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_72.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_70.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_70.png",name);
                            }
                        }
//                        else if(k==7)
//                        {
//                            if(programs[temp].network[i].component[k][j-1].Data0==2)
//                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_42.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_40.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                            }
//                        }
                        if(k!=0 && k!=7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_73.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_73.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_75.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_75.png",name);
                            }
                        }
                    }
                    if(j>=2)//三个并联情况
                    {
                        if(k==0)
                        {
                           if((programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)&&(programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))
                           {
//                               QLabel *label1 = new QLabel;
//                               set_col(label1,"_71.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                               SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_71.png",name);
//                               QLabel *label2 = new QLabel;
//                               set_col(label2,"_70.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                               SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_70.png",name);
                           }
                        }
//                        else if(k==7)
//                        {
//                            if(programs[temp].network[i].component[k][j-1].Data0==2 && programs[temp].network[i].component[k][j-2].Data0==2)
//                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_38.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_40.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                            }
//                        }
                        if(k!=0 && k!=7)
                        {
                            if((programs[temp].network[i].component[k][j-2].Data0==2 && (programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))&&(programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_74.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_74.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_75.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_75.png",name);
                            }
                        }
                    }
                }
                if(programs[temp].network[i].component[k][j].Type == 5)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,"_29.png");
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label); //table右移一列，额外+1
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_29.png",name);
                    }
                    if(j>=1)//两个并联情况
                    {
//                        if(k==0)
//                        {
//                            if(programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)
//                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_66.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_68.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                            }
//                        }
                        if(k==7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2)
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_42.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_42.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_40.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_40.png",name);
                            }
                        }
                        if(k!=0 && k!=7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_35.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_35.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_36.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_36.png",name);
                            }
                        }
                    }
                    if(j>=2)//三个并联情况
                    {
//                        if(k==0)
//                        {
//                           if((programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)&&(programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))
//                           {
//                               QLabel *label1 = new QLabel;
//                               set_col(label1,"_67.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                               QLabel *label2 = new QLabel;
//                               set_col(label2,"_68.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                           }
//                        }
                        if(k==7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2 && programs[temp].network[i].component[k][j-2].Data0==2)
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_38.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_38.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_40.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_40.png",name);
                            }
                        }
                        if(k!=0 && k!=7)
                        {
                            if((programs[temp].network[i].component[k][j-2].Data0==2 && (programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))&&(programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_101.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_101.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_36.png",name);
                            }
                        }
                    }
                }
                if(programs[temp].network[i].component[k][j].Type == 6)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,);
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label); //table右移一列，额外+1
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_90.png",name);
                    }
                    if(j>=1)//两个并联情况
                    {
//                        if(k==0)
//                        {
//                            if(programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)
//                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,"_66.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,"_68.png");
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                            }
//                        }
                        if(k==7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2)
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_96.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_94.png",name);
                            }
                        }
                        if(k!=0 && k!=7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_91.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_93.png",name);
                            }
                        }
                    }
                    if(j>=2)//三个并联情况
                    {
//                        if(k==0)
//                        {
//                           if((programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)&&(programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))
//                           {
//                               QLabel *label1 = new QLabel;
//                               set_col(label1,"_67.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
//                               QLabel *label2 = new QLabel;
//                               set_col(label2,"_68.png");
//                               ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
//                           }
//                        }
                        if(k==7)
                        {
                            if(programs[temp].network[i].component[k][j-1].Data0==2 && programs[temp].network[i].component[k][j-2].Data0==2)
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_95.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_94.png",name);
                            }
                        }
                        if(k!=0 && k!=7)
                        {
                            if((programs[temp].network[i].component[k][j-2].Data0==2 && (programs[temp].network[i].component[k+1][j-2].Data0==2 || programs[temp].network[i].component[k+1][j-2].Type==2))&&(programs[temp].network[i].component[k][j-1].Data0==2 && (programs[temp].network[i].component[k+1][j-1].Data0==2 || programs[temp].network[i].component[k+1][j-1].Type==2)))
                            {
//                                QLabel *label1 = new QLabel;
//                                set_col(label1,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j-1, k + 1 + 1),label1); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_92.png",name);
//                                QLabel *label2 = new QLabel;
//                                set_col(label2,);
//                                ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label2); //table右移一列，额外+1
                                SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_93.png",name);
                            }
                        }
                    }
                }
//                else if(Networks[i].component[j][k].Type == 33)
//                {

//                }
                //特殊元器件（简单类型）
                if(programs[temp].network[i].component[k][j].Type >=  32 && programs[temp].network[i].component[k][j].Type <=  38)//SET,CALL,RST,DIFU,DIFD,ALT
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_111.png",name);
                    }
                    if(programs[temp].network[i].component[k][j].Data0 == 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_114.png",name);
                    }
                    if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 != 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_112.png",name);
                    }
                    if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 == 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_113.png",name);
                    }
                }

            }
        }
        cnt_passrow += programs[temp].network[i].component[0].size() + 1;
    }
}

void MainWindow::load_ld2(int temp = 0)
{

    //额外一列 + 左导轨 + 8 + 右导轨 + 1（留空白）= 12
    standItemModel = new QStandardItemModel();
    standItemModel->setColumnCount(12);
    ui->tableView->setModel(standItemModel);

    int cnt_leftpowerline = 0;

    for(int i = 0 ;i < programs[temp].network.size() ; i ++)
    {
//        取消了额外加一行，改成j<= -江海涛
//        SetItem(standItemModel,cnt_leftpowerline);
//        cnt_leftpowerline ++;

        for(int j = 0;j <= programs[temp].network[i].component[0].size();j ++,cnt_leftpowerline ++)
        {
//            QStandardItem *standItem0;
//            if(j == 0)
//            {
//                standItem0 = new QStandardItem(QString::number(i+1));
//            }
//            else
//            {
//                standItem0 = new QStandardItem();
//            }

            SetItem(standItemModel,cnt_leftpowerline);

            //standItem0->setBackground(QColor (0, 152, 227, 255));
//            standItem0->setSelectable(0);
//            standItem0->setEditable(0);

            QString sl,sr ;
            sl = "_left.png";
            sr = "_right.png";
            if(j == 0)
            {
                sl = "_nleft.png";
                sr = "_nright.png";
            }
            //1 col
            QLabel *label = new QLabel;
            set_col(label,sl);
            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_leftpowerline, 1),label);

            //10 col
            QLabel *label2 = new QLabel;
            set_col(label2,sr);
            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_leftpowerline, 10),label2);
        }

    }
    aRow = cnt_leftpowerline;

    ui->tableView->setModel(standItemModel);

    for(int i = 0 ; i <= cnt_leftpowerline ; i ++)
    {
        if(i == 0)
        {
            ui->tableView->setColumnWidth(i,this->size().width()/36);
        }
        else
        {
            ui->tableView->setColumnWidth(i,this->size().width()/12);
        }
    }
    for(int i = 0 ; i < cnt_leftpowerline;i ++)

    {
        ui->tableView->setRowHeight(i,this->size().width()/24);
    }


    int cnt_passrow = 0;
    cnt_passrow++;
    QString name;

    for(int i = 0 ; i < programs[temp].network.size() ; i ++)
    {
        QLabel *label = new QLabel;
        label->setText(QString("network %1").arg(i+1));
        ui->tableView->setIndexWidget(standItemModel->index(cnt_passrow-1, 2),label);
        QLabel *label2 = new QLabel;
        label2->setText(programs[temp].network[i].comment.toUtf8().data());
        ui->tableView->setIndexWidget(standItemModel->index(cnt_passrow-1,3),label2);
        for(int j = 0 ; j < programs[temp].network[i].component[0].size() ; j ++)
        {
            for(int k = 0 ; k < 8 ; k ++)
            {
                name = programs[temp].network[i].component[k][j].Name;

                if(k == 0 && programs[temp].network[i].component[k][j].Type == 0)
                {
                    QLabel *label = new QLabel;
                    set_col(label,"_nleft.png");
                    ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1),label);
                }

                if(k == 7 && programs[temp].network[i].component[k][j].Type == 0)
                {
                    QLabel *label = new QLabel;
                    set_col(label,"_nright.png");
                    ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 3),label);
                }
//                if(programs[temp].network[i].component[k][j].Type == 0)
//                {

//                    if(j != 0 && programs[temp].network[i].component[k][j - 1].Data0 == 2 && programs[temp].network[i].component[k - 1][j].Type == 1)
//                    {
//                           QLabel *label = new QLabel;
//                           set_col(label,"_2_left_up.png");
//                           ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
//                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_up.png",name);
//                    }
//                    if(j != 0 && programs[temp].network[i].component[k][j - 1].Type == 2 && programs[temp].network[i].component[k - 1][j].Type == 1)
//                    {
//                            QLabel *label = new QLabel;
//                           set_col(label,"_2_left_up.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
//                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_up.png",name);
//                    }
//                    if(k == 6)
//                    {
//                        QLabel *label = new QLabel;
//                        set_col(label,"_2.png");
//                        ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, 10),label);
//                    }


 //               }

                if(programs[temp].network[i].component[k][j].Type == 1)//横线
                {

                    if(j>=1 && k>=1 && programs[temp].network[i].component[k+1][j-1].Data0 == 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_88.png",name);
                    }

                    else
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_1.png",name);
                    }
                }



                if(programs[temp].network[i].component[k][j].Type == 2)//竖线
                {
                    if(programs[temp].network[i].component[k - 1][j].Type == 1)
                    {
                        if(j != 0 && programs[temp].network[i].component[k][j - 1].Data0 == 2)
                        {
//                            QLabel *label = new QLabel;
//                            set_col(label,"_2_left_updown.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_updown.png",name);
                        }

                        else if(j != 0 && programs[temp].network[i].component[k][j - 1].Type == 2)
                        {
//                            QLabel *label = new QLabel;
//                            set_col(label,"_2_left_updown.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_updown.png",name);
                        }
                        else
                        {
//                            QLabel *label = new QLabel;
//                            set_col (label,"_2_left_down.png");
//                            ui->tableView->setIndexWidget(this->standItemModel->index(cnt_passrow + j, k + 1 + 1),label);
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_2_left_down.png",name);
                        }
                    }

                }



                if(programs[temp].network[i].component[k][j].Type == 3)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 &&
                                (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_62.png",name);
                    }
                    if(k!=7)
                    {
                        if(programs[temp].network[i].component[k+1][j].Data0==2 && programs[temp].network[i].component[k][j].Data0!=2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_66.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k+1][j].Type==2 && programs[temp].network[i].component[k][j].Data0!=2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_67.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k+1][j].Type!=2 && (programs[temp].network[i].component[k+1][j-1].Type==2 || programs[temp].network[i].component[k+1][j-1].Data0==2))
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_68.png",name);
                        }
                    }
                    if(k!=0 && k!=7)
                    {
                        if(programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_65.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Type==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_64.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j-1].Data0==2 && programs[temp].network[i].component[k][j].Data0!=2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_63.png",name);
                        }
                     }
                }
                if(programs[temp].network[i].component[k][j].Type == 4)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 &&
                                (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_69.png",name);
                    }
                    if(k!=7)
                    {
                        if(programs[temp].network[i].component[k+1][j].Data0==2 && programs[temp].network[i].component[k][j].Data0!=2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_72.png",name);

                        }
                        if(j>=1 && programs[temp].network[i].component[k+1][j].Type==2 && programs[temp].network[i].component[k][j].Data0!=2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_71.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k+1][j].Type!=2 && (programs[temp].network[i].component[k+1][j-1].Type==2 || programs[temp].network[i].component[k+1][j-1].Data0==2))
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_70.png",name);
                        }
                    }
                    if(k!=0 && k!=7)
                    {
                        if(programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_73.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Type==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_74.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j-1].Data0==2 && programs[temp].network[i].component[k][j].Data0!=2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_75.png",name);
                        }
                     }
                }
                if(programs[temp].network[i].component[k][j].Type == 5)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_29.png",name);
                    }
                    if(k==7)
                    {
                        if(programs[temp].network[i].component[k][j].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_42.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 != 2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_40.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 == 2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_38.png",name);
                        }
                    }
                    if(k!=0 && k!=7)
                    {
                        if(programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_35.png",name);
                        }
                        if(programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Type==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_101.png",name);
                        }
                        if(programs[temp].network[i].component[k][j-1].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_36.png",name);
                        }
                    }
                }
                if(programs[temp].network[i].component[k][j].Type == 6)
                {
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_90.png",name);
                    }
                    if(k==7)
                    {
                        if(programs[temp].network[i].component[k][j].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_96.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 != 2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_94.png",name);
                        }
                        if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 == 2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_95.png",name);
                        }
                    }
                    if(k!=0 && k!=7)
                    {
                        if(programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_91.png",name);
                        }
                        if(programs[temp].network[i].component[k][j].Data0==2 && programs[temp].network[i].component[k+1][j].Type==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_92.png",name);
                        }
                        if(programs[temp].network[i].component[k][j-1].Data0==2)
                        {
                            SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_93.png",name);
                        }
                    }
                }
                //特殊元器件（简单类型）
                if(programs[temp].network[i].component[k][j].Type >=  32 && programs[temp].network[i].component[k][j].Type <=  38)//SET,CALL,JMPB,RST,DIFU,DIFD,ALT
                {
                    int t = programs[temp].network[i].component[k][j].Type;
                    QString cn[7] = {"STT","CALL","JMPB","RST","DIFU","DIFD","ALT"};
                    if(j==0 || (programs[temp].network[i].component[k][j-1].Data0!=2 && (programs[temp].network[i].component[k+1][j-1].Data0!=2 && programs[temp].network[i].component[k+1][j-1].Type!=2)))
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_111.png",name,cn[t-32]);
                    }
                    if(programs[temp].network[i].component[k][j].Data0 == 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_114.png",name,cn[t-32]);
                    }
                    if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 != 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_112.png",name,cn[t-32]);
                    }
                    if(j>=1 && programs[temp].network[i].component[k][j-1].Data0 == 2 && programs[temp].network[i].component[k][j].Data0 == 2)
                    {
                        SetLabel(standItemModel,ui,cnt_passrow + j,k+2,"_113.png",name,cn[t-32]);
                    }
                }

            }
        }
        cnt_passrow += programs[temp].network[i].component[0].size() + 1;
    }

    //standItemModel->setItemData();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setShowGrid(false);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->verticalHeader()->setVisible(false);
}

void MainWindow::on_pushButton_9_clicked()
{

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    // ui->tableView->setIndexWidget(this->standItemModel->index(i, j),label);
}


void MainWindow::on_pushButton_11_clicked()//编辑状态
{
    QObject::connect(this->ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slot_start_window()));
    click_status = EditMode;//状态改变为编辑状态
    ui->pushButton_3->setStyleSheet(0);//恢复颜色
    ui->pushButton_2->setStyleSheet(0);
    ui->pushButton_4->setStyleSheet(0);
    ui->pushButton_3->setText("LD");
    ui->pushButton_2->setText("OUT");
    ui->pushButton_4->setText("横线");
    ui->pushButton_5->setText("并联接LD,OUT");
    ui->pushButton_6->setText("LD与OUT取反");
    ui->pushButton_7->setText("删除");
    ui->button_open->setText("返回");
    ui->pushButton_12->setText(" ");
    ui->pushButton_11->setText("常用指令");
    ui->pushButton_10->setText("网络/行操作");
    ui->pushButton_13->setText("功能指令");
    ui->pushButton_16->setText(" ");
    ui->pushButton_14->setText("增加/删除竖线");
    ui->pushButton_9->setText(" ");
}

void MainWindow::on_pushButton_3_clicked()//工程模式为一级程序，编辑模式中常用指令为LD，网络/行操作为向下添加行，功能指令为
{
    if(click_status == DefaultSet)
    {
        Jobnumber = 0;
        this->load_ld2(Jobnumber);
        ui->pushButton_3->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        ui->pushButton_2->setStyleSheet(0);
        ui->pushButton_4->setStyleSheet(0);
    }
    else if(click_status == EditMode)
    {
        AddLD(row,colunm);//增加LD
        MainWindow::reFreshLd2(Jobnumber);
    }
    else if(click_status == NetworkOperat)
    {
        AddRowNext(row);//向下增加行
        MainWindow::reFreshLd2(Jobnumber);
    }
    else if(click_status == Displacement)
    {
        qDebug("ROTB");
        qDebug() << row << " " << colunm;
    }
}


void MainWindow::on_pushButton_2_clicked()//默认为二级程序,编辑模式中常用指令为OUT,网络模式为向下添加网络,功能指令为位移/旋转
{
    if(click_status == DefaultSet)
    {
        Jobnumber = 1;
        this->load_ld2(Jobnumber);
        ui->pushButton_2->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        ui->pushButton_3->setStyleSheet(0);
        ui->pushButton_4->setStyleSheet(0);
    }
    else if(click_status == Engineering)
    {

    }
    else if(click_status == EditMode)
    {
        AddOUT(row,colunm);//增加OUT
        MainWindow::reFreshLd2(Jobnumber);
    }
    else if(click_status == NetworkOperat)
    {
        AddNetNext(row);//向下增加网络
        MainWindow::reFreshLd2(Jobnumber);
    }
    else if(click_status == Functional)
    {
        ui->pushButton_3->setText("ROTB");
        ui->pushButton_2->setText("WSHL");
        ui->pushButton_4->setText("WSHR");
        ui->pushButton_5->setText(" ");
        ui->pushButton_6->setText(" ");
        ui->pushButton_7->setText(" ");
        ui->button_open->setText("返回");
        click_status = Displacement;
    }
    else if(click_status == Displacement)
    {
        qDebug("WSHL");
        qDebug() << row << " " << colunm;
    }
}

void MainWindow::on_pushButton_4_clicked()//默认模式为子级程序，编辑模式为添加横线，网络/行为向上添加行
{
    if(click_status == DefaultSet)
    {
        Jobnumber = 2;
        this->load_ld2(Jobnumber);
        ui->pushButton_4->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
        ui->pushButton_3->setStyleSheet(0);
        ui->pushButton_2->setStyleSheet(0);
    }
    else if(click_status == EditMode)
    {
        AddLine(row,colunm);//增加Line
        MainWindow::reFreshLd2(Jobnumber);
    }
    else if(click_status == Displacement)
    {
        qDebug("WSHR");
        qDebug() << row << " " << colunm;
    }
    else if(click_status == NetworkOperat)
    {
        AddRowBefore(row);//向上增加行
        MainWindow::reFreshLd2(Jobnumber);
    }
}

void MainWindow::on_pushButton_5_clicked()//编辑模式为并联,网络/行向上添加网络
{
    if(click_status == EditMode)
    {
        Parallel(row,colunm);//并联
        MainWindow::reFreshLd2(Jobnumber);
    }
    else if(click_status == NetworkOperat)
    {
        AddNetBefore(row);//向上增加网络
        MainWindow::reFreshLd2(Jobnumber);
    }
}

void MainWindow::on_pushButton_7_clicked()//编辑模式为删除,网络/行删除网络
{
    if(click_status == EditMode)
    {
        DeletNow(row,colunm);//删除当前元件
        MainWindow::load_ld2(Jobnumber);
    }
    else if(click_status==Engineering)
    {
        QStandardItemModel *standItemModel;
                ui->treeView->hide();//隐藏其他控件
                ui->tableView->hide();
                ui->tableView_2->show();//显示表格控件

                standItemModel = new QStandardItemModel();
                standItemModel->setColumnCount(4);
                standItemModel->setHeaderData(0,Qt::Horizontal,QStringLiteral("地址"));//设置表头内容
                standItemModel->setHeaderData(1,Qt::Horizontal,QStringLiteral("指令名"));
                standItemModel->setHeaderData(2,Qt::Horizontal,QStringLiteral("模块"));
                standItemModel->setHeaderData(3,Qt::Horizontal,QStringLiteral("位置"));
                ui->tableView_2->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

                int tempI = 0;//记录表格行数
                for(int p = 0;p < programs.size();p ++)//向表格添加内容
                {
                    int tempR = 0;//记录这个程序的总行数
                    for(int i = 0;i < programs[p].network.size();i ++)
                    {

                        for(int j = 0;j < programs[p].network[i].component[0].size();j ++)
                        {
                            for(int k = 0;k < 8;k ++)
                            {
                                if(programs[p].network[i].component[k][j].Type > 2)
                                {
                                    QStandardItem *standItem1 = new QStandardItem(programs[p].network[i].component[k][j].Name);
                                    QString ch;
                                    if(programs[p].network[i].component[k][j].Type == 3)
                                    {
                                        ch = "LD";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 4)
                                    {
                                        ch = "LDI";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 5)
                                    {
                                        ch = "OUT";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 6)
                                    {
                                        ch = "OUTN";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 23)
                                    {
                                        ch = "SPE";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 32)
                                    {
                                        ch = "SET";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 33)
                                    {
                                        ch = "CALL";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 35)
                                    {
                                        ch = "RST";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 36)
                                    {
                                        ch = "DIFU";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 37)
                                    {
                                        ch = "DIFD";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 41)
                                    {
                                        ch = "MOVN";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 42)
                                    {
                                        ch = "CMP";
                                    }
                                    else if(programs[p].network[i].component[k][j].Type == 43)
                                    {
                                        ch = "DECB";
                                    }
                                    QStandardItem *standItem2 = new QStandardItem(ch);
                                    QStandardItem *standItem3 = new QStandardItem(programs[p].name);
                                    QString ch1 = QString("R%1,C%2,网络%3").arg(tempR).arg(k).arg(i);

                                    QStandardItem *standItem4 = new QStandardItem(ch1);
                                    standItemModel->setItem(tempI,0,standItem1); //表格第i行，第0列添加一项内容
                                    standItemModel->item(tempI,0)->setTextAlignment(Qt::AlignCenter);//设置表格内容居中

                                    standItemModel->setItem(tempI,1,standItem2); //表格第i行，第1列添加一项内容
                                    standItemModel->item(tempI,1)->setTextAlignment(Qt::AlignCenter);//设置表格内容居中

                                    standItemModel->setItem(tempI,2,standItem3); //表格第i行，第2列添加一项内容
                                    standItemModel->item(tempI,2)->setTextAlignment(Qt::AlignCenter);//设置表格内容居中

                                    standItemModel->setItem(tempI,3,standItem4); //表格第i行，第3列添加一项内容
                                    standItemModel->item(tempI,3)->setTextAlignment(Qt::AlignCenter);//设置表格内容居中
                                    tempI++;
                                }
                            }
                        tempR++;
                        }
                    }
                }

                ui->tableView_2->setModel(standItemModel);//挂载表格模型
                ui->tableView_2->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//表头信息显示居中
                ui->tableView_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);//设定表头弹性拉伸
                ui->tableView_2->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
                ui->tableView_2->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
                ui->tableView_2->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
                ui->tableView_2->setColumnWidth(0,100);//设定表格第0列宽度
                ui->tableView_2->setColumnWidth(1,100);
                ui->tableView_2->setColumnWidth(2,300);
                ui->tableView_2->setColumnWidth(3,300);
                ui->tableView_2->verticalHeader()->hide();//隐藏默认显示的行头
                ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中时整行选中
                ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格属性只读，不能编辑
    }
    else if(click_status == NetworkOperat)
    {
        d_net();//删除网络
        MainWindow::load_ld2(Jobnumber);
    }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    cout << index.row() << ' ' << index.column() << endl;
    row = index.row();
    colunm = index.column();
}

void MainWindow::on_pushButton_14_clicked()//编辑模式下为竖线
{
    if(click_status == EditMode)
    {
        VerticalBar(row,colunm);//增加/删除竖线
    }
}


void MainWindow::on_pushButton_16_clicked()
{

}

void MainWindow::on_pushButton_12_clicked()//工程管理
{

    click_status = Engineering;
    ui->pushButton_3->setStyleSheet(0);//恢复颜色
    ui->pushButton_2->setStyleSheet(0);
    ui->pushButton_4->setStyleSheet(0);
    ui->pushButton_3->setText("梯图选择\n通道1");
    ui->pushButton_2->setText("打开梯图\n通道1");
    ui->pushButton_4->setText("U盘导入\n通道1");
    ui->pushButton_5->setText("导至U盘\n通道1");
    ui->pushButton_6->setText("程序版本\n信息");
    ui->pushButton_3->setEnabled(false);//关闭控件
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_7->setText("引用\n索引列表");
    ui->pushButton_16->setText("");
    ui->button_open->setText("返回");
    ui->pushButton_12->setStyleSheet("background-color: rgb(0, 170, 255)");//设置颜色
    ui->treeView->show();
    ui->tableView_2->hide();
    ui->treeView->setEditTriggers(0);//将节点设置为不可编辑
    for(int i=0;i<11;i++)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);//显示窗口设置为可变
    }
    QStandardItemModel *model = new QStandardItemModel(ui->treeView);//创建模型
    ui->treeView->setModel(model);//导入模型
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("项目名"));//添加表头
    QStandardItem* itemProject1 = new QStandardItem("一级程序");//添加根节点
    model->setItem(0,0,itemProject1);
    QStandardItem* itemProject2 = new QStandardItem("二级程序");
    model->setItem(1,0,itemProject2);
    QStandardItem* itemProject3 = new QStandardItem("子程序");
    model->setItem(2,0,itemProject3);
    QStandardItem *itemChild1 = new QStandardItem(programs[0].name);//添加一级程序子节点，默认为一个
    itemProject1->appendRow(itemChild1);
    QStandardItem *itemChild2 = new QStandardItem(programs[1].name);//添加二级程序子节点，默认为一个
    itemProject2->appendRow(itemChild2);
    for(int i = 2;i < programs.size();i ++)//添加子程序子节点
    {
        QStandardItem *itemChild3 = new QStandardItem(programs[i].name);
        itemProject3->appendRow(itemChild3);
    }
    connect(ui->treeView,SIGNAL(pressed(QModelIndex)),this,SLOT(slot_treeView_pressed(QModelIndex)));
}

void MainWindow::slot_treeView_pressed(QModelIndex Index)//读取树状图点击的文件
{
    QAbstractItemModel* m=(QAbstractItemModel*)Index.model();
    for(int columnIndex = 0; columnIndex < m->columnCount(); columnIndex++)
    {
         if(Index.parent().data().toString()=="一级程序")
             this->load_ld2(1);
         else if(Index.parent().data().toString()=="二级程序")
             this->load_ld2(2);
         else if(Index.parent().data().toString()=="子程序")
             this->load_ld2(Index.row()+3);
    }
}
void MainWindow::on_pushButton_10_clicked()//默认状态为数据列表，编辑模式为网络/行操作
{
    if(click_status == DefaultSet)
    {
        click_status = DataList;
        ui->pushButton_16->setText(" ");
        ui->pushButton_14->setText(" ");
        ui->pushButton_9->setText(" ");
    }
    else if(click_status == EditMode || click_status == Functional)
    {
        click_status = NetworkOperat;
        ui->pushButton_3->setText("向下添加行");
        ui->pushButton_2->setText("向下添加网络");
        ui->pushButton_4->setText("向上添加行");
        ui->pushButton_5->setText("向上添加网络");
        ui->pushButton_6->setText("删除行");
        ui->pushButton_7->setText("删除网络");
        ui->button_open->setText("返回");
    }
}

void MainWindow::on_pushButton_13_clicked()//默认状态为状态列表，编辑模式为功能指令
{
    if(click_status == DefaultSet)
    {
        click_status = StateList;
        ui->pushButton_16->setText(" ");
        ui->pushButton_14->setText(" ");
        ui->pushButton_9->setText(" ");
    }
    else if(click_status == EditMode || click_status == NetworkOperat)
    {
        click_status = Functional;
        ui->pushButton_3->setText("数学运算");
        ui->pushButton_2->setText("位移/旋转");
        ui->pushButton_4->setText("定时/计数");
        ui->pushButton_5->setText("符号/跳跃");
        ui->pushButton_6->setText("位输出");
        ui->pushButton_7->setText(" ");
        ui->button_open->setText("返回");
    }
}
