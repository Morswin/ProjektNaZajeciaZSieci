#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "syggen.h"
#include "pid.h"
#include "ModelARX.h"
#include "sprzwr.h"

class Symulacja
{
    ModelARX m_arx;
    ModelPID m_pid;
    SygGen m_sygnal;
    SprZwr m_uchyb;
public:
    Symulacja();
    Symulacja(
        SygGen& sygn,
        double pid_k, double pid_ti, double pid_td,
        std::vector<double> arx_a, std::vector<double> arx_b, int arx_k, bool arx_z);

    double symulujKrok();
    void setPID_k(double k);
    void setPID_tI(double tI);
    void setPID_tD(double tD);
    void resetPID_I();
    void resetPID_D();
    double getPID_output();
    double getPID_P();
    double getPID_I();
    double getPID_D();
    void addARX_a(double single_a);
    void addARX_b(double single_b);
    void clearARX_a();
    void clearARX_b();
    void setARX_k(int k);
    void setARX_z(bool z);
    void clearARXBuffers();
    void liczSygnalSkok(double amp, int krok_aktyw);
    void liczSygnalKwad(double amp, int okr, double wyp);
    void liczSygnalSin(double amp, int okr);
    double getSygn() const;
    void resetInternalKrok();
    double getUchyb();
    void resetUchyb();
};

#endif // SYMULACJA_H
