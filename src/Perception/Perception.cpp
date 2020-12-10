#include "../Bestiole.h"
#include "Perception.h"
#include "Oreilles.h"
#include "Yeux.h"
#include <vector>


Perception::Perception(Bestiole *bestiole){
    bestioleMaitre = bestiole;
    yeuxVect = std::vector<Yeux>();
}

bool Perception::jeTeVois(const Bestiole & bestiole){
    if (!oreilleVect.empty()){
        for (std::vector<Oreilles>::size_type i=0;i<oreilleVect.size();i++){
            if (oreilleVect[i].jeTeVois(bestiole)){
                return true;
            }
        }
    }
    if (!yeuxVect.empty()){
        for (std::vector<Oreilles>::size_type i=0;i<yeuxVect.size();i++){
            if (yeuxVect[i].jeTeVois(bestiole)){
                return true;
            }
        }
    }
    return false;
}

void Perception::addYeux(Yeux y) {
    yeuxVect.push_back(y);
}

void Perception::addOreille(Oreilles o) {
    oreilleVect.push_back(o);
};