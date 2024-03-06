#pragma once

#include <QtWidgets/QWidget>
#include "ui__test_qmouseevent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class _test_QMouseEventClass; };
QT_END_NAMESPACE

class _test_QMouseEvent : public QWidget
{
    Q_OBJECT

public:
    _test_QMouseEvent(QWidget *parent = nullptr);
    ~_test_QMouseEvent();

    bool event(QEvent* ev);

private:
    Ui::_test_QMouseEventClass *ui;
};
