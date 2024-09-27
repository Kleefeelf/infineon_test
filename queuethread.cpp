#include "queuethread.h"

QueueThread::QueueThread(GeneratingThread *genThread): generatingThread(genThread) {
    connect(generatingThread, &GeneratingThread::newNumberGenerated, this, &QueueThread::addNumber);
}
void QueueThread::run() {
    while (true) {
        mutex.lock();
        if (queue.size() >= 20) {
            quint16 dequeuedNum = queue.dequeue();
            emit dequeueOccured(dequeuedNum);
        }
        mutex.unlock();
    }
}


void QueueThread::addNumber(quint16 number) {
    mutex.lock();
    queue.enqueue(number);
    emit updateQueue(queue.toList());
    mutex.unlock();
}
