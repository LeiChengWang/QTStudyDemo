#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer;

    QImage img;
    img.load(":photos/1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));

    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);

    picID = 2;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startBtn_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot() {
    QString path = ":photos/";
    path += QString::number(picID);
    path += ".jpg";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picID++;
    if(picID == 4) {
        picID = 1;
    }
}

void Widget::on_stopBtn_clicked()
{
    timer->stop();
}


void Widget::on_singleBtn_clicked()
{
    QTimer::singleShot(1000,this,SLOT(timeoutSlot()));
}

