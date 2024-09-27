#include "generatingthread.h"
#include <QThread>

GeneratingThread::GeneratingThread() : number(0), running(true) {}

void GeneratingThread::run() {
    running = true;
    while(running) {
        QMutexLocker locker(&mutex);
        number++;
        emit newNumberGenerated(number);
        locker.unlock();
        QThread::msleep(300);
    }
}

void GeneratingThread::stop() {
    running = false;
}

quint16 GeneratingThread::getNumber() {
    QMutexLocker locker(&mutex);
    return number;
}
