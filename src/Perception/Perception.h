#ifndef _PERCEPTION_H_
#define _PERCEPTION_H_

#include <vector>
#include "Oreilles.h"
#include "Yeux.h"

class Bestiole;

class Perception {
private:
    Bestiole * bestioleMaitre;
    std::vector<Yeux> yeuxVect;
    std::vector<Oreilles> oreilleVect;

public:
    Perception(): Perception(nullptr){};
    Perception(Bestiole * bestiole);
    bool jeTeVois(const Bestiole & bestiole);
    void addYeux(Yeux y);
    void addOreille(Oreilles o);
};

#endif