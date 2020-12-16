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
/**
 * @brief classe gérant la perception d'une bestiole
 */
class Perception {
private:
    std::vector<Yeux> yeuxVect;              ///< vecteur contenant tout les capteurs de type Yeux
    std::vector<Oreilles> oreilleVect;       ///< vecteur contenant tout les capteurs de type Oreilles

public:
    Perception();                      ///< Constructeur
    Perception(const Perception & p);  ///< Constructeur par copie
    ~Perception();                     ///< Destructeur
    Perception & operator=(const Perception & p);
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const;
    void addYeux(const Yeux& y);              ///< ajout de Yeux
    void addOreille(const Oreilles& o);       ///< ajout de Oreilles
    const std::vector<Yeux> &getYeuxVect() const;           ///< getter du vector de Yeux
    const std::vector<Oreilles> &getOreilleVect() const;    ///< getter du vector de Oreilles
};

#endif