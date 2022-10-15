#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings set;
    double dph = set.value("dph",21).toDouble();

    if (dph==15){
        ui->rb15->setChecked(true);
        ui->rb21->setChecked(false);
    }
    else {
        ui->rb15->setChecked(false);
        ui->rb21->setChecked(true);
    }


    QString lang = set.value("lang","cs").toString();

    if(lang=="cs"){

        ui-> actioncs ->setChecked(true);
        ui -> actionen -> setChecked(false);

    }
    else {
        ui-> actioncs ->setChecked(false);
        ui -> actionen -> setChecked(true);

    }




    connect(ui->rb15,&QRadioButton::clicked,this,&MainWindow::on_pushButtonEval_clicked);
    connect(ui->rb21,&QRadioButton::clicked,this,&MainWindow::on_pushButtonEval_clicked);
    connect(ui->withoutTax,&QLineEdit::textChanged,this,&MainWindow::on_pushButtonEval_clicked);
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
        else if(ui->rb21->isChecked()){
            value*=1.21;}
         ui -> withTax -> setText(tr("%1 EUR").arg(value));

    }
    else{
        ui -> withTax -> setText("NaN");
    }
}


void MainWindow::on_rb21_clicked()
{
    QSettings set;
    set.setValue("dph",21);

}


void MainWindow::on_rb15_clicked()
{
    QSettings set;
    set.setValue("dph",15);

}


void MainWindow::on_actioncs_triggered()
{
    QSettings set;
    set.setValue("lang","cs");
       ui -> actionen ->setChecked(false);
       qApp -> removeTranslator(&translator);
       ui -> retranslateUi(this);
       qApp -> installTranslator(&translator);
       translator.load(":/lang/trans_cs.qm");
       ui -> retranslateUi(this);

}


void MainWindow::on_actionen_triggered()
{
    QSettings set;
    set.setValue("lang","en");
    ui -> actioncs ->setChecked(false);
    qApp -> removeTranslator(&translator);
    ui -> retranslateUi(this);
    qApp -> installTranslator(&translator);
    translator.load(":/lang/trans_en.qm");
    ui -> retranslateUi(this);
}

