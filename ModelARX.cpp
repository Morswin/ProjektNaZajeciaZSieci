#include "ModelARX.h"
#include <numeric>
#include <QException>
#include <random>
// #include <QDebug>

ModelARX::ModelARX() //kosntruktor
    : m_u_buffer{}
    , m_u_delay{}
    , m_y_buffer{}
    , m_a{}
    , m_b{}
    , m_k_opozn{ 1 }
    , m_zakl_rng{ false }
    , m_zakl_val{ 0.0 }
{}

ModelARX::ModelARX(std::vector<double> wsp_a, std::vector<double> wsp_b, int k, bool z, double z_val) //konstruktor 2
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

void ModelARX::addA(const double a) //dodaje zmienne a do wektora
{
    m_a.push_back(a);
}

// void ModelARX::removeA(int index)
// {
//     if (index < static_cast<int>(m_a.size()))
//         m_a.erase(m_a.begin() + index);
//     else
//         throw std::out_of_range("Invalid index!");
// }

void ModelARX::clearA()
{
    m_a.clear();
}

void ModelARX::addB(const double b) //dodaje zmienne b do odpowiedniego wektora
{
    m_b.push_back(b);
}

// void ModelARX::removeB(int index)
// {
//     if (index < static_cast<int>(m_b.size()))
//         m_b.erase(m_b.begin() + index);
//     else
//         throw std::out_of_range("Invalid index!");
// }

void ModelARX::clearB()
{
    m_b.clear();
}

void ModelARX::setZakl(bool isOn) { //flaga na włączanie i wyłączanie zakłóceń
    m_zakl_rng = isOn;
}

void ModelARX::setZaklWart(double zakl){ //ustawianie zakłóceń
    m_zakl_val = zakl;
}

const std::vector<double>& ModelARX::getARX_a_vector() const
{
    return m_a;
}

const std::vector<double>& ModelARX::getARX_b_vector() const
{
    return m_b;
}

void ModelARX::setOpozn(int k) //Ustawienie opóźnienia
{
    if (k >= 1)
        m_k_opozn = k;
    else
        throw std::out_of_range("K musi wynosić min. 1!");
}

double ModelARX::symuluj(const double sygn_wej) //Mięsko, czyli symulacja
{
    double z{};

    if (getCzyZakl() && m_zakl_val != 0.0) //sprawdza warunki dotycznące zakłócenia
    {
        std::random_device s; std::mt19937 rng_zakl; //posiew i ranodmowe
        std::normal_distribution<double> rozklad(0, m_zakl_val); //ustawienie rozkładu
        rng_zakl.seed(s());
        z = rozklad(rng_zakl); //ustawienie zakłócenia na odpowiednie value
    }
    else
        z = 0.0; //Nie ma wartości, nie ma zakłóceń

    if (static_cast<int>(m_u_delay.size()) <= m_k_opozn) //Obsłóga opóźnienia. Jeśli tablica delay jest mniejsza niż wartość opóźnienia
        m_u_delay.push_back(sygn_wej); //Wartości są wrzucane do tablicy z delayem.

    if (static_cast<int>(m_u_delay.size()) > m_k_opozn) { //jak już tablica robi się większa niź obóźnienia
        m_u_buffer.push_front(m_u_delay.front()); //Wrzuca do "głównej" tablicy
        m_u_delay.pop_front(); //po czym usówa wartość z początku tablicy.
    }

    if (m_u_buffer.size() > m_b.size()) m_u_buffer.pop_back(); //czyszczenie tablicy na bierząco na podstawie rozmiaru b.

    double splot_u_b = 0.0,
           splot_y_a = 0.0;

    splot_u_b = std::inner_product(m_u_buffer.begin(), m_u_buffer.end(), m_b.begin(), 0.0); //Obliczanie iloczynu skalarnego dwóch wektórów, tak twierdzi internet
    splot_y_a = std::inner_product(m_y_buffer.begin(), m_y_buffer.end(), m_a.begin(), 0.0); //Czyli to są wyniki tego śmiesznego mnożenia, ale *fancy*

    double y = splot_u_b - splot_y_a + z; //ewidentnie wynik tego co się dzieje na górze

    m_y_buffer.push_front(y); //tablica Y 'aktualna'???
    if(m_y_buffer.size() > m_a.size()) m_y_buffer.pop_back(); //kontrola wielkości wektora

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
