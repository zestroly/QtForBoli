#ifndef LOCKCONCTLSERIAL_H
#define LOCKCONCTLSERIAL_H
#include "posix_qextserialport.h"



class LockConctlSerial
{
public:
//    LockConctlSerial();
    LockConctlSerial(const char *dev, BaudRateType Rate); //串口， 波特率
    char XORcheck(char* pdata, int datalen ); //校验
    void OpenSingelBox(int addr, int keynum); //输入板子地址，板子锁号
    void OpenAllBox(); //打开所有板子
    int CheckBoxStatus(int addr, char *buff); //输入板子地址
    int FindBoardToDB(); //查找所有板子 从地址0x01 开始找 用于校验板子连接的锁号 并记录到数据库中
    int BoxNumChangeBoardMsg(int BoxNum); //箱号 转化成 板子地址和板子锁号
    //箱号  板子地址   板控位置  存入数据库中
    int LockUpdateDBase(int Boxnum, int boardaddr, int boardkey);
    //地址个数
    int getBoardAddrNumber();
    //该锁板号的锁控个数
    int getBoardKeyNumber(int addr);
    //总共个数
    int getBoxNumber();
    void ClearDBtable(); //清理表的数据
    ~LockConctlSerial();

private:
    Posix_QextSerialPort *Com;
    char devname[100];
};

#endif // LOCKCONCTLSERIAL_H
