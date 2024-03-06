#include "xlabel.h"
#include<QEvent>
#include<QMouseEvent>
#include<qdebug.h>
#include<QPixmap>
Xlabel::Xlabel(QWidget *parent)
	: QLabel(parent)
{
    this->setMouseTracking(true);
    menu.addAction("菜单1");
    menu.addAction("菜单2");
    menu.addAction("菜单3");

}

Xlabel::~Xlabel()
{}
bool Xlabel::event(QEvent* ev)
{
    if (ev->type() == QEvent::MouseButtonPress)
    {
        //相对坐标
        QMouseEvent* mc = static_cast<QMouseEvent*>(ev);
        //qDebug() << "Local ";
        //qDebug() << "MouseButtonPress " << mc->x() << ": " << mc->y();
        ////程序坐标
        //qDebug() << "windowPos " << mc->windowPos().x() << ": " << mc->windowPos().y();
        ////屏幕坐标
        //qDebug() << "screenPos " << mc->screenPos().x() << ": " << mc->screenPos().y();
        ////本地坐标在转全局
        QPoint gpos = mapToGlobal(mc->pos());
        //qDebug() << "mapToGlobal " << gpos.x() << " : " << gpos.y();
        ////获取鼠标的坐标
        //qDebug() << "QCursor " << QCursor::pos().x() << " : " << QCursor::pos().y();
        ////鼠标按键事件
        if (mc->buttons() & Qt::LeftButton)
        {
            qDebug() << "Left";
            //鼠标替换
            QPixmap pix("cursor.jpg");
            QCursor cur = QCursor(pix, -1, -1);
            setCursor(cur);

        }
        if (mc->buttons() & Qt::RightButton)
        {
            qDebug() << "Right";
            menu.exec(gpos);
           
        }
        if (mc->buttons() & Qt::MiddleButton)
        {
            qDebug() << "Mid";
        }
        //qDebug() << "Main: ";

    }
    return QWidget::event(ev);
}
