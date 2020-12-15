/**
* @file Prevoyant.h
* @brief Il s'agit d'un comportement possible de la bestiole, elle est sensée permettre à la bestiole de prévoir le
 * mouvement des bestioles environnantes et d'éviter la collision en accord avec sa prévision
 * Elle n'a pas été implémentée
 */

#ifndef AZIZINTHEJUNGLE_PREVOYANT_H
#define AZIZINTHEJUNGLE_PREVOYANT_H
#include "Comportement.h"

class Bestiole;

class Prevoyant: public Comportement {
public:
    Prevoyant();
    virtual std::array<double, 2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list) override;
};


#endif //AZIZINTHEJUNGLE_PREVOYANT_H
