#include "_test_qmouseevent.h"
#include<QEvent>
#include<QMouseEvent>
#include<qdebug.h>
_test_QMouseEvent::_test_QMouseEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_test_QMouseEventClass())
{
    ui->setupUi(this);
}

_test_QMouseEvent::~_test_QMouseEvent()
{
    delete ui;
}

bool _test_QMouseEvent::event(QEvent* ev)
{
    if (ev->type() == QEvent::MouseButtonPress)
    {
        //�������
        QMouseEvent* mc = static_cast<QMouseEvent*>(ev);
        //qDebug() << "MouseButtonPress " << mc->x() << ": " << mc->y();
        //��������
        //qDebug() << "windowPos " << mc->windowPos().x() << ": " << mc->windowPos().y();
        //��Ļ����
        //qDebug() << "screenPos " << mc->screenPos().x() << ": " << mc->screenPos().y();
    }
    return QWidget::event(ev);
}
