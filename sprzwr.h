#ifndef SPRZWR_H
#define SPRZWR_H

#include "syggen.h"

class SprZwr
{
    double m_poprz_y;
    double m_uchyb;

public:
    SprZwr();
    SprZwr(double y);
    double liczUchyb(double wejscie);
    double getUchyb() const;
    void setPoprzY(double y);
    double getPoprzY() const { return m_poprz_y; }
    void reset();
};

#endif // SPRZWR_H
