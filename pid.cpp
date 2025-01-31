#include "PID.h"
// #include <iostream>

ModelPID::ModelPID()
    : k{}
    , tI{}
    , tD{}
    , I_result{}
    , D_result{}
    , pamiecCalk{0.0}
    , pamiecRozn{0.0}
{}

ModelPID::ModelPID(double tempK, double tempTI, double tempTD) : k{tempK}, tI{tempTI}, tD{tempTD}, pamiecCalk{0.0}, pamiecRozn{0.0} {

}

ModelPID::~ModelPID(){

}

void ModelPID::ustawK(double tempK){
    k = tempK;
}

void ModelPID::ustawTI(double tempTI){
    tI = tempTI;
}

void ModelPID::ustawTD(double tempTD){
    tD = tempTD;
}

void ModelPID::resetujPamiecCalk(){
    pamiecCalk = 0.0;
}

void ModelPID::resetujPamiecRozn(){
    pamiecRozn = 0.0;
}

void ModelPID::resetujPamiec(){
    resetujPamiecCalk();
    resetujPamiecRozn();
}

double ModelPID::czescProp(double eI){
    return k * eI;
}

double ModelPID::czescCalk(double eI){
    if (tI != 0) {
        pamiecCalk += eI;
        I_result = pamiecCalk / tI;
        return pamiecCalk / tI;
    }
    else
        return 0.0;
}

double ModelPID::czescRozn(double eI){
    double temp = tD * (eI - pamiecRozn);
    pamiecRozn = eI;
    D_result = temp;
    return temp;
}

double ModelPID::symulujKrokPID(double eI){
    double p_, i_, d_;
    p_ = czescProp(eI);
    i_ = czescCalk(eI);
    d_ = czescRozn(eI);
    PID_result = p_ + i_ + d_;
    return p_ + i_ + d_;
}
