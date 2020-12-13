//
// Created by sella on 04/12/2020.
//

#ifndef AZIZINTHEJUNGLE_COMPORTEMENT_H
#define AZIZINTHEJUNGLE_COMPORTEMENT_H
#include <vector>
#include <array>

class Bestiole;

class Comportement {
private:
    const char * nom;
public:
    Comportement();
    Comportement(const char * nom);
    virtual ~Comportement(){};
    virtual std::array<double, 2> calculVitesse(const Bestiole &b, std::vector<Bestiole> & list);
    virtual const char* getNom(){return nom;};
};


#endif //AZIZINTHEJUNGLE_COMPORTEMENT_H
