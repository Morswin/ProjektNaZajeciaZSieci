#include "kontrolapolaczenia.h"

KontrolaPolaczenia::KontrolaPolaczenia(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer(this);
    // Sloty serwera
    connect(m_server, &QTcpServer::newConnection, this, &KontrolaPolaczenia::on_client_connecting);
    // Sygnały klienta
    // Łokieć pięta, nie ma klienta
    connect(&m_socket, &QTcpSocket::connected, this, &KontrolaPolaczenia::connected);
    connect(&m_socket, &QTcpSocket::disconnected, this, &KontrolaPolaczenia::disconnected);
    connect(&m_socket, &QTcpSocket::stateChanged, this, &KontrolaPolaczenia::stateChanged);  // Tutaj lub w errorach przechwycić sygnał, jeśli reconnect się wiesza
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &KontrolaPolaczenia::errorOccurred);
}

void KontrolaPolaczenia::polacz_z_urzadzeniem(QString ip, int port)
{
    if (m_server_started) m_server->close();
    if (m_socket.isOpen())
    {
        if (ip == m_ip && port == m_port) return;
        m_socket.close();
    }
    m_ip = ip;
    m_port = port;
    m_socket.connectToHost(m_ip, m_port);
}

void KontrolaPolaczenia::hostuj(int port)
{
    if (m_socket.isOpen()) m_socket.close();
    m_server_started = m_server->listen(QHostAddress::Any, port); // To zwraca bool, false jeśli port zajęty. Jak będą z tym błędy to tutaj trzeba potencjalnie ten edge case obsłużyć
}

QString KontrolaPolaczenia::get_ip()
{
    return m_ip;
}

void KontrolaPolaczenia::set_ip(QString ip)
{
    m_ip = ip;
}

bool KontrolaPolaczenia::get_server_started()
{
    return m_server_started;
}

void KontrolaPolaczenia::on_client_connecting()
{
    auto socket = m_server->nextPendingConnection();
    emit newClientConnected();
}
