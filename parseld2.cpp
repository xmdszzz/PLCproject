//#pragma execution_character_set("utf-8")
#include "parseld2.h"
#include <iostream>
#include "newstruct.h"
using namespace std;

int cpu_mdl;


//QList<components>networks;  //网络链表（存储多个网络）
QList<networks>programs;    //程序链表（存储多个程序）

//判断大小端，小端返回TRUE,大端返回FALSE
int checkCPU()
{
    union w
    {
        int a;
        char b;
    }c;
    c.a = 1;
return (c.b == 1);
}


//读取文件的大小，返回文件占的字节数
int GetFileSize(const char* path)
{
    ifstream t;
    int length;
    t.open(path, ios::in | ios::binary);      // open input file
    t.seekg(0, std::ios::end);    // go to the end
    length = t.tellg();           // report location (this is the length)
    cout << "the length is " << length << endl;
    t.close();
    return length;
}


//将文件内的所有内容存在buffer里面
void read_all_context(char*& buffer,const char* path)
{
    ifstream t;
    int length;
    t.open(path);      // open input file
    t.seekg(0, ios::end);    // go to the end
    length = t.tellg();           // report location (this is the length)
    cout << "the length is " << length << endl;
    t.seekg(0, ios::beg);    // go back to the beginning

    for(int i = 0; i < length ; i += 1 )
    {
        t.seekg(i,ios::beg);
        char str[1];
        t.read(str, 1);       // read the whole file into the buffer
        t.clear();
        buffer[i] = str[0];

    }

    //t.read(buffer,length);


    t.close();
}



//解析LD_String 将ptr，后面length个字节存放在context中
void Parse_LD_Context(char* context,char* ptr , int length)
{
        memcpy((void*)context,(void*)ptr ,length);

        for(int i = 0 ;i < length; i ++)
        {
            context[i] = 0xff - context[i];      //这里需要注意，要用0xff- 进行解密；
        }

        context[length] = 0;
}

//读取当前地址的LD_SIZE,并将指针移到字符串之后（因为传的是实参，所以会改变当前指针的地址）
LD_SIZE parse_ld_size(char*& current_ptr)
{
    LD_SIZE size;
    INT8U head;
    INT32U length;

    memcpy((void*)&head,current_ptr,sizeof(char));

    if(head < 0xff)
    {
        current_ptr ++;
        size.head = head;
    }
    else
    {
        current_ptr ++;
        size.head = 0xff;
        memcpy((void*)&length,current_ptr,sizeof(INT32U));
        size.length = length;
        current_ptr += 4;
    }

    return size;
}

//输出LD_SIZE
void print_ld_size(LD_SIZE size)
{
    if(size.head < 0xff)
    {
        cout << (int)size.head;
    }
    else
    {
        cout << size.length;
    }
}


//读取当前地址的LD_String,并将指针移到字符串之后（因为传的是实参，所以会改变当前指针的地址）
LD_STRING Parse_LD_STRING(char*& current_ptr)
{
    LD_STRING ld_string;

    INT8U head;
    INT32U length;

    memcpy((void*)&head,current_ptr,sizeof(char));

    if(head < 0xff)
    {
        current_ptr ++;

        ld_string.size.head = head;
        ld_string.pstring = (char*)malloc(head + 1);
        Parse_LD_Context(ld_string.pstring,current_ptr,head);
        cout << ld_string.pstring << endl;

        current_ptr += head;
    }
    else
    {
        current_ptr ++;
//        char cnt[4];
//        if(cpu_mdl == LITTLE_END)
//        {
//            cnt[0] = current_ptr[0];
//            cnt[1] = current_ptr[1];
//            cnt[2] = current_ptr[2];
//            cnt[3] = current_ptr[3];
//        }
//        else
//        {
//            cnt[0] = current_ptr[3];
//            cnt[1] = current_ptr[2];
//            cnt[2] = current_ptr[1];
//            cnt[3] = current_ptr[0];
//        }

            memcpy((void*)&length,(void*)current_ptr,sizeof(INT32U));

            ld_string.size.head = 0xff;
            ld_string.size.length = length;
            current_ptr += 4;

            ld_string.pstring = (char*)malloc(length + 1);
            Parse_LD_Context(ld_string.pstring,current_ptr,length);
            cout << ld_string.pstring << endl;

            current_ptr += length;

    }

    return ld_string;
}

