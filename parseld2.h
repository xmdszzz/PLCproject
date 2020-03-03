#ifndef PARSELD2_H
#define PARSELD2_H

#include "newstruct.h"
#include "stdio.h"
#include <iostream>


#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <sys/types.h>
#include <QDebug>

#define LEN_HEADER			56
#define LITTLE_END          1
#define BIG_END             0

typedef char				INT8;
typedef int					INT32;
typedef short				INT16;
typedef unsigned char		INT8U;
typedef unsigned short		INT16U;
typedef unsigned int		INT32U;



    //类型30~75根据以下结构来读取
    typedef struct
    {
        INT8U	 Type;  // CELL Style
        INT8U    Data0; // =2则为前方有竖线
        INT8U    Data1; //0=0组1=1组2=2组参数
        INT8U    Data2; //02=无首字符 01=有首字符
        INT32U   Data3; //前面2byte为数字，第3byte为小数点后的数字，第4byte低6位为字符，高七位为1表示有小数，为0表示无小数。
    } Cell_standard;

    class Network
    {
    public:
        int row;
        Cell_standard component[100][8];
        QString VarName[100][8];
    };

    extern Network network;

typedef struct        //fixed 5bytes
{
    INT8U head;        // Judge by head
    INT32U length;
}LD_SIZE;

typedef struct		  //unfixed
{
    LD_SIZE size;
    char *pstring;   //malloc(head) or malloc(length)
}LD_STRING;


//ld2的文件头 56bytes
typedef struct
{
    INT32U	type;				//类型
    INT32U	version;			//版本
    INT32U	headSize;			//文件头大小
    INT32U	fileSize;			//文件大小
    INT32U	blocks;				//程序块个数
    INT32U  offsetLadderInfo;   //梯图信息偏移量
    INT32U	offsetSymbolTable;	//符号表数据偏移量
    INT32U	offsetLadData;		//梯图数据偏移量
    INT32U	offsetInitDataTable;//初始数据表偏移量
    INT32U	offsetMessage;		//报警信息表
    INT16U  crc16;              //CRC16 校验码
    INT16U  reserved1;          //预留
    INT32   reserved2;          //预留
    INT32   reserved3;          //预留
    INT32   reserved4;          //预留
}LADFILEHEADER;

//梯图信息
typedef struct
{
    LD_STRING	psDesigner;		//设计者
    LD_STRING	psVersion;		//程序版本号
    LD_STRING	psComment;		//备注
}LADDERINFO;


//数据块头
typedef struct
{
    INT32U	type;							//类型
    INT32U	spAddr;						//子程序地址32bit数
    INT32U	headSize;						//头大小
    INT32U	blocktype;					//程序块类型
    LD_STRING	*psBlockName;				//程序块名称
    LD_STRING	*psDesigner;				//设计者
    LD_STRING	*psVersion;				//程序版本号
    LD_STRING	*psComment;				//备注
    INT32   reserved1,reserved2;		//预留
    INT32   reserved3,reserved4;		//预留
}LADBLOCKDATAHEADER;


#define LADBLOCK_LEVEL1     1		//1级程序
#define LADBLOCK_LEVEL2     2		//2级程序
#define LADBLOCK_SUB        3		//子级程序


typedef struct
{
    INT8U	Type;	// CELL Style=0 or 1 or 2
    INT8U	Data0; // =2则为前方有竖线
} Cell_type1;

//类型3~6根据以下结构来读取
typedef struct
{
    INT8U	Type;  // CELL Style
    INT8U	Data0; // =2则为前方有竖线
    INT8U	Data1; //	0=0组1=1组2=2组参数
    INT32	Data2; //前面2byte为数字，第3byte为小数点后的数字，第4byte低6位为字符，高七位为1表示有小数，为0表示无小数。
} Cell_type2;

//类型30~75根据以下结构来读取
typedef struct
{
    INT8U	Type;  // CELL Style
    INT8U    Data0; // =2则为前方有竖线
    INT8U    Data1; //0=0组1=1组2=2组参数
    INT8U   Data2; //02=无首字符 01=有首字符
    INT32U   Data3; //前面2byte为数字，第3byte为小数点后的数字，第4byte低6位为字符，高七位为1表示有小数，为0表示无小数。
} Cell_type3;


typedef struct
{
    INT32U	nAddr;		//地址
    INT32	nData;		//设置值
    INT32	nMax; 		//最大允许值
    INT32	nMin; 		//最小允许值
}LdInitDataItem;



int checkCPU();
int GetFileSize(const char* path);
void read_all_context(char*& buffer,const char* path);
void Parse_LD_Context(char* context,char* ptr , int length);
LD_SIZE parse_ld_size(char*& current_ptr);
void print_ld_size(LD_SIZE size);
LD_STRING Parse_LD_STRING(char*& current_ptr);
LADFILEHEADER parse_plc_header(char* buffer);
void parse_LadderInfomation(char*& current_ptr);
void parse_ld_data(char*& current_ptr);
void parse_SymbolItem(char*& current_ptr);
void parse_init_table(char*& current_ptr);

void parse_ld2file(const char*path);

#endif // PARSELD2_H
