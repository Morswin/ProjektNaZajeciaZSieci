#include "kontrolapolaczenia.h"

KontrolaPolaczenia::KontrolaPolaczenia(QObject *parent)
    : QObject{parent}
{
    connect(&m_socket, &QTcpSocket::connected, this, &KontrolaPolaczenia::connected);
    connect(&m_socket, &QTcpSocket::disconnected, this, &KontrolaPolaczenia::disconnected);
    connect(&m_socket, &QTcpSocket::stateChanged, this, &KontrolaPolaczenia::stateChanged);
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &KontrolaPolaczenia::errorOccurred);
}

void KontrolaPolaczenia::polacz_z_urzadzeniem(QString ip, int port)
{
    if (m_socket.isOpen())
    {
        if (ip == m_ip && port == m_port) return;
        m_socket.close();
    }
    m_ip = ip;
    m_port = port;
    m_socket.connectToHost(m_ip, m_port);
}

QString KontrolaPolaczenia::get_ip()
{
    return m_ip;
}
