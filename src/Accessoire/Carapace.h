#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Accessoire.h"


class Carapace : public Accessoire
{
private:
    double m_coefCarapace;

public:
    Carapace(const Carapace & copieCarapace);
    Carapace(double coefCarapace);
    ~Carapace();

    virtual const char* getType() const override;
    virtual double getCoefCarapace() const override;
    void setCoefCarapace(double coefCarapace);
};


#endif
