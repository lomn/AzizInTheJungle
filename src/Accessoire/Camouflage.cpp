#include "Camouflage.h"

Camouflage::Camouflage(double coefCamouflage): Accessoire(){
    m_coefCamouflage = coefCamouflage;
}

Camouflage::Camouflage(const Camouflage & copieCamouflage): Accessoire(copieCamouflage){
    m_coefCamouflage = copieCamouflage.getCoefCamouflage();
}

//-_-_-

const char* Camouflage::getType() const {
    return "Camouflage";
}

double Camouflage::getCoefCamouflage() const {
    return m_coefCamouflage;
}

void Camouflage::setCoefCamouflage(double coefCamouflage){
    m_coefCamouflage = coefCamouflage;
}

Camouflage::~Camouflage() {}
