#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Accessoire.h"

/**
 * @brief Accessoire carapace: baisse la probabilité de mort par collision
 */
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