LADFILEHEADER parse_plc_header(char* buffer)
{
    LADFILEHEADER header;

    memcpy((void*)&header.type,(void*)buffer,sizeof(INT32U));
    buffer += sizeof(INT32U);

    memcpy((void*)&header.version,(void*)buffer,sizeof(INT32U));
    buffer += sizeof(INT32U);

    memcpy((void*)&header.headSize,(void*)buffer,sizeof(INT32U));
    buffer += sizeof(INT32U);

    memcpy((void*)&header.fileSize,(void*)buffer,sizeof(INT32U));
    buffer += sizeof(INT32U);

    memcpy((void*)&header.blocks,(void*)buffer,sizeof(INT32));
    buffer += sizeof(INT32);

    memcpy((void*)&header.offsetLadderInfo,(void*)buffer,sizeof(INT32));
    buffer += sizeof(INT32);

    memcpy((void*)&header.offsetSymbolTable,(void*)buffer,sizeof(INT32));
    buffer += sizeof(INT32);

    memcpy((void*)&header.offsetLadData,(void*)buffer,sizeof(INT32));
    buffer += sizeof(INT32);

    memcpy((void*)&header.offsetInitDataTable,(void*)buffer,sizeof(INT32));
    buffer += sizeof(INT32);

    memcpy((void*)&header.offsetMessage,(void*)buffer,sizeof(INT32));
    buffer += sizeof(INT32);

    cout << "类型：" << header.type << endl;
    cout << "版本：" << header.version << endl;
    cout << "文件头大小：" << header.headSize << endl;
    cout << "文件大小： " << header.fileSize << endl;
    cout << "程序块个数：" << header.blocks << endl;
    cout << "梯形图信息偏移量：" << header.offsetLadderInfo << endl;
    cout << "符号表数据偏移量：" << header.offsetSymbolTable << endl;
    cout << "梯形图数据偏移量：" << header.offsetLadData << endl;
    cout << "数据初始表偏移量：" << header.offsetInitDataTable << endl;
    cout << "报警表偏移量：" << header.offsetMessage << endl;


    return header;

}

//解析第二部分---“梯形图信息”里面的内容，并将指针移到至下一个环节（因为传的是实参，所以会改变当前指针的地址）
void parse_LadderInfomation(char*& current_ptr)
{
    cout << "解析作者信息...." << endl;
    cout << "作者信息：";
    LD_STRING info_author;
    info_author = Parse_LD_STRING(current_ptr);

    cout << "解析版本信息...." << endl;
    cout << "版本信息：";
    LD_STRING info_version;
    info_version = Parse_LD_STRING(current_ptr);

    cout << "解析备注...." << endl;
    cout << "备注信息：";
    LD_STRING info_note;
    info_note = Parse_LD_STRING(current_ptr);

    free(info_author.pstring);
    free(info_version.pstring);
    free(info_note.pstring);
}

//解析第三部分---“符号表”里面的内容
void parse_SymbolItem(char*& current_ptr)
{
    LD_SIZE size_table;
    INT8U head;
    INT32U length;

    int cnt_table;
    memcpy((void*)&head,current_ptr,sizeof(char));

    if(head < 0xff)
    {
        current_ptr ++;
        size_table.head = head;
        cnt_table = head;
    }
    else
    {
        current_ptr ++;
        memcpy((void*)&length,current_ptr,sizeof(INT32U));
        size_table.head = 0xff;
        size_table.length = length;
        cnt_table = length;
        current_ptr += 4;
    }

    cout << "符号表数量: " << cnt_table << endl << endl;

    for(int i = 0 ; i < cnt_table ;i ++)
    {
        cout << "符号表NO" << i + 1 << ":" << endl;

        INT8U styleSymbols;
        memcpy((void*)&styleSymbols,current_ptr,sizeof(INT8U));
        cout << "符号表类型-- " << (short)styleSymbols << endl;

        cout << "符号表注释-- " ;
        current_ptr ++;
        LD_STRING comment_table = Parse_LD_STRING(current_ptr);
        free(comment_table.pstring);

        cout << "符号表格数-- ";
        LD_SIZE size_Symbols;
        INT8U head;
        INT32U length;
        int cnt_Symbols;
        memcpy((void*)&head,current_ptr,sizeof(INT8U));

        if(head < 0xff)
        {
            current_ptr ++;
            size_Symbols.head = head;
            cnt_Symbols = head;
        }
        else
        {
            current_ptr ++;
            size_Symbols.head = 0xff;
            memcpy((void*)&length,current_ptr,sizeof(INT32U));
            size_Symbols.length = length;
            cnt_Symbols = length;
            current_ptr += 4;
        }

        cout << cnt_Symbols << endl;

        for(int i = 0 ; i < cnt_Symbols ;i ++)
        {
            INT32U Address;
            memcpy((void*)&Address , (void*)current_ptr,sizeof(INT32U));
            cout << "        符号" << i + 1 << ":" << endl;
            cout << "            地址：" << hex << "0x" << Address << endl;       //A -> 0x41
            cout << "            符号：" ;
            current_ptr += sizeof(INT32U);
            LD_STRING sign = Parse_LD_STRING(current_ptr);
            free(sign.pstring);

            cout << "            符号注释：";
            LD_STRING note_sign = Parse_LD_STRING(current_ptr);
            free(note_sign.pstring);
        }

    }


}

