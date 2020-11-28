#include "Camouflage.h"

Camouflage::Camouflage(double coefCamouflage){
    m_coefCamouflage = coefCamouflage;
    return;
}

Camouflage::Camouflage(const Camouflage & copieCamouflage){
    m_coefCamouflage = copieCamouflage.getCoefCamouflage();
}

//-_-_-

char* Camouflage::getType() const {
    return "Camouflage";
}

double Camouflage::getCoefCamouflage() const {
    return m_coefCamouflage;
}

void Camouflage::setCoefCamouflage(double coefCamouflage){
    m_coefCamouflage = coefCamouflage;
}
