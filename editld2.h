#ifndef EDITLD2_H
#define EDITLD2_H

#include "newstruct.h"
#include "stdio.h"
#include <iostream>


#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <sys/types.h>
#include <QDebug>


int get_network_no(int &r_row);//获取当前网络数

void deleteALL_ld2();//删除整个ld2网络

void d_row(int r);//函数：删除选中元器件所在网络的所在行，行为传入参数

void d_net();//函数：删除选中元器件所在的网络

void TheNot(int NowRow,int NowColunm);//取反

void AddLD(int NowRow,int NowColunm);//增加LD

void AddOUT(int NowRow,int NowColunm);//增加OUT

void AddLine(int NowRow,int NowColunm);//增加Line

void DeletNow(int NowRow,int NowColunm);//删除当前元件

void AddRowNext(int NowRow);//向下增加行

void AddNetNext(int NowRow);//向下增加网络

void AddRowBefore(int NowRow);//向上增加行

void AddNetBefore(int NowRow);//向上增加网络

void Parallel(int NowRow,int NowColunm);//并联

void VerticalBar(int NowRow,int NowColunm);//增加/删除竖线

#endif // EDITLD2_H
