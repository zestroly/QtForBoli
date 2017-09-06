#include "idcardserial.h"
#include "../log/qlog.h"


// 02   30 30 31 35 36 39 37 34 35 37   0d 0a 03
IDcardSerial::IDcardSerial(const char *dev, BaudRateType Rate)
{
    //打开单个箱子
    Com = new Posix_QextSerialPort(QString(dev), QextSerialBase::Polling);
    if(Com->open(QIODevice::ReadWrite)){
        Dlog()<<"打开串口成功";
    }else{
        Dlog()<<"打开串口失败";
        return;
    }
    memset(devname, 0, sizeof(devname));
    memcpy(devname, dev, strlen(dev));
    //设置波特率
    Com->setBaudRate(Rate);
    //设置数据位
    Com->setDataBits(DATA_8);
    //设置校验
    Com->setParity(PAR_NONE);
    //设置停止位
    Com->setStopBits(STOP_1);

    Com->setFlowControl(FLOW_OFF);
    Com->setTimeout(10000);


    Dlog()<< devname <<"构造串口数据发送器";
}


QString IDcardSerial::ReadID()
{
    char data[100] = {0};

    Com->flush();
    int availablenum = Com->bytesAvailable();
    Dlog()<<"111111111111"<<availablenum;

    if (availablenum <= 0)
        return "";
    usleep(1000*200);
    int count = Com->readLine(data, sizeof(data));


    char msgbuff[1024] = {0};
    sprintf(msgbuff, "数据接受%s(%d): ", devname, count);
    for(int i = 0; i< count; i++)
    {
        sprintf(msgbuff, "%s %02x",msgbuff, data[i]&0xff);
    }
    Dlog()<<msgbuff;
    char databuff[100]={0};
    qMemCopy( databuff, data+1, 10  );

    return QString(databuff);


}


IDcardSerial::~IDcardSerial()
{
}
