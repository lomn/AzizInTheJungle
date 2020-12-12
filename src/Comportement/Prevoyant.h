//
// Created by sella on 04/12/2020.
//

#ifndef AZIZINTHEJUNGLE_PREVOYANT_H
#define AZIZINTHEJUNGLE_PREVOYANT_H
#include "Comportement.h"

class Bestiole;

class Prevoyant: public Comportement {
public:
    Prevoyant();
    virtual std::array<double, 2> calculVitesse(const Bestiole &b, std::vector<Bestiole> & list) override;
};


#endif //AZIZINTHEJUNGLE_PREVOYANT_H
