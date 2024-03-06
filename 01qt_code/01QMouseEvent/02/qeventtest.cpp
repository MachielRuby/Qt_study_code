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
