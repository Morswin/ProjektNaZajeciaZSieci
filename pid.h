#ifndef ModelPID_H
#define ModelPID_H

class ModelPID
{
    double k;
    double tI;
    double tD;
    double I_result;
    double D_result;
    double pamiecCalk;
    double pamiecRozn;
    double PID_result;
public:
    ModelPID();
    ModelPID(double tempK, double tempTI, double tempTD);
    ~ModelPID();
    double getI() const { return I_result; }
    double getD() const { return D_result; }
    double getPID() const { return PID_result; }
    void ustawK(double tempK);
    void ustawTI(double tempTI);
    void ustawTD(double tempTD);
    void resetujPamiecCalk();
    void resetujPamiecRozn();
    void resetujPamiec();
    double czescProp(double eI);
    double czescCalk(double eI);
    double czescRozn(double eI);
    double symulujKrokPID(double eI);
};

#endif // ModelPID_H
