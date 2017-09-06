#ifndef IDCARDSERIAL_H
#define IDCARDSERIAL_H

#include "posix_qextserialport.h"

//读取idcard的信息
class IDcardSerial
{
public:
    IDcardSerial(const char *dev, BaudRateType Rate);
    QString ReadID();

    ~IDcardSerial();

private:
    Posix_QextSerialPort *Com;
    char devname[100];


};

#endif // IDCARDSERIAL_H
