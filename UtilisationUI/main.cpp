#include "utilisationui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UtilisationUI w;
    w.show();
    return a.exec();
}
