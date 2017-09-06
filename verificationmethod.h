#ifndef VERIFICATIONMETHOD_H
#define VERIFICATIONMETHOD_H

#include <QWidget>
#include <QPalette>
#include <QtGui/QWidget>
#include <QBrush>
#include <QTextCodec>
#include <QDebug>
#include <QDateTime>
#include <QPushButton>
#include <QLabel>
#include <QAction>
#include <QToolBar>
#include <QPalette>
#include <QLabel>
#include <QFrame>
#include <QGraphicsView>
#include "mainwindow.h"
#include "checkdev.h"
#include <QToolButton>

class MainWindow;
class CheckDev;

class VerificationMethod : public QWidget
{
    Q_OBJECT
    
public:
    explicit VerificationMethod(QWidget *parent = 0);
    ~VerificationMethod();
    CheckDev *checkdev;
    
private slots:
    void on_PassWorkCheck_clicked();

    void on_IDcardCheck_clicked();

    void on_DactylogramCheck_clicked();

    void on_FaceCheck_clicked();

    void on_BackToUpper_clicked();

    void connectPuttonSignal();
    void disconnectPuttonSignal();

    void on_clearPointe();

private:
    MainWindow *parentName;

    QPushButton *FaceCheck;
    QPushButton *PassWorkCheck;
    QPushButton *DactylogramCheck;
    QPushButton *IDcardCheck;
    QPushButton *BackToUpper;



};

#endif // VERIFICATIONMETHOD_H
