#ifndef  DequeueETHREAD_H
#define  DequeueETHREAD_H

#include "queuethread.h"

class DequeueThread: public QThread {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(DequeueThread)
public:
    DequeueThread(QueueThread *queueThread);
    void run() override;
    void stop();
public slots:
    void getNumber(quint16 number);
signals:
    void addNewNumber(quint16 number);
private:
    bool running;
    quint16 m_number;
    QueueThread *queue;
    QMutex mutex;
};

#endif //  DEQUEUEETHREAD_H
