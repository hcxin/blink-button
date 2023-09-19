#include "blink_thread.h"

/**
 * @author xinhaichen
 */
void BlinkThread::run() {
    while (!isInterruptionRequested()) {
        QThread::msleep(500);
        qInfo("--run--");
        emit blinkSignal();
    }
}