//解析第四部分---“梯形图程序数据”里面的内容
void parse_ld_data(char*& current_ptr)
{
    LADBLOCKDATAHEADER head_block;
    networks *tempnetworks = new networks;

    memcpy((void*)&head_block.type,(void*)current_ptr,sizeof(INT32U));
    cout << "类型：" << head_block.type << endl;
    current_ptr += sizeof(INT32U);

    memcpy((void*)&head_block.spAddr,(void*)current_ptr,sizeof(INT32U));
    cout << "程序块地址： 0x" << hex << head_block.spAddr << endl;
    cout << dec;
    current_ptr += sizeof(INT32U);

    memcpy((void*)&head_block.headSize,(void*)current_ptr,sizeof(INT32U));
    cout << "程序块头大小：" << head_block.headSize << endl;
    current_ptr += sizeof(INT32U);

    memcpy((void*)&head_block.blocktype,(void*)current_ptr,sizeof(INT32U));
    cout << "程序块类型：";
    if(head_block.blocktype ==  LADBLOCK_LEVEL1 )
    {
        cout << "一级程序" << endl;
    }
    else if(head_block.blocktype ==  LADBLOCK_LEVEL2 )
    {
        cout << "二级程序" << endl;
    }
    else if(head_block.blocktype ==  LADBLOCK_SUB )
    {
        cout << "子程序" << endl;
    }
    current_ptr += sizeof(INT32U);

    cout << "程序块名称：";
    LD_STRING program_name = Parse_LD_STRING(current_ptr);
    tempnetworks->name = QString::fromLocal8Bit(program_name.pstring);
    free(program_name.pstring);

    cout << "程序块设计者：";
    LD_STRING program_author = Parse_LD_STRING(current_ptr);
    free(program_author.pstring);

    cout << "程序块版本：";
    LD_STRING program_version = Parse_LD_STRING(current_ptr);
    free(program_version.pstring);

    cout << "程序块备注：";
    LD_STRING program_note = Parse_LD_STRING(current_ptr);
    free(program_note.pstring);

    current_ptr += 4*sizeof(INT32);		//四个预留块

    LD_SIZE size_network = parse_ld_size(current_ptr);
    cout << "网络数量： ";
    print_ld_size(size_network);
    cout << endl;

    int real_size_network;
    if(size_network.head < 0xff)
    {
        real_size_network = size_network.head;
    }
    else
    {
        real_size_network = size_network.length;
    }



    for(int i = 0 ; i < real_size_network ; i ++)
    {
                    components *tempcomponents = new components;

        cout << "     network ID: " << i + 1 << ":" << endl;
        cout << "         注释：";
        tempcomponents->comment = Parse_LD_STRING(current_ptr).pstring;
        //Parse_LD_STRING(current_ptr);
        cout << "         row of network：";
        LD_SIZE row = parse_ld_size(current_ptr);
        print_ld_size(row);
        cout << endl;

        int real_row;
        if(row.head < 0xff)
        {
            real_row = row.head;
        }
        else
        {
            real_row = row.length;
        }




        for(int j = 0; j < real_row ; j++)
        {
            cout << "j = " << j << endl;



            for(int k = 0; k < 8 ; k ++)
            {

                cout << "            " << k+1 << ":" << " ";
                cout << "TYPE:";

                INT8U type;
                memcpy((void*)&type,(void*)current_ptr,sizeof(INT8U));
                cout << (short)type << ' ';
                current_ptr += sizeof(INT8U);

                if(0 <= type && type <= 2  || type == 254 || type == 10)
                {
                    INT8U data0;
                    memcpy((void*)&data0,(void*)current_ptr,sizeof(INT8U));
                    current_ptr += sizeof(INT8U);
                    cout << "d0:" << (int) data0 << ' ' ;


                    SingleComponent *tempSingleComponent = new SingleComponent;
                    tempSingleComponent->SetBasis(type,data0);
                    tempcomponents->component[k].append(*tempSingleComponent);
                }

                else if(3 <= type && type <= 6)
                {
                    INT8U data0;
                    INT8U data1;
                    INT32U data2;

                    memcpy((void*)&data0,(void*)current_ptr,sizeof(INT8U));
                    current_ptr += sizeof(INT8U);
                    cout << "d0:" << (int) data0 << ' ' ;

                    memcpy((void*)&data1,(void*)current_ptr,sizeof(INT8U));
                    current_ptr += sizeof(INT8U);
                    cout << "d1:" << (int) data1 << ' ' ;

                    SingleComponent *tempSingleComponent = new SingleComponent;
                    tempSingleComponent->SetBasis(type,data0);
                    tempSingleComponent->SetData1(data1);

                    for(int i = 0; i < data1 ; i ++)
                     {
                         memcpy((void*)&data2,(void*)current_ptr,sizeof(INT32U));
                         INT8U data23,data24;
                         INT16U data21;
                         memcpy((void*)&data21,(void*)(current_ptr + 0*sizeof(INT16U)),sizeof(INT16U));
                         memcpy((void*)&data23,(void*)(current_ptr + 2*sizeof(INT8U)),sizeof(INT8U));
                         memcpy((void*)&data24,(void*)(current_ptr + 3*sizeof(INT8U)),sizeof(INT8U));
                         current_ptr += sizeof(INT32U);
                         cout << hex << "d3:0x" << (int) data2 << ' ' ;
                         cout << dec ;
                         //QString vn = (data24 & 0X7F) + QString::number(data21) + "." + QString::number(data23);
                         QString vn = (data24 & 0X7F) + QString("%1").arg(data21,4,10,QLatin1Char('0'));
                         cout << "Name" << i << ":"<<vn.toStdString() << endl;
                         if(i == 0)tempSingleComponent->SetName(vn);
                         tempSingleComponent->SetExtraData2forB(i,data2);
                     }
                    tempcomponents->component[k].append(*tempSingleComponent);

                }
                else if(30 <= type && type <= 75)
                {
                    INT8U data0;
                    INT8U data1;
                    INT8U data2;
                    INT32U data3;

                    memcpy((void*)&data0,(void*)current_ptr,sizeof(INT8U));
                    current_ptr += sizeof(INT8U);
                    cout << "d0:" << (int) data0 << ' ' ;

                    memcpy((void*)&data1,(void*)current_ptr,sizeof(INT8U));
                    current_ptr += sizeof(INT8U);
                    cout << "d1:" << (int) data1 << ' ' ;

                    SingleComponent *tempSingleComponent = new SingleComponent;
                    tempSingleComponent->SetBasis(type,data0);
                    tempSingleComponent->SetData1(data1);

                    for(int i = 0; i < data1 ; i ++)
                    {
                        memcpy((void*)&data2,(void*)current_ptr,sizeof(INT8U));
                        current_ptr += sizeof(INT8U);
                        cout << "d2:" << (int) data2 << ' ' ;

                        memcpy((void*)&data3,(void*)current_ptr,sizeof(INT32U));


                        INT8U data33,data34;
                        INT16U data31;
                        memcpy((void*)&data31,(void*)(current_ptr + 0*sizeof(INT16U)),sizeof(INT16U));
                        memcpy((void*)&data33,(void*)(current_ptr + 2*sizeof(INT8U)),sizeof(INT8U));
                        memcpy((void*)&data34,(void*)(current_ptr + 3*sizeof(INT8U)),sizeof(INT8U));


                        current_ptr += sizeof(INT32U);
                        cout << hex << "d3:0x" << (int) data3 << ' ' ;
                        cout << dec ;

                        //QString vn = (data34 & 0X7F) + QString::number(data31) + "." + QString::number(data33);
                        QString vn = (data34 & 0X7F) + QString("%1").arg(data31,4,10,QLatin1Char('0'));
                        cout << "Name" << i << ":"<<vn.toStdString() << endl;
                        if(i == 0)tempSingleComponent->SetName(vn);
                        tempSingleComponent->SetExtraData2forC(i,data2);
                        tempSingleComponent->SetExtraData3forC(i,data3);
                    }
                    tempcomponents->component[k].append(*tempSingleComponent);


                }

                cout << endl;
            }




        }
        tempnetworks->network.append(*tempcomponents);

    }
    programs.append(*tempnetworks);
    delete tempnetworks;




}

