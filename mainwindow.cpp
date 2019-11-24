#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>
#include <QTimer>
#include "about.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tray_icon = new QSystemTrayIcon;
    tray_icon->setIcon(QIcon(":/img/img/bobbyg.ico"));
    tray_icon->setVisible(true);
}
////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
    delete tray_icon;
}
////////////////////////////////////////////////////////////
void MainWindow::on_checkbox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {

        ui->approval->setText("   Approved");
        qApp->setWindowIcon(QIcon(":/img/img/bobbyr.ico"));

        tray_icon->setIcon(QIcon(":/img/img/bobbyr.ico"));
        tray_icon->showMessage("Tray icon changed!", "Changed!");
    }
    else
    {
        ui->approval->setText("Not approved");
        qApp->setWindowIcon(QIcon(":/img/img/bobbyr.ico"));

        tray_icon->setIcon(QIcon(":/img/img/bobbyg.ico"));
        tray_icon->showMessage("Tray icon changed!", "Changed!");
    }
}
////////////////////////////////////////////////////////////
void MainWindow::on_horizontalslider_valueChanged(int value)
{
    switch(value)
    {
        case 0:
        {
            QPixmap pixmap(":/img/img/bobby.png");
            ui->photo->setPixmap(pixmap);
            break;
        }
        case 1:
        {
            QPixmap pixmap(":/img/img/bobby1.png");
            ui->photo->setPixmap(pixmap);
            break;
        }
        default:
        {
            QPixmap pixmap(":/img/img/bobby2.png");
            ui->photo->setPixmap(pixmap);
            break;
        }
   }
}
////////////////////////////////////////////////////////////
void MainWindow::on_winkbutton_clicked()
{
    ui->photo->hide();
    QTimer::singleShot(40, ui->photo, SLOT(show()));
}
////////////////////////////////////////////////////////////
void MainWindow::on_actionexit_triggered()
{
    close();
}
////////////////////////////////////////////////////////////
void MainWindow::on_actionabout_me_triggered()
{
   About Aboutme;
   Aboutme.setModal(true);
   Aboutme.exec();
}
