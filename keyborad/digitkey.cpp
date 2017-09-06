#include "digitkey.h"
#include <QDebug>
#include "log/qlog.h"

DigitKey::DigitKey(QWidget *parent) :
    QDialog(parent)
{
    this->resize(295,330);
   // this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setCursor(Qt::BlankCursor);
    this->setFocusPolicy(Qt::NoFocus);
    this->setMouseTracking(false);

    display = new QLineEdit(this);
    display->setGeometry(1, 4, 290, 50);
    display->setFont(QFont("quanwenyi", 20 ,QFont::Normal, false));
    display->setFocusPolicy(Qt::NoFocus);

    toolButton_1 = new QToolButton(this);
    toolButton_1->setIcon(QIcon("images/picture/1.png"));
    toolButton_1->setIconSize(QSize(32,32));
    toolButton_1->setGeometry(0, 65, 62, 62);
    toolButton_1->setText("1");
    toolButton_1->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));

    toolButton_2 = new QToolButton(this);
    toolButton_2->setIcon(QIcon("images/picture/2.png"));
    toolButton_2->setIconSize(QSize(32,32));
    toolButton_2->setGeometry(70, 65, 62, 62);
    toolButton_2->setText("2");
    toolButton_2->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_2,SIGNAL(clicked()), this, SLOT(digit2Clicked()));

    toolButton_3 = new QToolButton(this);
    toolButton_3->setIcon(QIcon("images/picture/3.png"));
    toolButton_3->setIconSize(QSize(32,32));
    toolButton_3->setGeometry(140, 65, 62, 62);
    toolButton_3->setText("3");
    toolButton_3->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_3,SIGNAL(clicked()), this, SLOT(digit3Clicked()));

    backspaceButton = new QToolButton(this);
    backspaceButton->setGeometry(210, 65, 82, 62);
    backspaceButton->setIcon(QIcon("images/picture/20080902000304211.png"));
    backspaceButton->setIconSize(QSize(32,32));
    backspaceButton->setText("退格");
    backspaceButton->setFocusPolicy(Qt::NoFocus);
    connect(backspaceButton,SIGNAL(clicked()), this, SLOT(backspaceClicked()));


    toolButton_4 = new QToolButton(this);
    toolButton_4->setGeometry(0, 130, 62, 62);
    toolButton_4->setIcon(QIcon("images/picture/4.png"));
    toolButton_4->setIconSize(QSize(32,32));
    toolButton_4->setText("4");
    toolButton_4->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_4,SIGNAL(clicked()), this, SLOT(digit4Clicked()));

    toolButton_5 = new QToolButton(this);
    toolButton_5->setGeometry(70, 130, 62, 62);
    toolButton_5->setIcon(QIcon("images/picture/5.png"));
    toolButton_5->setIconSize(QSize(32,32));
    toolButton_5->setText("5");
    toolButton_5->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_5,SIGNAL(clicked()), this, SLOT(digit5Clicked()));

    toolButton_6 = new QToolButton(this);
    toolButton_6->setGeometry(140, 130, 62, 62);
    toolButton_6->setIcon(QIcon("images/picture/6.png"));
    toolButton_6->setIconSize(QSize(32,32));
    toolButton_6->setText("6");
    toolButton_6->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_6,SIGNAL(clicked()), this, SLOT(digit6Clicked()));

    clearButton = new QToolButton(this);
    clearButton->setGeometry(210, 130, 82, 62);
    clearButton->setIcon(QIcon("images/picture/quit.png"));
    clearButton->setIconSize(QSize(32,32));
    clearButton->setText("清除");
    clearButton->setFocusPolicy(Qt::NoFocus);
    connect(clearButton,SIGNAL(clicked()), this, SLOT(clear()));


    toolButton_7 = new QToolButton(this);
    toolButton_7->setGeometry(0, 195, 62, 62);
    toolButton_7->setIcon(QIcon("images/picture/7.png"));
    toolButton_7->setIconSize(QSize(32,32));
    toolButton_7->setText("7");
    toolButton_7->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_7,SIGNAL(clicked()), this, SLOT(digit7Clicked()));

    toolButton_8 = new QToolButton(this);
    toolButton_8->setGeometry(70, 195, 62, 62);
    toolButton_8->setIcon(QIcon("images/picture/8.png"));
    toolButton_8->setIconSize(QSize(32,32));
    toolButton_8->setText("8");
    toolButton_8->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_8,SIGNAL(clicked()), this, SLOT(digit8Clicked()));

    toolButton_9 = new QToolButton(this);
    toolButton_9->setGeometry(140, 195, 62, 62);
    toolButton_9->setIcon(QIcon("images/picture/9.png"));
    toolButton_9->setIconSize(QSize(32,32));
    toolButton_9->setText("9");
    toolButton_9->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_9,SIGNAL(clicked()), this, SLOT(digit9Clicked()));

    toolButton_0 = new QToolButton(this);
    toolButton_0->setGeometry(0, 260, 62, 62);
    toolButton_0->setIcon(QIcon("images/picture/0.png"));
    toolButton_0->setIconSize(QSize(32,32));
    toolButton_0->setText("0");
    toolButton_0->setFocusPolicy(Qt::NoFocus);
    connect(toolButton_0,SIGNAL(clicked()), this, SLOT(digit0Clicked()));

    pointButton = new QToolButton(this);
    pointButton->setGeometry(70, 260, 62, 62);
    pointButton->setIcon(QIcon("images/picture/12.png"));
    pointButton->setIconSize(QSize(15,15));
    pointButton->setText(".");
    pointButton->setFocusPolicy(Qt::NoFocus);
    connect(pointButton,SIGNAL(clicked()), this, SLOT(pointClicked()));

    changeSignButton = new QToolButton(this) ;
    changeSignButton->setGeometry(140, 260, 62, 62);
    changeSignButton->setIcon(QIcon("images/picture/20080902000703847.png"));
    changeSignButton->setIconSize(QSize(32,32));
    changeSignButton->setText("+/-");
    changeSignButton->setFocusPolicy(Qt::NoFocus);
    connect(changeSignButton,SIGNAL(clicked()), this, SLOT(changeSignClicked()));

    enterButton = new QToolButton(this);
    enterButton->setGeometry(210, 195, 82, 126);
    enterButton->setIcon(QIcon("images/picture/20080527174444744.png"));
    enterButton->setIconSize(QSize(32,32));
    enterButton->setText("确认");
    enterButton->setFocusPolicy(Qt::NoFocus);
    connect(enterButton,SIGNAL(clicked()), this, SLOT(enterClicked()));

    Dlog()<<"构造数字键盘";


}

