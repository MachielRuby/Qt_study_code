#pragma once

#include <QLabel>
#include<QMouseEvent>
#include<QEvent>
#include<QLabel>
#include<QMenu>

class Xlabel  : public QLabel
{
	Q_OBJECT

public:
	Xlabel(QWidget *parent);
	~Xlabel();
	bool event(QEvent* ev);
	virtual void enterEvent(QEvent* event)
	{
		qDebug() << "enter event";
	}
	virtual void leaveEvent(QEvent* event)
	{
		qDebug() << "leave event";
	}
	virtual void mouseDoubleClickEvent(QMouseEvent* event)
	{
		qDebug() << "mouseDoubleClickEvent"<<event->pos().x()<<" : "<<event->pos().y();
	}
	virtual void mouseMoveEvent(QMouseEvent* event)
	{
		qDebug() << "mouseDoubleMoveEvent" << event->pos().x() << " : " << event->pos().y();
	}
	virtual void mousePressEvent(QMouseEvent* event) 
	{
		qDebug() << "mouseDoublePressEvent" << event->pos().x() << " : " << event->pos().y();
	}
	virtual void mouseReleaseEvent(QMouseEvent* event)
	{
		qDebug() << "mouseDoubleRealeaseEvent" << event->pos().x() << " : " << event->pos().y();
	}
private:
	QMenu menu;

};
