#ifndef NEWSTRUCT_H
#define NEWSTRUCT_H
#include "QList"
#include "QDebug"

typedef char				INT8;
typedef short				INT16;
typedef int					INT32;
typedef unsigned char		INT8U;
typedef unsigned short		INT16U;
typedef unsigned int		INT32U;


class SingleComponent {
   public:
      QString Name;
      INT8U	Type;	// CELL Style=0 or 1 or 2 , For TypeA,B,C
      INT8U	Data0;  // Data0=2则为前方有竖线 , For TypeA,B,C
      INT8U Data1;  //Data1=0为0组1=1组2=2组参数 , For TypeB,C
      QVarLengthArray<INT32U> Data2forB;  //前面2byte为数字，第3byte为小数点后的数字，第4byte低6位为字符，高七位为1表示有小数，为0表示无小数。For TypeB only
      QVarLengthArray<INT8U> Data2forC;  // 02=无首字符 01=有首字符 , For TypeC only
      QVarLengthArray<INT32U> Data3forC;  // 前面2byte为数字，第3byte为小数点后的数字，第4byte低6位为字符，高七位为1表示有小数，为0表示无小数。For TypeC only

      void SetName( QString input_Name)
      {
         Name = input_Name;
      }
      void SetBasis( INT8U input_Type=0, INT8U input_Data0=0)
      {
         Type = input_Type;
         Data0 = input_Data0;
      }
      void SetData1( INT8U input_Data1=0)
      {
         Data1 = input_Data1;
      }
      void SetExtraData2forB(INT8U pos, INT32U input_Data2forB=0)
      {

         if(pos > Data2forB.size())
         {
            qDebug("不可跨下标创建Data2forB");
         }
         else if(pos == Data2forB.size())
         {
             Data2forB.append(input_Data2forB);
         }
         else
         {
             Data2forB[pos] = input_Data2forB;
         }
      }
      void SetExtraData2forC(INT8U pos, INT8U input_Data2forC=0)
      {

         if(pos > Data2forC.size())
         {
            qDebug("不可跨下标创建Data2forC");
         }
         else if(pos == Data2forC.size())
         {
             Data2forC.append(input_Data2forC);
         }
         else
         {
             Data2forC[pos] = input_Data2forC;
         }
      }
      void SetExtraData3forC(INT8U pos, INT32U input_Data3forC=0)
      {

         if(pos > Data3forC.size())
         {
            qDebug("不可跨下标创建Data3forC");
         }
         else if(pos == Data3forC.size())
         {
             Data3forC.append(input_Data3forC);
         }
         else
         {
             Data3forC[pos] = input_Data3forC;
         }
      }
      void Reset2Blank()
      {
          Name.clear();
          Type = 0;
          Data0 = 0;
          Data1 = 0;
          Data2forB.clear();
          Data2forC.clear();
          Data3forC.clear();
      }


};



struct components
{
    QList<SingleComponent> component[8];   //列链表形式的元件表（存储单个网络的所有元件，列数=8，行数=QList.size
};

struct networks
{
    QString name;//程序名称
    QList<components> network;
};


#endif // NEWSTRUCT_H
