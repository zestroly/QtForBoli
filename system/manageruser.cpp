#include "manageruser.h"
#include "../log/qlog.h"
#include "../dev/idcardserial.h"

myQuser::myQuser(QWidget *parent, int width, int heith)
{

    QFont wenquanyi25("wenquanyi",  25, QFont::Normal, false);

    lineEdit = new QLineEdit(parent);
    changeButton = new QPushButton(parent);
    eraseButton = new QPushButton(parent);

    lineEdit->setFont(wenquanyi25);
    lineEdit->setAlignment(Qt::AlignHCenter);
    lineEdit->setFocusPolicy(Qt::NoFocus);

    changeButton->setFont(wenquanyi25);
    changeButton->setFocusPolicy(Qt::NoFocus);
    changeButton->setText("修改");
    eraseButton->setFont(wenquanyi25);
    eraseButton->setFocusPolicy(Qt::NoFocus);
    eraseButton->setText("删除");

    lineEdit->resize(200, 40);
    changeButton->resize(60, 40);
    eraseButton->resize(60, 40);

    lineEdit->move(width, heith);
    changeButton->move(lineEdit->x()+  lineEdit->width() +20, heith);
    eraseButton->move(changeButton->x()+  changeButton->width() + 20, heith);


    lineEdit->show();
    changeButton->show();
    eraseButton->show();

}

myQuser::~myQuser()
{
    delete lineEdit;
    delete changeButton;
    delete eraseButton;
}






//***********ManagerUser


ManagerUser::ManagerUser(QWidget *parent) :
    QWidget(parent)
{
    this->resize(1366,768);
    this->setFocusPolicy(Qt::NoFocus);
    QFont wenquanyi35("wenquanyi",  35, QFont::Normal, false);
    QFont wenquanyi25("wenquanyi",  25, QFont::Normal, false);

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("images/picture/main3.jpg").scaled(this->size())));
    this->setPalette(palette);

    scrollArea = new QScrollArea(this);
    scrollArea->setFocusPolicy(Qt::NoFocus);
    displayWidget = new QWidget(scrollArea);
    displayWidget->setFocusPolicy(Qt::NoFocus);


    int StartX = 20, StartY = 20;
    for(int i = 0; i < 10; i++)
    {
        myQuser *qm = new myQuser(displayWidget, StartX, StartY);
        StartY += 60;
        p_myQuser.append(qm);
    }

    scrollArea->move(50, 50);
    scrollArea->resize(this->width()/3  ,  this->height() - 100);//要显示的区域大小

    displayWidget->resize( scrollArea->width() - 20 ,StartY + 100 );
    scrollArea->setWidget(displayWidget);

    QString keyword("1234567890-=abcdefghijklmnopqrstuvwxyz,./");

    int key_x = this->width()/3 + 230;
    int key_y = 80;
    QPushButton *pushbutton;
    for(int i = 0; i < keyword.length(); i++)
    {
        pushbutton = new QPushButton(QString(keyword[i]), this);
        pushbutton->setFont(QFont("utf-8", 50, QFont::Bold, false ));

        pushbutton->move(key_x, key_y);
        if ( (i + 1) % 7 == 0)
        {
            key_y +=90;
            key_x =this->width() / 3+200 + 30;
        }else{
            key_x += 90;
        }
        pushbutton->resize(70,70);
        pushbutton->setFocusPolicy(Qt::NoFocus);
        connect(pushbutton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
        PushButtons.append(pushbutton);
    }

    pushbutton = new QPushButton(QString("<--"), this);
    pushbutton->setFont(QFont("utf-8", 50, QFont::Bold, false ));
    pushbutton->move(key_x, key_y);
    pushbutton->resize(120,70);
    pushbutton->setFocusPolicy(Qt::NoFocus);
    connect(pushbutton ,SIGNAL(clicked()), this, SLOT(digitClicked()));
    PushButtons.append(pushbutton);

    NewUser = new QPushButton("新增", this);
    NewUser->resize(80 , 50);
    NewUser->move(scrollArea->x()+scrollArea->width() + 10 ,  50);
    NewUser->setFont(wenquanyi35);
    NewUser->setFocusPolicy(Qt::NoFocus);


    GoBack = new QPushButton("返回", this);
    GoBack->resize(80 , 50);
    GoBack->move(scrollArea->x()+scrollArea->width() + 10 ,  500);
    GoBack->setFont(wenquanyi35);
    GoBack->setFocusPolicy(Qt::NoFocus);



    connect(NewUser ,SIGNAL(clicked()), this, SLOT(clicked_NewUser()));
    connect(GoBack ,SIGNAL(clicked()), this, SLOT(clicked_Goback()));
    connect(this, SIGNAL(SendToParent(QString)), parent, SLOT(RecvFromChild(QString)));
    this->setAutoFillBackground(true);
    Dlog()<<"构造";
}


