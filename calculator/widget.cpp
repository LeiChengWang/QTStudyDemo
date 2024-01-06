#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置窗口的大小
    this->setMaximumSize(210,300);
    this->setMinimumSize(210,300);

    //设置窗口的名称
    this->setWindowTitle("计算器");

    //设置文本输入框字体
    QFont f("仿宋",12);
    ui->expLineEdit->setFont(f);

    // //按钮上放图片
    // QIcon icon;
    // icon.addFile("‪D:/Code/QtStudy/calculator/del.jpg",QSize(40,40),QIcon::Normal,QIcon::On);
    // ui->delBtn->setIcon(icon);

    //改变按钮的背景色
    ui->equalBtn->setStyleSheet("background:#7EC0EE");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_leftBtn_clicked()
{
    expression += "(";
    ui->expLineEdit->setText(expression);
}


void Widget::on_zerobtn_clicked()
{
    expression += "0";
    ui->expLineEdit->setText(expression);
}


void Widget::on_rightBtn_clicked()
{
    expression += ")";
    ui->expLineEdit->setText(expression);
}


void Widget::on_oneBtn_clicked()
{
    expression += "1";
    ui->expLineEdit->setText(expression);
}


void Widget::on_twoBtn_clicked()
{
    expression += "2";
    ui->expLineEdit->setText(expression);
}


void Widget::on_threeBtn_clicked()
{
    expression += "3";
    ui->expLineEdit->setText(expression);
}


void Widget::on_fourBtn_clicked()
{
    expression += "4";
    ui->expLineEdit->setText(expression);
}


void Widget::on_fiveBtn_clicked()
{
    expression += "5";
    ui->expLineEdit->setText(expression);
}


void Widget::on_sixBtn_clicked()
{
    expression += "6";
    ui->expLineEdit->setText(expression);
}


void Widget::on_sevenBtn_clicked()
{
    expression += "7";
    ui->expLineEdit->setText(expression);
}


void Widget::on_eightBtn_clicked()
{
    expression += "8";
    ui->expLineEdit->setText(expression);
}


void Widget::on_nineBtn_clicked()
{
    expression += "9";
    ui->expLineEdit->setText(expression);
}


void Widget::on_addBtn_clicked()
{
    expression += "+";
    ui->expLineEdit->setText(expression);
}


void Widget::on_subBtn_clicked()
{
    expression += "-";
    ui->expLineEdit->setText(expression);
}


void Widget::on_mulBtn_clicked()
{
    expression += "*";
    ui->expLineEdit->setText(expression);
}


void Widget::on_divBtn_clicked()
{
    expression += "/";
    ui->expLineEdit->setText(expression);
}


void Widget::on_clearBtn_clicked()
{
    expression.clear();
    ui->expLineEdit->clear();
}


void Widget::on_delBtn_clicked()
{
    expression.chop(1);
    ui->expLineEdit->setText(expression);
}


void Widget::on_equalBtn_clicked()
{
    expression =  QString::number(calculateExpression(expression));
    ui->expLineEdit->setText(expression);
}

double Widget::calculateExpression(const QString &expression) {
    QStack<double> numbers;
    QStack<char> operators;

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i].isDigit()) {
            QString num;
            while (i < expression.length() && (expression[i].isDigit() || expression[i] == '.')) {
                num.append(expression[i]);
                i++;
            }
            i--;

            numbers.push(num.toDouble());
        } else if (expression[i] == '(') {
            char currentChar = expression[i].toLatin1(); // 将QChar转换为char
            operators.push(currentChar);
        } else if (expression[i] == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                double val2 = numbers.pop();
                double val1 = numbers.pop();
                char op = operators.pop();

                if (op == '+')
                    numbers.push(val1 + val2);
                else if (op == '-')
                    numbers.push(val1 - val2);
                else if (op == '*')
                    numbers.push(val1 * val2);
                else if (op == '/')
                    numbers.push(val1 / val2);
            }
            operators.pop(); // Pop '('
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            char currentOp = expression[i].toLatin1(); // 将QChar转换为char
            while (!operators.isEmpty() && operators.top() != '(' &&
                   ((currentOp == '*' || currentOp == '/') ||
                    (operators.top() == '+' || operators.top() == '-'))) {
                double val2 = numbers.pop();
                double val1 = numbers.pop();
                char op = operators.pop();

                if (op == '+')
                    numbers.push(val1 + val2);
                else if (op == '-')
                    numbers.push(val1 - val2);
                else if (op == '*')
                    numbers.push(val1 * val2);
                else if (op == '/')
                    numbers.push(val1 / val2);
            }
            operators.push(currentOp);
        }

    }

    while (!operators.isEmpty()) {
        double val2 = numbers.pop();
        double val1 = numbers.pop();
        char op = operators.pop();

        if (op == '+')
            numbers.push(val1 + val2);
        else if (op == '-')
            numbers.push(val1 - val2);
        else if (op == '*')
            numbers.push(val1 * val2);
        else if (op == '/')
            numbers.push(val1 / val2);
    }

    return numbers.top();
}


