#pragma once

#include <QtWidgets/QWidget>
#include "ui_qeventtest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QEventTestClass; };
QT_END_NAMESPACE

class QEventTest : public QWidget
{
    Q_OBJECT

public:
    QEventTest(QWidget *parent = nullptr);
    ~QEventTest();
    //重载事件函数
    bool event(QEvent* ev);
    //键盘按下
    void keyPressEvent(QKeyEvent* event);

    //键盘松开
    void keyReleaseEvent(QKeyEvent* event);

    bool handleKeyPress(QKeyEvent* ev);

private:
    Ui::QEventTestClass *ui;
};

// x() y() 相对本地坐标
/*
QPoint windowPos()程序窗口坐标
screenPos() 屏幕坐标
QWidget::mapToGlobal(ev->pos());屏幕
*/