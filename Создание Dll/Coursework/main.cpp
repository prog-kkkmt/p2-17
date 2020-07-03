#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qApp->addLibraryPath("/plugins");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
