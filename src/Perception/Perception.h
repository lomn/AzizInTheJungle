/**
* @file Perception.h
* @brief Il s'agit de la classe faisant la gestion des capteurs de la Bestiole. Elle détermine si une bestiole est capable
 * de détecter une autre
 */

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
    Perception(const Perception & p);
    ~Perception();
    Perception & operator=(const Perception & p);
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const;
    void addYeux(const Yeux& y);
    void addOreille(const Oreilles& o);
    const std::vector<Yeux> &getYeuxVect() const;

    const std::vector<Oreilles> &getOreilleVect() const;
};

#endif