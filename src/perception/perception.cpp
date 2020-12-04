#include "../Bestiole.h"
#include "perception.h"
#include<stdlib.h>
#include "Oreilles.h"
#include "Yeux.h"


Perception::Perception(Bestiole * bestiole,std::vector<Yeux> yeuxVectArg,std::vector<Oreilles> oreilleVectArg){
    bestioleMaitre = bestiole;
    yeuxVect = yeuxVectArg;
    oreilleVect = oreilleVectArg;
}

bool Perception::jeTeVois(const Bestiole & bestiole){
    if (oreilleVect.size()>0){
        for (int i=0;i<oreilleVect.size();i++){
            if (oreilleVect[i].jeTeVois(bestiole)){
                return true;
            }
        }
    }
    if (yeuxVect.size()>0){
        for (int i=0;i<yeuxVect.size();i++){
            if (yeuxVect[i].jeTeVois(bestiole)){
                return true;
            }
        }
    }
    return false;
}
;