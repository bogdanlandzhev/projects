#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
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
    void on_checkbox_stateChanged(int arg1);

    void on_horizontalslider_valueChanged(int value);

    void on_winkbutton_clicked();

    void on_actionexit_triggered();

    void on_actionabout_me_triggered();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *tray_icon;
   // form_open *fOpen;
};
#endif // MAINWINDOW_H
