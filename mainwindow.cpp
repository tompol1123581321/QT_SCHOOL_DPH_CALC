#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->withTax->clear();
    ui->withoutTax->clear();
}


void MainWindow::on_pushButtonEval_clicked()
{
    bool success;
    double value = ui -> withoutTax -> text().toDouble(&success);
    if(success){
        if(ui->rb15->isChecked()){
            value*=1.15;

        }
        else{
            value*=1.21;}

    }
    ui -> withTax -> setText(tr("%1 EUR").arg(value));
}