//解析第五部分---“梯形图数据表”里面的内容
void parse_init_table(char*& current_ptr)
{
     cout << "初始化数据表数量: ";
     LD_SIZE size_init_table = parse_ld_size(current_ptr);
     print_ld_size(size_init_table);
     cout << endl;

     INT8U type_table;
     memcpy((void*)&type_table,(void*)current_ptr,sizeof(INT8U));
     current_ptr ++;
     cout << "数据初始表类型: " << (int)type_table << endl;

     cout << "数据初始表注释：" << endl;
     Parse_LD_STRING(current_ptr);

     cout << "数据初始表的表格数量：";
     LD_SIZE cnt_init_table = parse_ld_size(current_ptr);
     print_ld_size(cnt_init_table);
     cout << endl;

     int cnt_inittable;
     if(cnt_init_table.head < 0xff)
     {
         cnt_inittable = cnt_init_table.head;
     }
     else
     {
         cnt_inittable = cnt_init_table.length;
     }


     for(int i = 0 ; i < cnt_inittable ; i ++)
     {
         LdInitDataItem item;
         memcpy((void*)&item,(void*)current_ptr,sizeof(LdInitDataItem));
         current_ptr += sizeof(LdInitDataItem);
         cout << i << ": ";
         cout << hex << item.nData << dec << endl;

     }


     memcpy((void*)&type_table,(void*)current_ptr,sizeof(INT8U));
     current_ptr ++;
     cout << "数据初始表类型: " << (int)type_table << endl;

     cout << "数据初始表注释：" << endl;
     Parse_LD_STRING(current_ptr);

     cout << "数据初始表的表格数量：";
     cnt_init_table = parse_ld_size(current_ptr);
     print_ld_size(cnt_init_table);
     cout << endl;

     if(cnt_init_table.head < 0xff)
     {
         cnt_inittable = cnt_init_table.head;
     }
     else
     {
         cnt_inittable = cnt_init_table.length;
     }


     for(int i = 0 ; i < cnt_inittable ; i ++)
     {
         LdInitDataItem item;
         memcpy((void*)&item,(void*)current_ptr,sizeof(LdInitDataItem));
         current_ptr += sizeof(LdInitDataItem);
         cout << i << ": ";
         cout << "地址：" << hex << item.nAddr << dec << ' ';
         cout << "数值：" << hex << item.nData << dec << ' ';
         cout << "min ：" << hex << item.nMin << dec << ' ';
         cout << "max ：" << hex << item.nMax << dec << endl;
     }

}

