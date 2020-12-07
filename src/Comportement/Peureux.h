//
// Created by sella on 04/12/2020.
//

#ifndef AZIZINTHEJUNGLE_PEUREUX_H
#define AZIZINTHEJUNGLE_PEUREUX_H
#include "Comportement.h"


class Peureux: Comportement {

private:
    int scare_count;

public:
    Peureux();
    std::array<double,2> calculVitesse(const Bestiole &b, std::vector<Bestiole> & list) override;
    void setScare_count(int scare);
    int getScare_count();

};


#endif //AZIZINTHEJUNGLE_PEUREUX_H
