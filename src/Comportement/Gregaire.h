/**
* @file Gregaire.h
* @brief Il s'agit d'un comportement de bestiole:  une bestiole dite grégaire ajuste sa direction sur la direction moyenne
* des bestioles environnantes.
 */
#ifndef AZIZINTHEJUNGLE_GREGAIRE_H
#define AZIZINTHEJUNGLE_GREGAIRE_H
#include "Comportement.h"
#include <array>

class Bestiole;
/**
 * @brief comportement: ajuste sa direction à la direction moyenne des bestioles enviironnantes
 */
class Gregaire : public Comportement{
public:
    Gregaire();
    virtual std::array<double,2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list) override;
};


#endif //AZIZINTHEJUNGLE_GREGAIRE_H
