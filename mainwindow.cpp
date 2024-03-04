#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestioncontrat.h"
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


void MainWindow::on_pushButton_2_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
     gestioncontrat *gc=new gestioncontrat();
     gc->show();
}

void MainWindow::on_pushButton_3_clicked()
{
         ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_7_clicked()
{
             ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked()
{
                 ui->stackedWidget->setCurrentIndex(5);
}
