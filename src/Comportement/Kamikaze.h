//
// Created by sella on 04/12/2020.
//

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
