#include "qeventtest.h"
#include <QDebug>
#include <QKeyEvent>

QEventTest::QEventTest(QWidget* parent) : QWidget(parent), ui(new Ui::QEventTestClass()) {
    ui->setupUi(this);
    setMouseTracking(true);
}

QEventTest::~QEventTest() {
    delete ui;
}

bool QEventTest::event(QEvent* ev) {
    if (ev->type() == QEvent::KeyPress) {
        // 处理键盘按下事件
        return handleKeyPress(static_cast<QKeyEvent*>(ev));
    }
    return QWidget::event(ev);
}

bool QEventTest::handleKeyPress(QKeyEvent* ev) {
    if (ev->isAutoRepeat()) {
        return true; // 忽略自动重复按键事件
    }
    switch (ev->key()) {
    case Qt::Key_A:
        qDebug() << "Pressed 'A'";
        return true;
    case Qt::Key_Z:
        qDebug() << "Pressed 'Z'";
        return true;
    default:
        return QWidget::event(ev);
    }
}

void QEventTest::keyPressEvent(QKeyEvent* ev) {
    // 重载处理键盘按下事件
    if (!ev->isAutoRepeat()) {
        qDebug() << "keyPressEvent: " << ev->key();
    }
}

void QEventTest::keyReleaseEvent(QKeyEvent* ev) {
    // 重载处理键盘释放事件
    if (!ev->isAutoRepeat()) {
        qDebug() << "keyReleaseEvent: " << ev->key();
    }
}

.h文件

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
