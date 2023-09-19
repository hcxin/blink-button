#pragma once

#include <QObject>
#include <QThread>
#include <QApplication>

/**
 * @author xinhaichen
 */
class BlinkThread: public QThread {
Q_OBJECT

signals:
    void blinkSignal();

protected:
    void run();

};
