//
// Created by sella on 04/12/2020.
//

#ifndef AZIZINTHEJUNGLE_GREGAIRE_H
#define AZIZINTHEJUNGLE_GREGAIRE_H
#include "Comportement.h"
#include <array>

class Bestiole;

class Gregaire : public Comportement{
public:
    Gregaire();
    virtual std::array<double,2> calculVitesse(const Bestiole &b, std::vector<Bestiole> & list) override;
};


#endif //AZIZINTHEJUNGLE_GREGAIRE_H
