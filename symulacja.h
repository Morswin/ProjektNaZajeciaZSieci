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

    double symulujKrok_IConstOut(bool is_klient=false, double klient_input=0.0);
    double symulujKrok_IConstIn(bool is_klient=false, double klient_input=0.0);
    void symulujKrokBypassARX(double arx, bool pid_in);
    void setSygnAmp(double amp);
    void setSygnWyp(double wyp);
    void setSygnOkrAkt(double okr_akt);
    void setSygnStala(double st);
    void setPID_k(double k);
    void setPID_tI(double tI);
    void setPID_tD(double tD);
    void setPID_adjust_mem_on_change(bool isToggled);
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
    void setARX_z_val(double z_val);
    void clearARXBuffers();
    bool isAEmpty() const { return m_arx.isAEmpty(); }
    bool isBEmpty() const { return m_arx.isBEmpty(); }
    const std::vector<double>& getARX_a_vector() const;
    const std::vector<double>& getARX_b_vector() const;
    int getARX_k() const;
    bool getARX_isZ() const;
    double getARX_z_std_dev() const;
    void liczSygnalSkok();
    void liczSygnalKwad();
    void liczSygnalSin();
    // void liczSygnalSkok(double amp, int krok_aktyw);
    // void liczSygnalKwad(double amp, int okr, double wyp);
    // void liczSygnalSin(double amp, int okr);
    double getSygn() const;
    void resetInternalKrok();
    double getUchyb();
    void resetUchyb();
};

#endif // SYMULACJA_H
