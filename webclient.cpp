#include "webclient.h"

webclient::webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::connected, this, &webclient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &webclient::readyRead);
}

void webclient::connected()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n").toLocal8Bit());
}

void webclient::readyRead()
{
    u_output->setText(m_socket->readAll());
    m_socket->disconnectFromHost();
}

void webclient::on_GoButton_clicked()
{
    u_output->clear();

    m_hostname = u_hostname->text();
    m_socket->connectToHost(m_hostname, m_port);

    if(!m_socket->waitForConnected(6000))
    {
        u_output->setText("connection failed!");
    }
}
