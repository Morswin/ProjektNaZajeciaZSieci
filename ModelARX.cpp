 #include "ModelARX.h"
#include <numeric>
#include <QException>
#include <random>
// #include <QDebug>

ModelARX::ModelARX()
    : m_u_buffer{}
    , m_u_delay{}
    , m_y_buffer{}
    , m_a{}
    , m_b{}
    , m_k_opozn{ 1 }
    , m_zakl_rng{ true }
    , m_zakl_val{ 0.0 }
{}

ModelARX::ModelARX(std::vector<double> wsp_a, std::vector<double> wsp_b, int k, bool z, double z_val)
    : m_u_buffer{}
    , m_u_delay{}
    , m_y_buffer{}
    , m_a{ wsp_a }
    , m_b{ wsp_b }
    , m_zakl_rng{ z }
    , m_zakl_val{ z_val }
{
    setOpozn(k);
}

void ModelARX::addA(const double a)
{
    m_a.push_back(a);
}

void ModelARX::removeA(int index)
{
    if (index < static_cast<int>(m_a.size()))
        m_a.erase(m_a.begin() + index);
    else
        throw std::out_of_range("Invalid index!");
}

void ModelARX::clearA()
{
    m_a.clear();
}

void ModelARX::addB(const double b)
{
    m_b.push_back(b);
}

void ModelARX::removeB(int index)
{
    if (index < static_cast<int>(m_b.size()))
        m_b.erase(m_b.begin() + index);
    else
        throw std::out_of_range("Invalid index!");
}

void ModelARX::clearB()
{
    m_b.clear();
}

void ModelARX::setZakl(bool isOn) {
    m_zakl_rng = isOn;
}

void ModelARX::setZaklWart(double zakl){
    m_zakl_val = zakl;
}

void ModelARX::setOpozn(int k)
{
    if (k >= 1)
        m_k_opozn = k;
    else
        throw std::out_of_range("K musi wynosić min. 1!");
}

double ModelARX::symuluj(const double sygn_wej)
{
    std::random_device s; std::mt19937 rng_zakl;
    std::normal_distribution<double> rozklad(0, m_zakl_val);
    double z{};
    if (getCzyZakl())
    {
        rng_zakl.seed(s());
        z = rozklad(rng_zakl);
    }
    else
        z = 0.0;

    if (static_cast<int>(m_u_delay.size()) <= m_k_opozn)
        m_u_delay.push_back(sygn_wej);

    if (static_cast<int>(m_u_delay.size()) > m_k_opozn) {
        m_u_buffer.push_front(m_u_delay.front());
        m_u_delay.pop_front();
    }

    if (m_u_buffer.size() > m_b.size()) m_u_buffer.pop_back();

    double splot_u_b = 0.0,
           splot_y_a = 0.0;

    splot_u_b = std::inner_product(m_u_buffer.begin(), m_u_buffer.end(), m_b.begin(), 0.0);
    splot_y_a = std::inner_product(m_y_buffer.begin(), m_y_buffer.end(), m_a.begin(), 0.0);

    double y = splot_u_b - splot_y_a + z;

    m_y_buffer.push_front(y);
    if(m_y_buffer.size() > m_a.size()) m_y_buffer.pop_back();

    // qInfo() << "BufWE: \t" << m_u_buffer.size()
    //         << "BufDelay: \t" << m_u_delay.size()
    //         << "BufWY: \t" << m_y_buffer.size()
    //         << '\n';

    return y;
}

void ModelARX::clearBuffers()
{
    m_u_buffer.clear();
    m_u_delay.clear();
    m_y_buffer.clear();
}
