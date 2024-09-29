#include "./header/queuethread.h"
#include "qdebug.h"

QueueThread::QueueThread(GeneratingThread *genThread): generatingThread(genThread) {
    connect(generatingThread, &GeneratingThread::newNumberGenerated, this, &QueueThread::addNumber);
}
void QueueThread::run() {
    while (true) {
        quint16 num;
        bool shouldEmit = false;
        {
            QMutexLocker locker(&mutex);
            if (queue.size() >= 20) {
                num = queue.dequeue();
                shouldEmit = true;
            }
        }
        if (shouldEmit) {
            emit dequeueOccured(num);
            emit updateQueue(queue.toList());
        }
    }
}


void QueueThread::addNumber(quint16 number) {
    QMutexLocker locker(&mutex);
    queue.enqueue(number);
    emit updateQueue(queue.toList());
}
