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
    //�����¼�����
    bool event(QEvent* ev);
    //���̰���
    void keyPressEvent(QKeyEvent* event);

    //�����ɿ�
    void keyReleaseEvent(QKeyEvent* event);

    bool handleKeyPress(QKeyEvent* ev);

private:
    Ui::QEventTestClass *ui;
};

// x() y() ��Ա�������
/*
QPoint windowPos()���򴰿�����
screenPos() ��Ļ����
QWidget::mapToGlobal(ev->pos());��Ļ
*/