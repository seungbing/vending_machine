#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n) {
    money += n;
    ui->lcdNumber->display(QString::number(money));

    if(money < 100) {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    else if(money < 150 && money >= 100) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    else if(money < 200 && money >= 150) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGongcha->setEnabled(false);
    }
    else if(money >= 200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGongcha->setEnabled(true);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
 changeMoney(50);
}

void Widget::on_pb100_clicked()
{
 changeMoney(100);
}

void Widget::on_pb500_clicked()
{
 changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_ret_clicked()
{
    int money10 = 0;
    int money50 = 0;
    int money100 = 0;
    int money500 = 0;

    if(money >= 500) {
        money500 = money / 500;
        money = money % 500;
    }
    if(money >= 100) {
        money100 = money / 100;
        money = money % 100;
    }
    if(money >= 50) {
        money50 = money / 50;
        money = money % 50;
    }
    if(money >= 10){
        money10 = money / 10;
        money = money % 10;
    }

    QMessageBox msg;
    msg.information(nullptr,"return money",
                    "500coin : "+QString::number(money500)+
                    "\n100coin : "+QString::number(money100)+
                    "\n50coin : "+QString::number(money50)+
                    "\n10coin : "+QString::number(money10));
    money = 0;
    ui->lcdNumber->display(QString::number(money));
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbGongcha->setEnabled(false);
}
