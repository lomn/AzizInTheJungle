#ifndef AZIZINTHEJUNGLE_PEUREUX_H
#define AZIZINTHEJUNGLE_PEUREUX_H
#include "Comportement.h"

class Bestiole;

class Peureux: public Comportement {

private:
public:
    Peureux();
    virtual std::array<double,2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list) override;
};


#endif //AZIZINTHEJUNGLE_PEUREUX_H
