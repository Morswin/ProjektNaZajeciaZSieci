#include "syggen.h"
#include <QtMath>
#include <stdexcept>

SygGen::SygGen()
    : m_krok{ 0 }
    , m_sygn{ 0.0 }
{}

double SygGen::sygnalSkok(double amp, int krok_aktyw) {
    if (amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

    if (getKrok() >= krok_aktyw) {
        krokDalej();
        setSygn(amp);
        return amp;
    }
    else {
        krokDalej();
        setSygn(0.0);
        return 0.0;
    }
}

double SygGen::sygnalKwad(double amp, int okr, double wyp) {
    if (amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

    if ((getKrok() % okr) < (wyp * okr)) {
        setSygn(amp);
        krokDalej();
        return amp;
    }
    else {
        setSygn(0.0);
        krokDalej();
        return 0.0;
    }

}

double SygGen::sygnalSin(double amp, int okr) {
    if (amp < 0.0) throw std::out_of_range("Amp musi byc nieujemne");

    double wyjscie = amp *(qSin(2 * M_PI * (getKrok() % okr)/okr - (M_PI/2)) + 1.0) / 2.0;
    setSygn(wyjscie);
    krokDalej();
    return wyjscie;
}

