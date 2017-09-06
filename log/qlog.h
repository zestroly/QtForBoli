#ifndef QLOG_H
#define QLOG_H

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

#define Dlog() qDebug()<<QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz")<< __FILE__ <<__FUNCTION__<< "(" << __LINE__ << ")"


class Qlog
{
public:
    Qlog();
};

#endif // QLOG_H
