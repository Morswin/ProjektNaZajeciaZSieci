#ifndef KONTROLAPOLACZENIA_H
#define KONTROLAPOLACZENIA_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class KontrolaPolaczenia : public QObject
{
    Q_OBJECT
public:
    explicit KontrolaPolaczenia(QObject *parent = nullptr);
    void polacz_z_urzadzeniem(QString ip, int port);
    void hostuj(int port);
    QString get_ip();
    void set_ip(QString ip);
    bool get_server_started();
    void rozlacz();

signals:
    // Klient
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);
    // Server
    void newClientConnected(QTcpSocket *);

private slots:
    void on_client_connecting();

private:
    QTcpSocket m_socket;
    QString m_ip;
    int m_port;
    QTcpServer* m_server = nullptr;
    QList<QTcpSocket *> m_sockets;
    bool m_server_started = false;
};

#endif // KONTROLAPOLACZENIA_H
