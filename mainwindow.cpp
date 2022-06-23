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

void MainWindow::on_workersButton_clicked()
{
    WorkersForm *workersform = new WorkersForm();
    workersform->show();
}


void MainWindow::on_AnimalsButton_clicked()
{
    AnimalsForm *animalsform = new AnimalsForm();
    animalsform->show();
}

