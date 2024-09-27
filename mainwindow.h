#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "queuethread.h"
#include "generatingthread.h"
#include "dequeuethread.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void genThreadToggle();
    void deqThreadToggle();
    void updateGenList(quint16 newNumber);
    void updateQueueList(const QList<quint16> &queue);
    void updateDequeuedList(quint16 newNumber); // список всіх хто вийшов з черги
private:
    Ui::MainWindow *ui;
    GeneratingThread *generatingThread;
    QueueThread *queueThread;
    DequeueThread *dequeueThread;
};
#endif // MAINWINDOW_H
