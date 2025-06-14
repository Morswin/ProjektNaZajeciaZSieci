#include "symulacja.h"

Symulacja::Symulacja()
    : m_arx{}
    , m_pid{}
    , m_sygnal{}
    , m_uchyb{}
{}

Symulacja::Symulacja(SygGen& sygn,
                     double pid_k, double pid_ti, double pid_td,
                     std::vector<double> arx_a, std::vector<double> arx_b, int arx_k, bool arx_z)
    : m_arx{ arx_a, arx_b, arx_k, arx_z }
    , m_pid{ pid_k, pid_ti, pid_td }
    , m_sygnal{ sygn }
    , m_uchyb{}
{}

double Symulacja::symulujKrok_IConstOut(bool is_klient, double klient_input) {
    double wynik;
    if (!is_klient) {
        wynik = m_arx.symuluj(m_pid.symulujKrokPID_IConstOut(m_uchyb.liczUchyb(m_sygnal.getSygn())));
    }
    else {
        wynik = m_arx.symuluj(klient_input);
    }

    m_uchyb.setPoprzY(wynik);

    return wynik;
}

double Symulacja::symulujKrok_IConstIn(bool is_klient, double klient_input) {
    double wynik;
    if (!is_klient) {
        wynik = m_arx.symuluj(m_pid.symulujKrokPID_IConstIn(m_uchyb.liczUchyb(m_sygnal.getSygn())));
    }
    else {
        wynik = m_arx.symuluj(klient_input);
    }

    m_uchyb.setPoprzY(wynik);

    return wynik;
}

void Symulacja::symulujKrokBypassARX(double arx, bool pid_in) {
    m_uchyb.setPoprzY(arx);
    if (pid_in) {
        m_pid.symulujKrokPID_IConstIn(m_uchyb.liczUchyb(m_sygnal.getSygn()));
    }
    else {
        m_pid.symulujKrokPID_IConstOut(m_uchyb.liczUchyb(m_sygnal.getSygn()));
    }
}

void Symulacja::setSygnAmp(double amp) {
    m_sygnal.setAmp(amp);
}

void Symulacja::setSygnWyp(double wyp) {
    m_sygnal.setWyp(wyp);
}

void Symulacja::setSygnOkrAkt(double okr_akt) {
    m_sygnal.setOkrAkt(okr_akt);
}

void Symulacja::setSygnStala(double st) {
    m_sygnal.setStala(st);
}

void Symulacja::setPID_k(double k) {
    m_pid.ustawK(k);
}

void Symulacja::setPID_tI(double tI) {
    m_pid.ustawTI(tI);
}

void Symulacja::setPID_tD(double tD) {
    m_pid.ustawTD(tD);
}

void Symulacja::setPID_adjust_mem_on_change(bool isToggled) {
    m_pid.dostosujPamiec(isToggled);
}

void Symulacja::resetPID_I() {
    m_pid.resetujPamiecCalk();
}

void Symulacja::resetPID_D() {
    m_pid.resetujPamiecRozn();
}

double Symulacja::getPID_output() {
    return m_pid.getPID();
}

double Symulacja::getPID_P() {
    return m_pid.czescProp(m_uchyb.getUchyb());
}

double Symulacja::getPID_I() {
    return m_pid.getI();
}

double Symulacja::getPID_D() {
    return m_pid.getD();
}

void Symulacja::addARX_a(double single_a) {
    m_arx.addA(single_a);
}

void Symulacja::addARX_b(double single_b) {
    m_arx.addB(single_b);
}

void Symulacja::clearARX_a() {
    m_arx.clearA();
}

void Symulacja::clearARX_b() {
    m_arx.clearB();
}

void Symulacja::setARX_k(int k) {
    m_arx.setOpozn(k);
}

void Symulacja::setARX_z(bool z) {
    m_arx.setZakl(z);
}

void Symulacja::setARX_z_val(double z_val){
    m_arx.setZaklWart(z_val);
}

void Symulacja::clearARXBuffers() {
    m_arx.clearBuffers();
}

const std::vector<double>& Symulacja::getARX_a_vector() const
{
    return m_arx.getARX_a_vector();
}

const std::vector<double>& Symulacja::getARX_b_vector() const
{
    return m_arx.getARX_b_vector();
}

int Symulacja::getARX_k() const
{
    return m_arx.getOpozn();
}

bool Symulacja::getARX_isZ() const
{
    return m_arx.getCzyZakl();
}

double Symulacja::getARX_z_std_dev() const
{
    return m_arx.getZakl();
}

void Symulacja::liczSygnalSkok() {
    m_sygnal.sygnalSkok();
}

void Symulacja::liczSygnalKwad() {
    m_sygnal.sygnalKwad();
}

void Symulacja::liczSygnalSin() {
    m_sygnal.sygnalSin();
}

// void Symulacja::liczSygnalSkok(double amp, int krok_aktyw) {
//     m_sygnal.sygnalSkok(amp, krok_aktyw);
// }

// void Symulacja::liczSygnalKwad(double amp, int okr, double wyp) {
//     m_sygnal.sygnalKwad(amp, okr, wyp);
// }

// void Symulacja::liczSygnalSin(double amp, int okr) {
//     m_sygnal.sygnalSin(amp, okr);
// }

double Symulacja::getSygn() const {
    return m_sygnal.getSygn();
}

void Symulacja::resetInternalKrok() {
    m_sygnal.resetInternalKrok();
}

double Symulacja::getUchyb() {
    return m_uchyb.getUchyb();
}

void Symulacja::resetUchyb() {
    m_uchyb.reset();
}
