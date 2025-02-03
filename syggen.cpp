#include "syggen.h"
#include <QtMath>
#include <stdexcept>
// #include <QDebug>

SygGen::SygGen()
    : m_krok{ 0 }
    , m_sygn{ 0.0 }
    , m_amp{ 0.0 }
    , m_wyp_kwad{ 0.0 }
    , m_okres_aktyw{ 0 }
{}

double SygGen::sygnalSkok() {
    if (m_amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

    // qInfo() << m_amp << '\t' << m_okres_aktyw;

    if (getKrok() >= m_okres_aktyw) {
        krokDalej();
        setSygn(m_amp);
        return m_amp;
    }
    else {
        krokDalej();
        setSygn(0.0);
        return 0.0;
    }
}

double SygGen::sygnalKwad() {
    if (m_amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

    if ((getKrok() % m_okres_aktyw) < (m_wyp_kwad * m_okres_aktyw)) {
        setSygn(m_amp);
        krokDalej();
        return m_amp;
    }
    else {
        setSygn(0.0);
        krokDalej();
        return 0.0;
    }

}

double SygGen::sygnalSin() {
    if (m_amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

    double wyjscie = m_amp *(qSin(2 * M_PI * (getKrok() % m_okres_aktyw)/m_okres_aktyw - (M_PI/2)) + 1.0) / 2.0;
    setSygn(wyjscie);
    krokDalej();
    return wyjscie;
}

// double SygGen::sygnalSkok(double amp, int krok_aktyw) {
//     if (amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

//     if (getKrok() >= krok_aktyw) {
//         krokDalej();
//         setSygn(amp);
//         return amp;
//     }
//     else {
//         krokDalej();
//         setSygn(0.0);
//         return 0.0;
//     }
// }

// double SygGen::sygnalKwad(double amp, int okr, double wyp) {
//     if (amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

//     if ((getKrok() % okr) < (wyp * okr)) {
//         setSygn(amp);
//         krokDalej();
//         return amp;
//     }
//     else {
//         setSygn(0.0);
//         krokDalej();
//         return 0.0;
//     }

// }

// double SygGen::sygnalSin(double amp, int okr) {
//     if (amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

//     double wyjscie = amp *(qSin(2 * M_PI * (getKrok() % okr)/okr - (M_PI/2)) + 1.0) / 2.0;
//     setSygn(wyjscie);
//     krokDalej();
//     return wyjscie;
// }

