#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接信号与槽
    connect(ui->cmdLineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitBtn_clicked()));
    connect(ui->cancelBtn,&QPushButton::clicked,this,&Widget::on_cancelBtn_clicked);
    connect(ui->browseBtn,&QPushButton::clicked,[this](){
        QMessageBox::information(this,"信息","点击浏览");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_commitBtn_clicked()
{
    //获取cmdLineEdit内容
    QString program = ui->cmdLineEdit->text();
    //创建Process对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}


void Widget::on_cancelBtn_clicked()
{
    this->close();
}
