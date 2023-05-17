#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sources/network/request.h"
#include "sources/network/server.h"
#include "network/client.h"
#include "network/timers/windowstimer.h"
#include <QMainWindow>
#include <QTimer>
#include <queue>
#include <vector>

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
    void on_client1_GoogleChrome_stateChanged(int arg1);

    void on_client2_Mail_stateChanged(int arg1);

    void on_client2_OneDrive_stateChanged(int arg1);

    void on_client2_GoogleChrome_stateChanged(int arg1);

    void on_client3_Telegram_stateChanged(int arg1);

    void on_client3_Zoom_stateChanged(int arg1);

    void on_timer_started(int timerId);

    void change_left_timeout_1();
    void change_left_timeout_2();
    void change_left_timeout_3();

    void on_client_become_active(int clientId);

private:
    Ui::MainWindow *ui;
    Server* mServer;
    std::vector<Client> mClients;
    std::vector<QTimer*> mTimers;

};
#endif // MAINWINDOW_H
