/**
* @file Kamikaze.h
* @brief Il s'agit d'un comportement de bestiole:  une bestiole dite kamikaze est attirée par la bestiole la plus proche et
* tente de l’attaquer en cherchant à provoquer une collision
 */

#ifndef AZIZINTHEJUNGLE_KAMIKAZE_H
#define AZIZINTHEJUNGLE_KAMIKAZE_H
#include "Comportement.h"
#include <array>

class Bestiole;

class Kamikaze : public Comportement {
public:
    Kamikaze();
    virtual std::array<double, 2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list) override;
};


#endif //AZIZINTHEJUNGLE_KAMIKAZE_H