void ManagerUser::digitClicked()
{
    QPushButton *pushbutton = dynamic_cast<QPushButton*>(sender());
    if(pushbutton == 0){
        Dlog()<<"键盘出错";
        return;
    }

    if(focusWidget () == 0)
    {
        Dlog()<<"没有焦点控件";
        return;
    }

    QWidget *current_focus_widget;
    current_focus_widget = this->focusWidget();
    if (current_focus_widget->inherits("myLineEdit"))
    {
        myLineEdit *le= qobject_cast<myLineEdit*>(current_focus_widget);
        Dlog()<<"输入"<<pushbutton->text();

        if( pushbutton->text() != QString("<--"))
        {
            QString str = le->text();
            le->setText(str+pushbutton->text());
        }else{

            QString str = le->text();
            if(str.length() > 0)
                le->setText( str.left(str.length()-1) );
        }

    }

}



ManagerUser::~ManagerUser()
{
    foreach(myQuser* mq, p_myQuser)
    {
        delete mq;
    }

    delete displayWidget;
    delete scrollArea;

    foreach(QPushButton* qpb, PushButtons)
    {
           delete qpb;
    }
    delete GoBack;
    delete NewUser;
    Dlog()<<"析构";

}

void ManagerUser::clicked_NewUser()
{
    MTable = new ManagerTable(this);
    MTable->show();
}

void ManagerUser::RecvFromChild(QString ChildrenName)
{
    Dlog()<<ChildrenName;
    if(ChildrenName == QString("ManagerTable"))
    {
       delete MTable;
       MTable = NULL;
    }
}


void ManagerUser::clicked_Goback()
{
    emit SendToParent(QString("ManagerUser"));
}


ManagerTable::ManagerTable(QWidget *parent) :
    QWidget(parent)
{
    this->resize(650,parent->height());
    this->setFocusPolicy(Qt::NoFocus);
    QFont wenquanyi35("wenquanyi",  35, QFont::Normal, false);
    QFont wenquanyi25("wenquanyi",  25, QFont::Normal, false);

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("images/3d8010817b8aa2d9191d4060f7576fe6.jpg").scaled(this->size())));
    this->setPalette(palette);

    QList<QString> strmsg;
    strmsg.append(QString("用户名"));
    strmsg.append(QString("联系方式"));
    strmsg.append(QString("密码管理"));
    strmsg.append(QString("ID卡录入"));
    strmsg.append(QString("指纹录入"));
    strmsg.append(QString("人脸识别"));

    QFont wenquanyi_table("wenquanyi",  25, QFont::Normal, false);
    int tabel_x = 50, tabel_y=100;
    foreach(QString cell , strmsg)
    {
        QLabel *label = new QLabel(cell, this);
        label->resize(120 , 50);
        label->move(tabel_x,  tabel_y);
        label->setFont(wenquanyi_table);
        labels.append(label);
        label->show();

        myLineEdit* lineEdit = new myLineEdit(this);
        lineEdit->resize(300 , 50);
        lineEdit->move(label->x() + label->width() + 20 ,  tabel_y);
        lineEdit->setFont(wenquanyi_table);
        lineEdit->show();
        lineEdits.append(lineEdit );

        QPushButton* pushButton = new QPushButton("修改", this);
        pushButton->resize(80 , 50);
        pushButton->move(lineEdit->x() + lineEdit->width() + 20 ,  tabel_y);
        pushButton->setFont(wenquanyi_table);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->show();
        pushButtons.append(pushButton );

        tabel_y += 70;
    }

    tabel_y += 30;
    QPushButton* savedata = new QPushButton("保存", this);
    savedata->resize(80 , 50);
    savedata->move(400 ,  tabel_y);
    savedata->setFont(wenquanyi35);
    savedata->setFocusPolicy(Qt::NoFocus);
    pushButtons.append(savedata );

    QPushButton* goback = new QPushButton("返回", this);
    goback->resize(80 , 50);
    goback->move(500 ,  tabel_y);
    goback->setFont(wenquanyi35);
    goback->setFocusPolicy(Qt::NoFocus);
    pushButtons.append(goback );

    this->setAutoFillBackground(true);
    connect(savedata ,SIGNAL(clicked()), this, SLOT(clicked_SaveData()));
    connect(goback ,SIGNAL(clicked()), this, SLOT(clicked_Goback()));
    connect(this ,SIGNAL(SendToParent(QString)), parent, SLOT(RecvFromChild(QString)));
    Dlog()<<"创建用户表";
    Dlog()<<"构造";
}


ManagerTable::~ManagerTable()
{
    foreach(QLabel* label , labels)
    {
        Dlog()<<label->text();
        delete label;
    }


    foreach(myLineEdit* lineEdit , lineEdits)
    {
        delete lineEdit;
    }

    foreach(QPushButton* pushbutton , pushButtons)
    {
        delete pushbutton;
    }

    Dlog()<<"析构";
}


void ManagerTable::clicked_SaveData()
{

}

void ManagerTable::clicked_Goback()
{
    emit SendToParent(QString("ManagerTable"));
}


















