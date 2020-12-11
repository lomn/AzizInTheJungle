#include "../Bestiole.h"
#include "Perception.h"
#include "Oreilles.h"
#include "Yeux.h"
#include <vector>


Perception::Perception(){
    yeuxVect = std::vector<Yeux>();
    oreilleVect = std::vector<Oreilles>();
}

bool Perception::jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole){
    if (!oreilleVect.empty()){
        for (std::vector<Oreilles>::size_type i=0;i<oreilleVect.size();i++){
            if (oreilleVect[i].jeTeVois(thisBestiole, bestiole)){
                std::cout << "Perception par oreilles" << std::endl;
                return true;
            }
        }
    }
    if (!yeuxVect.empty()){
        for (std::vector<Oreilles>::size_type i=0;i<yeuxVect.size();i++){
            if (yeuxVect[i].jeTeVois(thisBestiole, bestiole)){
                std::cout << "Perception par yeux" << std::endl;
                return true;
            }
        }
    }
    return false;
}

void Perception::addYeux(const Yeux& y) {
    yeuxVect.push_back(y);
}

void Perception::addOreille(const Oreilles& o) {
    oreilleVect.push_back(o);
};