#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonClear_clicked();

    void on_pushButtonEval_clicked();

    void on_rb21_clicked();

    void on_rb15_clicked();

    void on_actioncs_triggered();

    void on_actionen_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator translator;

};
#endif // MAINWINDOW_H
