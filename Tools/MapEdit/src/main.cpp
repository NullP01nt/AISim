#include <QApplication>
#include "MapEditWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapEditWindow mew;
    mew.show();

    return a.exec();
}
