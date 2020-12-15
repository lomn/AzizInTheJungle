/**
* @file Comportement.h
* @brief Il s'agit de la classe comportement ddont hérite tout les comportements
 */

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
    virtual std::array<double, 2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list);
    virtual const char* getNom(){return nom;};
};


#endif //AZIZINTHEJUNGLE_COMPORTEMENT_H
