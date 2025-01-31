#ifndef SYGGEN_H
#define SYGGEN_H

class SygGen
{
    int m_krok;
    double m_sygn;

public:
    SygGen();
    void setSygn(double sygnal) { m_sygn = sygnal; }
    double sygnalSkok(double amp, int krok_aktyw);
    double sygnalKwad(double amp, int okr, double wyp);
    double sygnalSin(double amp, int okr);
    int getKrok() const { return m_krok; }
    double getSygn() const { return m_sygn; }
    void krokDalej() { ++m_krok; }
    void resetInternalKrok() { m_krok = 0; }
};

#endif // SYGGEN_H
