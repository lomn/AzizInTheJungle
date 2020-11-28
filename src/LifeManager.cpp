//
// Created by sella on 28/11/2020.
//

#include "LifeManager.h"
#include "Bestiole.h"

void LifeManager::step(std::vector<Bestiole> list) {
    for (int i=0; i<list.size(); i++){
            auto * b=static_cast<Bestiole*>(&(list[i]));
            if (b) { // si la bestiole existe (si elle n’a pas été tué avant)
                if (b->getLifeSpan() == 0) {
                    list.erase(list.begin() + i);
                }
                else {
                    // Verification colision
                    for (int j=0; j<list.size(); j++){
                        auto * otherB=static_cast<Bestiole*>(&(list[i]));
                        if (otherB){ // si elle a été tué au tour d’avant
                            if (i!=j){
                                // Définition d’une hitbox
                                if (intersect(b, otherB)) {
                                    double p_m=((double) rand() / (RAND_MAX));
                                    double p_m1=p_m, p_m2=p_m;
//                                    double p_m1 = p_m * b.getAccessoires().getCarapace().getCcoef;
//                                    double p_m2 = p_m * b.getAccessoires().getCarapace().getCcoef;
                                    if (p_m1<b->getPDeath()) list.erase(list.begin()+i);
                                    if (p_m2<otherB->getPDeath()) list.erase(list.begin()+j);

                                }
                            }
                        }
                    }
                    // Clonage
                    double p_c;
                    if (p_c < b->getPClone()){
                        list.push_back(Bestiole(*b));
                    }
                }
            }
    }

}

bool LifeManager::intersect(Bestiole &b1, Bestiole &b2) {
    return false;
}
