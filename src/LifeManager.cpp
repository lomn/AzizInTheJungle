/*
 * Très peu optimisé ...
 */

#include "LifeManager.h"
#include "Bestiole.h"
#include "BestioleUtil.h"

void LifeManager::step(std::vector<Bestiole> & list) {
    std::cout << "dans le mana"<<std::endl;
    for (int i=0; i<list.size(); i++){
            auto b=static_cast<Bestiole*>(&(list[i]));
            if (b) { // si la bestiole existe (si elle n’a pas été tué avant)
                if (b->getLifeSpan() <= 0) {
                    list.erase(list.begin() + i);
                    std::cout << "Mort de vieillesse"<<std::endl;
                }
                else {
                    // Verification colision
                    for (int j=0; j<list.size(); j++){
                        auto otherB=static_cast<Bestiole*>(&(list[j]));
                        if (otherB!=nullptr){ // si elle a été tué au tour d’avant
                            bool cond= (not (*b==*otherB));
                            if (cond){
                                // Définition d’une hitbox
                                if (intersect(*b, *otherB)) {
                                    double p_m=((double) rand() / (RAND_MAX));
                                    double p_m1=p_m, p_m2=p_m;
//                                    double p_m1 = p_m * getCarapvalue(b->getAccessoires());
//                                    double p_m2 = p_m * getCarapvalue(otherB->getAccessoires());
                                    if (p_m1<b->getPDeath()) {
                                        list.erase(list.begin()+i);
                                        std::cout << "Mort de collision"<<std::endl;
                                    }
                                    if (p_m2<otherB->getPDeath()) {
                                        list.erase(list.begin()+j);
                                        std::cout << "Mort de collision"<<std::endl;
                                    }

                                }
                            }
                        }
                    }
                    // Clonage
                    double p_c=((double) rand() / (RAND_MAX));
                    if (p_c < b->getPClone()){
                        std::cout << "Clonning"  << std::endl;
                        Bestiole bc = Bestiole(static_cast<Bestiole>(*b));
                        bc.initCoords(300, 300);
                        list.push_back(bc);
                    }
                }
            }
    }

}

bool LifeManager::intersect(Bestiole &b1, Bestiole &b2) {
    if (not (b1==b2)){
        double dist1 =  distanceBestiole(b1, b2);
        double v2 =  b1.getSize() + b2.getSize();
        std::cout << "intersect :: " << dist1 << " < " << v2 << std::endl;
        return (dist1 < v2);
    }
    else {
        return false;
    }
}
