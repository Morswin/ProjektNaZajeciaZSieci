#include "sprzwr.h"

SprZwr::SprZwr()
    : m_poprz_y{ 0.0 }
    , m_uchyb{ 0.0 }
{}

SprZwr::SprZwr(double y)
    : m_poprz_y{ y }
{}

double SprZwr::liczUchyb(double sygn)
{
    double e = sygn - getPoprzY();
    m_uchyb = e;
    return e;
}

double SprZwr::getUchyb() const {
    return m_uchyb;
}

void SprZwr::setPoprzY(double y)
{
    m_poprz_y = y;
}

void SprZwr::reset()
{
    setPoprzY(0.0);
}
