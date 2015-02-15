#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle(QObject::tr("要塞随从分析"));
    w.show();

    return a.exec();
}
