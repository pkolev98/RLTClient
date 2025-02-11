#include <iostream>

#include <QCoreApplication>
#include <QDebug>

#include "main-window.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}