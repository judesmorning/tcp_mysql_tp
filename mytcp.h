#ifndef MYTCP_H
#define MYTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>

class Mytcp : public QObject
{
    Q_OBJECT
public:
    explicit Mytcp(QObject *parent = nullptr);
    void connect(QString ip, uint port);
signals:
    void getSourceDataSignal(QByteArray ba);
    void connectSignal(QString ip, uint port);
private slots:
    void connectSlot(QString ip,uint port);
    void recSlot();
    void tcpStateChangeSlot(QAbstractSocket::SocketState socketState);
private:
    QTcpSocket *socket;
};

#endif // MYTCP_H
