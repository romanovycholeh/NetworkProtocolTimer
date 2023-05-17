#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network/timers/windowstimer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Resource client1Resource1{Resource::Kind::GOOGLE_CHROME, Resource::State::DISCONNECTED};
    std::list<Resource> client1Resources{client1Resource1};
    Connection* client1Connection = new Connection{0, client1Resources};
    Client client1{0};
    mClients.push_back(client1);

    Resource client2Resource1{Resource::Kind::MAIL, Resource::State::DISCONNECTED};
    Resource client2Resource2{Resource::Kind::ONE_DRIVE, Resource::State::DISCONNECTED};
    Resource client2Resource3{Resource::Kind::GOOGLE_CHROME, Resource::State::DISCONNECTED};
    std::list<Resource> client2Resources{client2Resource1, client2Resource2, client2Resource3};
    Connection* client2Connection = new Connection{1, client2Resources};
    Client client2{1};
    mClients.push_back(client2);

    Resource client3Resource1{Resource::Kind::TELEGRAM, Resource::State::DISCONNECTED};
    Resource client3Resource2{Resource::Kind::ZOOM, Resource::State::DISCONNECTED};
    std::list<Resource> client3Resources{client3Resource1, client3Resource2};
    Connection* client3Connection = new Connection{2, client3Resources};
    Client client3{2};
    mClients.push_back(client3);

    std::vector<Connection*> connections{client1Connection, client2Connection, client3Connection};
    mServer = new Server{connections};

    connect(mServer, &Server::timerStarted, this, &MainWindow::on_timer_started);

    connect(mServer,&Server::clientBecomeActive, this, &MainWindow::on_client_become_active);

    mTimers.push_back(new QTimer(this));
    mTimers.push_back(new QTimer(this));
    mTimers.push_back(new QTimer(this));
    connect(mTimers.at(0),SIGNAL(timeout()), this, SLOT(change_left_timeout_1()));
    connect(mTimers.at(1),SIGNAL(timeout()), this, SLOT(change_left_timeout_2()));
    connect(mTimers.at(2),SIGNAL(timeout()), this, SLOT(change_left_timeout_3()));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_client1_GoogleChrome_stateChanged(int arg1)
{
    Request createdRequest = mClients.at(0).MakeRequest(0, Resource::Kind::GOOGLE_CHROME, static_cast<bool>(arg1));
    mServer->HandleRequest(createdRequest);
}


void MainWindow::on_client2_Mail_stateChanged(int arg1)
{
    Request createdRequest = mClients.at(1).MakeRequest(1, Resource::Kind::MAIL, static_cast<bool>(arg1));
    mServer->HandleRequest(createdRequest);
}


void MainWindow::on_client2_OneDrive_stateChanged(int arg1)
{
    Request createdRequest = mClients.at(1).MakeRequest(1, Resource::Kind::ONE_DRIVE, static_cast<bool>(arg1));
    mServer->HandleRequest(createdRequest);
}


void MainWindow::on_client2_GoogleChrome_stateChanged(int arg1)
{
    Request createdRequest = mClients.at(1).MakeRequest(1, Resource::Kind::GOOGLE_CHROME, static_cast<bool>(arg1));
    mServer->HandleRequest(createdRequest);
}


void MainWindow::on_client3_Telegram_stateChanged(int arg1)
{
    Request createdRequest = mClients.at(2).MakeRequest(2, Resource::Kind::TELEGRAM, static_cast<bool>(arg1));
    mServer->HandleRequest(createdRequest);
}


void MainWindow::on_client3_Zoom_stateChanged(int arg1)
{
    Request createdRequest = mClients.at(2).MakeRequest(2, Resource::Kind::ZOOM, static_cast<bool>(arg1));
    mServer->HandleRequest(createdRequest);
}

void MainWindow::on_timer_started(int timerId)
{
    QTime timeout;
    timeout.setHMS(0,0,5);
    switch(timerId)
    {
    case 0:
        ui->timeEdit_0->setTime(timeout);
        mTimers.at(timerId)->start(1000);
    break;

    case 1:
        ui->timeEdit_1->setTime(timeout);
        mTimers.at(timerId)->start(1000);
    break;
    case 2:

        ui->timeEdit_2->setTime(timeout);
        mTimers.at(timerId)->start(1000);
    break;
    }
}

void MainWindow::change_left_timeout_1()
{
    auto time = ui->timeEdit_0->time();
    int secondsLeft = time.second();
    --secondsLeft;
    if(secondsLeft == 0)
    {
        ui->client1_main->setEnabled(false);
        mTimers.at(0)->stop();
    }
    time.setHMS(0, 0, secondsLeft);
    ui->timeEdit_0->setTime(time);
}

void MainWindow::change_left_timeout_2()
{
    auto time = ui->timeEdit_1->time();
    int secondsLeft = time.second();
    --secondsLeft;
    if(secondsLeft == 0)
    {
        ui->client2_main->setEnabled(false);
        mTimers.at(1)->stop();
    }
    time.setHMS(0, 0, secondsLeft);
    ui->timeEdit_1->setTime(time);
}

void MainWindow::change_left_timeout_3()
{
    auto time = ui->timeEdit_2->time();
    int secondsLeft = time.second();
    --secondsLeft;
    if(secondsLeft == 0)
    {
        ui->client3_main->setEnabled(false);
        mTimers.at(2)->stop();
    }
    time.setHMS(0, 0, secondsLeft);
    ui->timeEdit_2->setTime(time);
}

void MainWindow::on_client_become_active(int clientId)
{
    switch(clientId)
    {
    case 0:
        ui->client1_main->setEnabled(true);
        mTimers.at(0)->stop();
        break;
    case 1:
        ui->client2_main->setEnabled(true);
        mTimers.at(1)->stop();
        break;
    case 2:
        ui->client3_main->setEnabled(true);
        mTimers.at(2)->stop();
        break;
    }
}

