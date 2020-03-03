#pragma execution_character_set("utf-8")
#include "editld2.h"

#include "newstruct.h"
using namespace std;



//QList<components>networks;  //网络链表（存储多个网络）
extern QList<networks>programs;    //程序链表（存储多个程序）

extern int DefaultSet;//默认状态
extern int Engineering;//工程管理
extern int EditMode;//编辑模式
extern int DataList;//数据列表
extern int StateList;//状态列表
extern int NetworkOperat;//网络/行操作
extern int Functional;//功能指令
extern int Displacement;//位移/旋转
extern int Jobnumber;//工程编号，开始为0，第一个
extern const int Jobnumber_0;//工程编号，默认0
extern const int Jobnumber_1;//工程编号，默认1
extern const int Jobnumber_2;//工程编号，默认2

extern int click_status;//全局变量
extern int row,colunm;//光标所在的行列数


int get_network_no(int &r_row)//获取当前网络数
{
    int i = 0;
    r_row --;  //第一行
    while(1)
    {
        //cout << r_row <<" "<< i << endl;
        if(r_row < programs[Jobnumber].network[i].component[0].size())
        {
            return i;
        }
        r_row -= programs[Jobnumber].network[i].component[0].size();
        r_row --;
        i++;
    }
}

void deleteALL_ld2()//删除整个ld2网络
{
    SingleComponent *tmp1;
    components *tmp2;
    for(int i = programs[Jobnumber].network.size()-1; i >= 0; i--)
    {
        for(int k = programs[Jobnumber].network[i].component[0].size()-1; k >= 0; k--)
        {
            for(int j = 0; j < 8; j++)
            {
                tmp1 = &programs[Jobnumber].network[i].component[j][k];
                delete tmp1;
                programs[Jobnumber].network[i].component[j].removeAt(k);
            }
        }
        tmp2 = &programs[Jobnumber].network[i];
        delete tmp2;
        programs[Jobnumber].network.removeAt(i);
    }
}

void d_row(int r)//函数：删除选中元器件所在网络的所在行，行为传入参数
{
    int r_row = row;
    int i = get_network_no(r_row);
    SingleComponent *tmp;
    for(int j = 0; j < 8; j++)
    {
       tmp = &programs[Jobnumber].network[i].component[j][r];
       delete tmp;
       programs[Jobnumber].network[i].component[j].removeAt(r);
    }
}

void d_net()//函数：删除选中元器件所在的网络
{
    int r_row = row;
    int j = get_network_no(r_row);
    for(int i = 0; i < programs[Jobnumber].network[j].component[0].size(); i++)
    {
        d_row(i);
    }
    components *tmp;
    tmp = &programs[Jobnumber].network[j];
    delete tmp;
    programs[Jobnumber].network.removeAt(j);
}

void TheNot(int NowRow,int NowColunm)//取反
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1; //table右移一列，额外-1
    int i = get_network_no(r_row);
    int TypeNow;//记录所在的型号
    int Data0Now;//记录竖线
    TypeNow = programs[Jobnumber].network[i].component[r_colunm][r_row].Type;
    Data0Now = programs[Jobnumber].network[i].component[r_colunm][r_row].Data0;
    if(TypeNow == 3 || TypeNow == 5)
    {
        TypeNow = programs[Jobnumber].network[i].component[r_colunm][r_row].Type + 1;
    }
    else if(TypeNow == 4 || TypeNow == 6)
    {
        TypeNow = programs[Jobnumber].network[i].component[r_colunm][r_row].Type - 1;
    }
    programs[Jobnumber].network[i].component[r_colunm][r_row].Reset2Blank();
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetBasis(TypeNow,Data0Now);
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetData1(0);
}

void AddLD(int NowRow,int NowColunm)//增加LD
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1;//table右移一列，额外-1
    int i = get_network_no(r_row);
    programs[Jobnumber].network[i].component[r_colunm][r_row].Reset2Blank();
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetBasis(3,0);
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetData1(0);
}

void AddOUT(int NowRow,int NowColunm)//增加OUT
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1;//table右移一列，额外-1
    int i = get_network_no(r_row);
    programs[Jobnumber].network[i].component[r_colunm][r_row].Reset2Blank();
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetBasis(5,0);
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetData1(0);
}

void AddLine(int NowRow,int NowColunm)//增加Line
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1;//table右移一列，额外-1
    int i = get_network_no(r_row);
    programs[Jobnumber].network[i].component[r_colunm][r_row].Reset2Blank();
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetBasis(1,0);
}

