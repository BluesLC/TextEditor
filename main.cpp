#include "textedito.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEdito w;
    w.show();

    return a.exec();
}
