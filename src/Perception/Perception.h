#ifndef _PERCEPTION_H_
#define _PERCEPTION_H_

#include <vector>
#include "Oreilles.h"
#include "Yeux.h"

class Bestiole;

class Perception {
private:
    std::vector<Yeux> yeuxVect;
    std::vector<Oreilles> oreilleVect;

public:
    Perception();
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole);
    void addYeux(Yeux y);
    void addOreille(Oreilles o);
};

#endif