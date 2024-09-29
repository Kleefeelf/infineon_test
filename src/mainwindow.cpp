#include "./header/mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , generatingThread(new GeneratingThread)
    , queueThread(new QueueThread(generatingThread))
    , dequeueThread(new DequeueThread(queueThread))

{
    ui->setupUi(this);

    connect(queueThread, &QueueThread::dequeueOccured, dequeueThread, &DequeueThread::getNumber);
    connect(ui->genButton, &QPushButton::clicked, this, &MainWindow::genThreadToggle);
    connect(ui->deqButton, &QPushButton::clicked, this, &MainWindow::deqThreadToggle);

    connect(generatingThread, &GeneratingThread::newNumberGenerated, this, &MainWindow::updateGenList);
    connect(queueThread, &QueueThread::updateQueue, this, &MainWindow::updateQueueList);
    connect(dequeueThread, &DequeueThread::addNewNumber, this, &MainWindow::updateDequeuedList);
    queueThread->start();
}

MainWindow::~MainWindow()
{
    if (generatingThread->isRunning()) {
        generatingThread->stop();
        generatingThread->terminate();
        generatingThread->wait();
    }

    if (dequeueThread->isRunning()) {
        dequeueThread->stop();
        generatingThread->terminate();
        dequeueThread->wait();
    }

    if (queueThread->isRunning()) {
        queueThread->terminate();
        queueThread->wait();
    }

    delete dequeueThread;
    delete queueThread;
    delete generatingThread;
    delete ui;

    qDebug() << "Deleted all threads";
}

void MainWindow::genThreadToggle() {
    ui->genButton->setText("Stop 1 thread");
    if (generatingThread->isRunning()) {
        generatingThread->stop();
        generatingThread->wait();
        ui->genButton->setText("Start 1 thread");
    }
    else {
        generatingThread->start();
    }
}

void MainWindow::deqThreadToggle() {
    ui->deqButton->setText("Stop 3 thread");
    if (dequeueThread->isRunning()) {
        dequeueThread->stop();
        dequeueThread->wait();
        ui->deqButton->setText("Start 3 thread");
    }
    else {
        dequeueThread->start();
    }
}

void MainWindow::updateGenList(quint16 newNumber) {
    ui->genListWidget->addItem(QString::number(newNumber));
}

void MainWindow::updateQueueList(const QList<quint16> &queue) {
    ui->queueListWidget->clear();
    for (quint16 number : queue) {
        ui->queueListWidget->addItem(QString::number(number));
    }
}

void MainWindow::updateDequeuedList(quint16 newNumber) {
    ui->dequeueListWidget->addItem(QString::number(newNumber));
}

