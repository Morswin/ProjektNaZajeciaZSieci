#ifndef SYGGEN_H
#define SYGGEN_H

class SygGen
{
    int m_krok;
    double m_sygn;

    double m_amp;
    double m_wyp_kwad;
    int m_okres_aktyw;  // na okres lub aktywację, w zależności od sygnalu

    void setSygn(double sygnal) { m_sygn = sygnal; }

public:
    SygGen();
    double sygnalSkok();
    double sygnalKwad();
    double sygnalSin();

    // double sygnalSkok(double amp, int krok_aktyw);
    // double sygnalKwad(double amp, int okr, double wyp);
    // double sygnalSin(double amp, int okr);

    void setAmp(double amp) { m_amp = amp; }
    void setWyp(double wyp) { m_wyp_kwad = wyp; }
    void setOkrAkt(double okr_akt) { m_okres_aktyw = okr_akt; }
    int getKrok() const { return m_krok; }
    double getSygn() const { return m_sygn; }
    void krokDalej() { ++m_krok; }
    void resetInternalKrok() { m_krok = 0; }
};

#endif // SYGGEN_H
