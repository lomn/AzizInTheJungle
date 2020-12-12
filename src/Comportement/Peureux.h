//
// Created by sella on 04/12/2020.
//

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
    virtual std::array<double,2> calculVitesse(const Bestiole &b, std::vector<Bestiole> & list) override;
    void setScare_count(int scare);
    int getScare_count();
    double getVitesseCalme();
    void setVitesseCalme(double speedCalm);

};


#endif //AZIZINTHEJUNGLE_PEUREUX_H
