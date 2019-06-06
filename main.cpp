#include "mainwindow.h"
#include <QApplication>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.move(0,0);
    w.show();

    MainWindow m;
    m.move(500,0);
    m.show();

    return a.exec();
}
