#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "../Bestiole.h"

class Oreilles{
private:
    const Bestiole * thisBestiole;
    double m_distance;

public:
    Oreilles(double distance, Bestiole & bestiole);
    Oreilles(const Oreilles & OreillesOrigine);
    ~Oreilles();

    double getDistance() const;
    bool jeTeVois(const Bestiole & bestiole);
};

#endif