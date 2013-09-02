#include "mainwindow.h"
#include <QApplication>
#include <QSystemTrayIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSystemTrayIcon *sysTrayIcon = new QSystemTrayIcon();
    sysTrayIcon->setIcon(QIcon(":/application_icon"));
    MainWindow w;
    //w.show();
    
    return a.exec();
}
