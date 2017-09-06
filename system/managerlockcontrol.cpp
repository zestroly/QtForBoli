#include "managerlockcontrol.h"
#include "../log/qlog.h"
#include "../keyborad/digitkey.h"
#include <strings.h>
#include "../dev/lockconctlserial.h"
#include <QInputContext>



ManagerLockControl::ManagerLockControl(QWidget *parent) :
    QWidget(parent)
{
    this->resize(1366,768);
    this->setAutoFillBackground(false);
    this->setFocusPolicy(Qt::NoFocus);

    QFont wenquanyi35("wenquanyi",  35, QFont::Normal, false);

    LockConctlSerial co("/dev/ttyUSB0", BAUD57600);

    LabelBoardLockNum = new QLabel("锁控位置：",this);
    LabelBoardLockNum->setFont(wenquanyi35);
    LabelBoardLockNum->setGeometry(50,100,200,50);
    LabelBoardLockNum->setFocusPolicy(Qt::NoFocus);

    LineEditBoardLockNum = new myLineEdit(this);
    LineEditBoardLockNum->setAlignment(Qt::AlignHCenter);
    LineEditBoardLockNum->setFont(wenquanyi35);
    LineEditBoardLockNum->setGeometry(250,100,200,50);
    LineEditBoardLockNum->setFocusPolicy(Qt::ClickFocus);
    LineEditBoardLockNum->setReadOnly(false);
    LineEditBoardLockNum->setText( QString::number(co.getBoardAddrNumber()) );

    LabelBoardNum = new QLabel("锁板数量：",this);
    LabelBoardNum->setFont(wenquanyi35);
    LabelBoardNum->setGeometry(50,180,200,50);
    LabelBoardNum->setFocusPolicy(Qt::NoFocus);

    LineEditBoardNum = new myLineEdit(this);
    LineEditBoardNum->setFont(wenquanyi35);
    LineEditBoardNum->setAlignment(Qt::AlignHCenter);
    LineEditBoardNum->setGeometry(250,180,200,50);
    LineEditBoardNum->setFocusPolicy(Qt::ClickFocus);
    LineEditBoardNum->setText( QString::number( co.getBoardKeyNumber(LineEditBoardLockNum->text().toInt() ) ) );

    LabelAllNum = new QLabel("锁控总数：",this);
    LabelAllNum->setFont(wenquanyi35);
    LabelAllNum->setGeometry(50,260,200,50);
    LabelAllNum->setFocusPolicy(Qt::NoFocus);

    LineEditAllNum = new myLineEdit(this);
    LineEditAllNum->setFont(wenquanyi35);
    LineEditAllNum->setAlignment(Qt::AlignHCenter);
    LineEditAllNum->setGeometry(250,260,200,50);
    LineEditAllNum->setFocusPolicy(Qt::ClickFocus);
    LineEditAllNum->setText(QString::number( co.getBoxNumber() ));

    LabelOpenNum = new QLabel("单独打开：",this);
    LabelOpenNum->setFont(wenquanyi35);
    LabelOpenNum->setGeometry(50,340,200,50);
    LabelOpenNum->setFocusPolicy(Qt::NoFocus);

    LineEditOpenNum = new myLineEdit(this);
    LineEditOpenNum->setFont(wenquanyi35);
    LineEditOpenNum->setAlignment(Qt::AlignHCenter);
    LineEditOpenNum->setGeometry(250,340,200,50);
    LineEditOpenNum->setFocusPolicy(Qt::ClickFocus);

    OpenAll = new QPushButton("打开全部",this);
    OpenAll->setFont(wenquanyi35);
    OpenAll->setFlat(false);
    OpenAll->adjustSize();
    OpenAll->move(50 , 420);
    OpenAll->setFocusPolicy(Qt::NoFocus);

    OpenSingle = new QPushButton("打开单柜体",this);
    OpenSingle->setFont(wenquanyi35);
    OpenSingle->setFlat(false);
    OpenSingle->adjustSize();
    OpenSingle->move(50+OpenAll->width()+30 , 420);
    OpenSingle->setFocusPolicy(Qt::NoFocus);

    SaveData = new QPushButton("保存",this);
    SaveData->setFont(wenquanyi35);
    SaveData->setFlat(false);
    SaveData->adjustSize();
    SaveData->move(50 , 500);
    SaveData->setFocusPolicy(Qt::NoFocus);

    Calibration = new QPushButton("校准锁板",this);
    Calibration->setFont(wenquanyi35);
    Calibration->setFlat(false);
    Calibration->adjustSize();
    Calibration->move(50+SaveData->width()+30 , 500);
    Calibration->setFocusPolicy(Qt::NoFocus);

    GoBack = new QPushButton("返回",this);
    GoBack->setFont(wenquanyi35);
    GoBack->setFlat(false);
    GoBack->adjustSize();
    GoBack->move(50+SaveData->width()+30 + Calibration->width() + 30 , 500);
    GoBack->setFocusPolicy(Qt::NoFocus);

    //小键盘
    QMatrix matrix;
    matrix.scale(2,2);
    QImage img;
    int start_x = this->width() / 2;
    int start_y = 100;

    for(int i = 1; i < 10 ; i++)
    {
        QToolButton *toolButton = new QToolButton(this);
        QString temp;
        temp.sprintf("images/picture/%d.png",i);
        img.load(temp);

        toolButton->setText(temp.sprintf("%d",i));
        toolButton->setIcon(QPixmap::fromImage(img.transformed(matrix)));
        toolButton->setIconSize(QPixmap::fromImage(img.transformed(matrix)).size());

        toolButton->move(start_x, start_y);
        if (i % 3 == 0)
        {
            start_y +=150;
            start_x =this->width() / 2;

        }else{
            start_x += 150;

        }
        toolButton->resize(100,100);
        toolButton->setFocusPolicy(Qt::NoFocus);
        connect(toolButton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
        toolButtons.append(toolButton);
    }

    QToolButton *toolButton = new QToolButton(this);
    img.load("images/picture/0.png");

    toolButton->setText(QString("0"));
    toolButton->setIcon(QPixmap::fromImage(img.transformed(matrix)));
    toolButton->setIconSize(QPixmap::fromImage(img.transformed(matrix)).size());

    toolButton->move(start_x, start_y);
    toolButton->resize(100,100);
    toolButton->setFocusPolicy(Qt::NoFocus);
    connect(toolButton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
    toolButtons.append(toolButton);

    toolButton = new QToolButton(this);
    img.load("images/picture/20080902000304211.png");

    toolButton->setText(QString("退格"));
    toolButton->setIcon(QPixmap::fromImage(img.transformed(matrix)));
    toolButton->setIconSize(QPixmap::fromImage(img.transformed(matrix)).size());

    toolButton->move(start_x + 150, start_y);
    toolButton->resize(100,100);
    toolButton->setFocusPolicy(Qt::NoFocus);
    connect(toolButton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
    toolButtons.append(toolButton);




    connect(GoBack,     SIGNAL(clicked()),this,SLOT(chicked_Goback()));
    connect(SaveData,   SIGNAL(clicked()),this,SLOT(chicked_SaveData()));
    connect(OpenAll,    SIGNAL(clicked()),this,SLOT(chicked_OpenAll()));
    connect(OpenSingle, SIGNAL(clicked()),this,SLOT(chicked_OpenSingle()));
    connect(Calibration, SIGNAL(clicked()),this,SLOT(chicked_Calibration()));



   // connect(this,   SIGNAL(SendToParent()),this->parent(),SLOT(display_main()));
    LineEditBoardLockNum->setFocus();
    this->setAutoFillBackground(true);
    Dlog()<<"构造";

}



void ManagerLockControl::digitClicked()
{
    QToolButton *toolButton = dynamic_cast<QToolButton*>(sender());
    if(toolButton == 0){
        Dlog()<<"键盘出错";
        return;
    }
    toolButton->setEnabled(false);
    disconnect(toolButton,SIGNAL(clicked()), this, SLOT(digitClicked()));

    QWidget *current_focus_widget;
    current_focus_widget = this->focusWidget();
    if (current_focus_widget->inherits("myLineEdit"))
    {

        myLineEdit *le= qobject_cast<myLineEdit*>(current_focus_widget);

        if( toolButton->text() != QString("退格"))
        {
            QString str = le->text();
            le->setText(str+toolButton->text());
        }else{

            QString str = le->text();
            if(str.length() > 0)
                le->setText( str.left(str.length()-1) );
        }

    }

    connect(toolButton,SIGNAL(clicked()), this, SLOT(digitClicked()));
    toolButton->setEnabled(true);
}


ManagerLockControl::~ManagerLockControl()
{

    QToolButton *toolButton;
    foreach( toolButton , toolButtons)
    {
        disconnect(toolButton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
        delete toolButton;
    }

    delete OpenAll;
    delete OpenSingle;
    delete GoBack;
    delete SaveData;
    delete Calibration;

    delete LabelBoardNum;
    delete LineEditBoardNum;

    delete LabelBoardLockNum;
    delete LineEditBoardLockNum;

    delete LabelAllNum;
    delete LineEditAllNum;

    delete LabelOpenNum;
    delete LineEditOpenNum;

    Dlog()<<"析构";
}




void ManagerLockControl::chicked_Calibration()
{
    LockConctlSerial co("/dev/ttyUSB0", BAUD57600);
    co.FindBoardToDB();
}

void ManagerLockControl::chicked_OpenAll()
{
    LockConctlSerial co("/dev/ttyUSB0", BAUD57600);
    co.OpenAllBox();
}

void ManagerLockControl::chicked_OpenSingle()
{
    LockConctlSerial co("/dev/ttyUSB0", BAUD57600);
    co.BoxNumChangeBoardMsg(LineEditOpenNum->text().toInt());
}


void ManagerLockControl::chicked_Goback()
{
    delete this;
 //   emit SendToParent();
}

void ManagerLockControl::chicked_SaveData()
{

}

