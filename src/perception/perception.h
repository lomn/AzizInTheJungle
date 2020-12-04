#ifndef _PERCEPTION_H_
#define _PERCEPTION_H_

#include "../Bestiole.h"
#include<stdlib.h>
#include "Oreilles.h"
#include "Yeux.h"

class Perception{
private: 
    Bestiole * bestioleMaitre;
    std::vector<Yeux> yeuxVect;
    std::vector<Oreilles> oreilleVect;

public:
    bool jeTeVois(const Bestiole & bestiole);
};

#endif