void DigitKey::digit0Clicked()//0
{
    toolButton_0->setEnabled(false);
    disconnect(toolButton_0,SIGNAL(clicked()), this, SLOT(digit0Clicked()));
    int digitValue = toolButton_0->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    connect(toolButton_0,SIGNAL(clicked()), this, SLOT(digit0Clicked()));
    toolButton_0->setEnabled(true);

}
void DigitKey::digit1Clicked()//1
{
    toolButton_1->setEnabled(false);
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));

    int digitValue = toolButton_1->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    connect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    toolButton_1->setEnabled(true);
}
void DigitKey::digit2Clicked()//2
{
    toolButton_2->setEnabled(false);
    int digitValue = toolButton_2->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_2->setEnabled(true);
}
void DigitKey::digit3Clicked()//3
{
    toolButton_3->setEnabled(false);
    int digitValue = toolButton_3->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
      toolButton_3->setEnabled(true);
}
void DigitKey::digit4Clicked()//4
{
    toolButton_4->setEnabled(true);
    int digitValue = toolButton_4->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_4->setEnabled(false);
}
void DigitKey::digit5Clicked()//5
{
    toolButton_5->setEnabled(false);
    int digitValue = toolButton_5->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_5->setEnabled(true);
}
void DigitKey::digit6Clicked()//6
{
    toolButton_6->setEnabled(false);
    int digitValue = toolButton_6->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_6->setEnabled(true);
}
void DigitKey::digit7Clicked()//7
{
    toolButton_7->setEnabled(false);
    int digitValue = toolButton_7->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_7->setEnabled(true);
}
void DigitKey::digit8Clicked()//8
{
    toolButton_8->setEnabled(false);
    int digitValue = toolButton_8->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_8->setEnabled(true);
}
void DigitKey::digit9Clicked()//9
{
    toolButton_9->setEnabled(false);
    int digitValue = toolButton_9->text().toInt();
    if (display->text() == "0" && digitValue == 0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
    toolButton_9->setEnabled(true);
}

void DigitKey::enterClicked()//确认键
{
    enterButton->setEnabled(false);
    waitingForOperand = true;
    emit setvalue(display->text());
    Dlog()<<"输入数据:"<< display->text();
    this->close();
}

void DigitKey::pointClicked()//小数点
{
    pointButton->setEnabled(false);

    if (waitingForOperand)
        display->setText("0");
    display->setText(display->text() + tr("."));
    waitingForOperand = false;
    pointButton->setEnabled(true);
}

void DigitKey::changeSignClicked()//正负号
{
    changeSignButton->setEnabled(false);
    QString text = display->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    display->setText(text);
    changeSignButton->setEnabled(true);
}

void DigitKey::backspaceClicked()//退格键
{
    backspaceButton->setEnabled(false);
    QString text = display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
    backspaceButton->setEnabled(true);
}

void DigitKey::clear()//清除键
{
    clearButton->setEnabled(false);
    display->setText("0");
    waitingForOperand = true;
    clearButton->setEnabled(true);
}


DigitKey::~DigitKey()
{
    disconnect(toolButton_0,SIGNAL(clicked()), this, SLOT(digit0Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_2,SIGNAL(clicked()), this, SLOT(digit2Clicked()));
    disconnect(toolButton_3,SIGNAL(clicked()), this, SLOT(digit3Clicked()));
    disconnect(toolButton_4,SIGNAL(clicked()), this, SLOT(digit4Clicked()));
    disconnect(toolButton_5,SIGNAL(clicked()), this, SLOT(digit5Clicked()));
    disconnect(toolButton_6,SIGNAL(clicked()), this, SLOT(digit6Clicked()));
    disconnect(toolButton_7,SIGNAL(clicked()), this, SLOT(digit7Clicked()));
    disconnect(toolButton_8,SIGNAL(clicked()), this, SLOT(digit8Clicked()));
    disconnect(toolButton_9,SIGNAL(clicked()), this, SLOT(digit9Clicked()));

    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));
    disconnect(toolButton_1,SIGNAL(clicked()), this, SLOT(digit1Clicked()));


    delete display;
    delete backspaceButton;
    delete changeSignButton;
    delete clearButton;
    delete enterButton;
    delete pointButton;
    delete toolButton_0;
    delete toolButton_1;
    delete toolButton_2;
    delete toolButton_3;
    delete toolButton_4;
    delete toolButton_5;
    delete toolButton_6;
    delete toolButton_7;
    delete toolButton_8;
    delete toolButton_9;

    Dlog()<<"虚构数字键盘";

}




