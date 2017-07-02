#include "hexcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hexcalculator w;
    w.show();

    return a.exec();
}

