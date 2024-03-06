#include "_test_qmouseevent.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _test_QMouseEvent w;
    w.show();
    return a.exec();
}
