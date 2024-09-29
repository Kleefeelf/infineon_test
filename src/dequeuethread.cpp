#include "./header/dequeuethread.h"
#include "qdebug.h"

DequeueThread::DequeueThread(QueueThread *qThread)
    : running(true), m_number(0), queue(qThread) {}

void DequeueThread::run(){
    running = true;
    while (running) {
        QMutexLocker locker(&mutex);
        if (m_number != 0) {
            emit addNewNumber(m_number);
            m_number = 0;
        }
    }
}

void DequeueThread::stop() {
    running = false;
}

void DequeueThread::getNumber(quint16 number) {
    QMutexLocker locker(&mutex);
    m_number = number;
}
