#ifndef _NAGEOIRE_H_
#define _NAGEOIRE_H_

#include "Accessoire.h"


class Nageoire : public Accessoire
{
private:
    double m_coefNageoire;

public:
    Nageoire(const Nageoire & copieNageoire);
    Nageoire(double coefNageoire);
    ~Nageoire();

    virtual char* getType() const;
    virtual double getCoefNageoire() const;
    void setCoefNageoire(double coefNageoire);
};


#endif
