#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include "log/qlog.h"
#include "keyborad/digitkey.h"
#include <QWSServer>
#include "system/systemmanager.h"
#include "system/managerlockcontrol.h"
#include "system/manageruser.h"


int main(int argc, char *argv[])
{    
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);



   MainWindow w;
    w.show();
////    SystemManager w;
////    w.show();
//ManagerNetworkSet w;
//w.show();

    //设置不显示鼠标
   // QWSServer::setCursorVisible(false);
    return a.exec();
}
