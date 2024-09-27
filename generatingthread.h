#ifndef GENERATINGTHREAD_H
#define GENERATINGTHREAD_H

#include "qthread.h"
#include "qtmetamacros.h"
#include <QMutex>

class GeneratingThread: public QThread {
    Q_OBJECT
public:
    GeneratingThread();
    void run() override;
    void stop();
    quint16 getNumber();
signals:
    void newNumberGenerated(quint16 newNumber);
private:
    quint16 number;
    bool running;
    QMutex mutex;
};

#endif // GENERATINGTHREAD_H
