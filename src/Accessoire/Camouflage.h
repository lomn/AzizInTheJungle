
#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Accessoire.h"
#include <iostream>
#include <vector>

/**
 * @brief Accessoire camouflage: rend la bestiole moins visible
 */
class Camouflage : public Accessoire
{
private:
    double m_coefCamouflage;

public:
    Camouflage(const Camouflage & copieCamouflage);
    Camouflage(double coefCamouflage);
    ~Camouflage();

    virtual const char* getType() const override;
    virtual double getCoefCamouflage() const override;
    void setCoefCamouflage(double coefCarapace);
};


#endif
