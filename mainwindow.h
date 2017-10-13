#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* =================================================
 * This file is part of the TTK Download Limit project
 * Copyright (C) 2015 - 2015 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

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
