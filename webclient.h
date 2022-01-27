#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"

#include <QTcpSocket>
#include <QAbstractSocket>

class webclient : public QWidget, private Ui::webclient
{
    Q_OBJECT

public:
    explicit webclient(QWidget *parent = nullptr);

    void connected();
    void readyRead();

private slots:
    void on_GoButton_clicked();
private:
    QTcpSocket *m_socket;
    QString m_hostname;

    unsigned short m_port = 80;
};

#endif // WEBCLIENT_H