void DeletNow(int NowRow,int NowColunm)//删除当前元件
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1;//table右移一列，额外-1
    int i = get_network_no(r_row);
    programs[Jobnumber].network[i].component[r_colunm][r_row].Reset2Blank();
    programs[Jobnumber].network[i].component[r_colunm][r_row].Data0 = 0;
    if(programs[Jobnumber].network[i].component[r_colunm + 1][r_row].Data0==2)
    {
        programs[Jobnumber].network[i].component[r_colunm + 1][r_row].Data0 = 0;
    }
    if(programs[Jobnumber].network[i].component[r_colunm + 1][r_row].Type==2)
    {
        programs[Jobnumber].network[i].component[r_colunm + 1][r_row].Type = 0;
    }
}

void AddRowNext(int NowRow)//向下增加行
{
    int r_row = NowRow;
    int i = get_network_no(r_row);
    for(int j = 0; j < 8; j++)
    {
        SingleComponent *tempSingleComponent = new SingleComponent;
        tempSingleComponent->Reset2Blank();
        programs[Jobnumber].network[i].component[j].append(*tempSingleComponent);
    }
}

void AddNetNext(int NowRow)//向下增加网络
{
    int r_row = NowRow;
    int i = get_network_no(r_row);
    cout << i << endl;
    components *tempcomponents = new components;
    for(int j = 0; j < 8; j++)
    {
        SingleComponent *tempSingleComponent = new SingleComponent;
        tempSingleComponent->Reset2Blank();
        tempcomponents->component[j].append(*tempSingleComponent);
    }
    programs[Jobnumber].network.insert(i+1,*tempcomponents);
}

void AddRowBefore(int NowRow)//向上增加行
{
    int r_row = NowRow;
    int i = get_network_no(r_row);
    for(int j = 0; j < 8; j++)
    {
        SingleComponent *tempSingleComponent = new SingleComponent;
        tempSingleComponent->Reset2Blank();
        //tempSingleComponent->SetBasis(1,0);
        programs[Jobnumber].network[i].component[j].insert(r_row,*tempSingleComponent);
    }
}

void AddNetBefore(int NowRow)//向上增加网络
{
    int r_row = NowRow;
    int i = get_network_no(r_row);
    cout << i << endl;
    components *tempcomponents = new components;
    for(int j = 0; j < 8; j++)
    {
        SingleComponent *tempSingleComponent = new SingleComponent;
        tempSingleComponent->Reset2Blank();
        tempcomponents->component[j].append(*tempSingleComponent);
    }
    programs[Jobnumber].network.insert(i,*tempcomponents);
}

void Parallel(int NowRow,int NowColunm)//并联
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1;//table右移一列，额外-1
    int i = get_network_no(r_row);
    int TypeNow;//记录所在的型号
    TypeNow = programs[Jobnumber].network[i].component[r_colunm][r_row - 1].Type;
    programs[Jobnumber].network[i].component[r_colunm][r_row].Reset2Blank();
    if(NowColunm==0)
    {
        if(programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Type!=2)
        {
            programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Data0 = 2;
        }
        else if(programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Data0==2 || programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Type==2)
        {
            programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Type = 2;
        }
    }
    else if(NowColunm==7)
    {
        programs[Jobnumber].network[i].component[r_colunm][r_row - 1].Data0 = 2;
    }
    else
    {
        programs[Jobnumber].network[i].component[r_colunm][r_row - 1].Data0 = 2;
        if(programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Type!=2)
        {
            programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Data0 = 2;
        }
        else if(programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Data0==2 || programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Type==2)
        {
            programs[Jobnumber].network[i].component[r_colunm + 1][r_row - 1].Type = 2;
        }
    }
    programs[Jobnumber].network[i].component[r_colunm][r_row].Type = TypeNow;
    programs[Jobnumber].network[i].component[r_colunm][r_row].SetData1(0);
}

void VerticalBar(int NowRow,int NowColunm)//增加/删除竖线
{
    int r_row = NowRow;
    int r_colunm = NowColunm - 1 - 1;//table右移一列，额外-1
    int i = get_network_no(r_row);
    if(programs[Jobnumber].network[i].component[r_colunm][r_row].Type!=0)
    {
        programs[Jobnumber].network[i].component[r_colunm][r_row].Data0 = 2;
    }
    if(programs[Jobnumber].network[i].component[r_colunm][r_row].Type==0)
    {
        programs[Jobnumber].network[i].component[r_colunm][r_row].Type = 2;
    }
    if(programs[Jobnumber].network[i].component[r_colunm][r_row].Data0==2)
    {
       programs[Jobnumber].network[i].component[r_colunm][r_row].Data0 = 0;
    }
    if(programs[Jobnumber].network[i].component[r_colunm][r_row].Type==2)
    {
        programs[Jobnumber].network[i].component[r_colunm][r_row].Type=0;
    }
}
