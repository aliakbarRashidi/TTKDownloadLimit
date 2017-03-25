#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QMainWindow>
#include <QNetworkReply>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class QFile;
class QNetworkAccessManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startRequest(const QUrl &url);

private slots:
    void startToDownload();
    void downLoadFinished();
    void downLoadReadyRead();
    void updateDownloadSpeed();
    void autoDownloadPressed();
    void limitDownloadPressed();
    void limitValueBoxChanged(int value);
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void replyError(QNetworkReply::NetworkError error);

private:
    void deleteAll();
    QString sizeStandardization(qint64 size);
    QString timeStandardization(qint64 time);

    Ui::MainWindow *ui;
    QFile *m_file;
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;
    qint64 m_received, m_total;
    qint64 m_limitValue;
    QTimer m_timer;

};

#endif // MAINWINDOW_H
