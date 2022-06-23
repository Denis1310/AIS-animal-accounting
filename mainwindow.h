#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "workersform.h"
#include "animalsform.h"
#include <QMainWindow>

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

    void on_workersButton_clicked();

    void on_AnimalsButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
