#ifndef MODELARX_H
#define MODELARX_H

#include <queue>
#include <vector>

class ModelARX
{
    std::deque<double> m_u_buffer;
    std::deque<double> m_u_delay;
    std::deque<double> m_y_buffer;
    std::vector<double> m_a;
    std::vector<double> m_b;
    int m_k_opozn;
    bool m_zakl_rng;
    double m_zakl_val;

    void decrK() { --m_k_opozn; }

public:
    ModelARX();
    ModelARX(std::vector<double> wsp_a, std::vector<double> wsp_b, int k = 1, bool z = false, double z_val = 0.0);
    void addA(const double a);
    // void removeA(int index);
    void clearA();
    void addB(const double b);
    // void removeB(int index);
    void clearB();
    void setOpozn(int k);
    void setZakl(bool isOn);
    void setZaklWart(double zakl);
    const std::vector<double>& getARX_a_vector() const;
    const std::vector<double>& getARX_b_vector() const;
    int getOpozn() const { return m_k_opozn; }
    bool getCzyZakl() const { return m_zakl_rng; }
    double getZakl() const { return m_zakl_val; }
    void clearBuffers();
    bool isAEmpty() const { return m_a.empty(); }
    bool isBEmpty() const { return m_b.empty(); }

    double symuluj(const double sygn_wej);
};

#endif // MODELARX_H