void parse_ld2file(const char*path)
{
    char *buffer = NULL;

    int buffer_length = GetFileSize(path);
    buffer = (char*)malloc(buffer_length);
    read_all_context(buffer,path);


    cout << "----------  文件头信息  ------------" << endl;
    LADFILEHEADER plc_header = parse_plc_header(buffer);
    cout << "----------------------------------" << endl;

    char *current_ptr = buffer + LEN_HEADER;
    cout << "----------  梯图信息  ------------" << endl;
    parse_LadderInfomation(current_ptr);
    cout << "----------------------------------" << endl;

    //current_ptr = buffer + plc_header.offsetSymbolTable;
    cout << endl;
    cout << "---------- 符号表信息 ------------" << endl;
    parse_SymbolItem(current_ptr);
    cout << "----------------------------------" << endl;
    cout << endl;


    //current_ptr = buffer + plc_header.offsetLadData ;
    //由于程序块数量太多，一一显示必将混乱，所以在此只显示了一级程序和二级程序
    cout << endl;
    cout << "----------  梯形图程序数据  ------------" << endl;

//    while(current_ptr - buffer < plc_header.offsetInitDataTable)
//        {
//            parse_ld_data(current_ptr);
//        }
//        parse_ld_data(current_ptr);
    for(INT32U i = 1;i <= plc_header.blocks;i ++)
    {
        parse_ld_data(current_ptr);
    }


    cout << "----------------------------------end" << endl;
    cout << endl;

}
