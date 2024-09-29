#ifndef QUEUETHREAD_H
#define QUEUETHREAD_H

#include "generatingthread.h"
#include <QQueue>
#include <QThread>

class QueueThread: public QThread {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(QueueThread)
public:
    QueueThread(GeneratingThread *genThread);
    void run() override;
public slots:
    void addNumber(quint16 number);
signals:
    void dequeueOccured(quint16 dequeuedNum);
    void updateQueue(const QList<quint16> &queue);
private:
    QQueue<quint16> queue;
    GeneratingThread *generatingThread;
    QMutex mutex;
};

#endif // QUEUETHREAD_H
