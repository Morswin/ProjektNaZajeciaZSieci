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

    m_timer = new QTimer(this);
    //connect(m_timer, &QTimer::timeout, this, &KontrolaPolaczenia::pingingTimer);

    connect(&m_socket, &QTcpSocket::readyRead, this, [this]() {
        QByteArray dane = m_socket.readAll();
        //qDebug() << "Odebrano dane z serwera:" << dane;
        emit dataRecived(dane);
    });
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

    isClient = true;
    qDebug()<<getIsClient();
    //m_timer->start();
}

void KontrolaPolaczenia::hostuj(int port)
{
    if (m_socket.isOpen()) m_socket.close();
    m_server_started = m_server->listen(QHostAddress::Any, port); // To zwraca bool, false jeśli port zajęty. Jak będą z tym błędy to tutaj trzeba potencjalnie ten edge case obsłużyć
    if(m_server_started){ isClient = false; }
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
    // Tutaj każdorazowo trzeba podpiąć odpowiednie sygnały żeby server mógł obsługiwać klientów osobno.

    if(!socket) return;

    m_sockets.append(socket);

    connect(socket, &QTcpSocket::disconnected, [this, socket]() {
        m_sockets.removeAll(socket);
        socket->deleteLater();
    });

    connect(socket, &QTcpSocket::readyRead, [this, socket]() {
        QByteArray data = socket->readAll();
    });

    emit newClientConnected(socket);
}

void KontrolaPolaczenia::rozlacz()
{
    m_socket.close();

    isClient = false;
}

void KontrolaPolaczenia::wyslijDoKlientow(const QByteArray &dane) {
    for (QTcpSocket* socket : m_sockets) {
        if (socket->state() == QAbstractSocket::ConnectedState) {
            socket->write(dane);
            socket->flush();
        }
    }
}

bool KontrolaPolaczenia::getIsClient() { return this->isClient; }

void KontrolaPolaczenia::setTimer(QTimer* t){
    if(!t) return;

    if (m_timer) {
        disconnect(m_timer, nullptr, this, nullptr);
    }

    m_timer = t;
}

QTimer* KontrolaPolaczenia::getTimer(){ return this->m_timer; }

QList<QTcpSocket*>* KontrolaPolaczenia::getSockets(){return &m_sockets;}

void KontrolaPolaczenia::set_client(bool c) {
    if (c) {
        isClient = true;
        m_server_started = false;
    }
    else {
        isClient = false;
    }
}

void KontrolaPolaczenia::set_server(bool s) {
    if (s) {
        m_server_started = true;
        isClient = false;
    }
    else {
        m_server_started = false;
    }
}

QTcpServer* KontrolaPolaczenia::get_serwer() {
    return m_server;
}

void KontrolaPolaczenia::klient_wyslij(QByteArray dane) {
    qDebug() << "Wysyłam to: " << dane;
    m_socket.write(dane);
    m_socket.flush();
}
