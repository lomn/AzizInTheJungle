#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Accessoire.h"
#include <iostream>
#include <vector>


class Camouflage : public Accessoire
{
private:
    double m_coefCamouflage;

public:
    Camouflage(const Camouflage & copieCamouflage);
    Camouflage(double coefCamouflage);
    ~Camouflage();

    virtual char* getType() const;
    virtual double getCoefCamouflage() const;
    void setCoefCamouflage(double coefCarapace);
};


#endif
