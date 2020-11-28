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

    virtual char* getType() const;
    virtual double getCoefCarapace() const;
    void setCoefCarapace(double coefCarapace);
};


#endif
