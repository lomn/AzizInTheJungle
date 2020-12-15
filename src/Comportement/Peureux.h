/**
* @file Peureux.h
* @brief Il s'agit d'un comportement de bestiole:  lorsque le nombre de bestioles autour d’une bestiole dite peureuse
* devient trop important, celle-ci fuit à vive allure dans la direction opposée avant de reprendre sa
* vitesse de croisière.
 */

#ifndef AZIZINTHEJUNGLE_PEUREUX_H
#define AZIZINTHEJUNGLE_PEUREUX_H
#include "Comportement.h"

class Bestiole;

class Peureux: public Comportement {

private:
    int scare_count;
    double vitesse_calme;

public:
    Peureux();
    virtual std::array<double,2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list) override;

};


#endif //AZIZINTHEJUNGLE_PEUREUX_H
