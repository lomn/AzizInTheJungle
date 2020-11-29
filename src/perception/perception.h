#ifndef _PERCEPTION_H_
#define _PERCEPTION_H_

#include "../Bestiole.h"
#include<stdlib.h>

class Perception{
private: 
    Bestiole * bestioleMaitre;
    std::vector<Yeux> yeuxVect;
    std::Vector<Oreille> oreilleVect;

public:
    virtual jeTeVois(const Bestiole & bestiole);
};

#endif