#include "mainwindow.h"
#include <Windows.h>
#include "network/server.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << "Started the application";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
