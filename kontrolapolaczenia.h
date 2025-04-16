#ifndef KONTROLAPOLACZENIA_H
#define KONTROLAPOLACZENIA_H

#include <QObject>
#include <QTcpSocket>

class KontrolaPolaczenia : public QObject
{
    Q_OBJECT
public:
    explicit KontrolaPolaczenia(QObject *parent = nullptr);
    void polacz_z_urzadzeniem(QString ip, int port);
    QString get_ip();

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);

private:
    QTcpSocket m_socket;
    QString m_ip;
    int m_port;
};

#endif // KONTROLAPOLACZENIA_H
