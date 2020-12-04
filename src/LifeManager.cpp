#include "LifeManager.h"
#include "Bestiole.h"
#include "BestioleUtil.h"

void quickDelete( int idx , std::vector<Bestiole> & list)
{
    list[idx] = list.back();
    list.pop_back();
}

void LifeManager::step(std::vector<Bestiole> & list, int xLim, int yLim) {
    std::cout << "Dans le manager"<<std::endl;
//    int nb_test=0;
    std::cout << "taille liste " << list.size() <<std::endl;
    int i=0;
    while ( i<list.size()){
            auto b=static_cast<Bestiole*>(&(list[i]));
            if (b) { // si la bestiole existe (si elle n’a pas été tué avant)
                if (b->getLifeSpan() <= 0) {
//                    list.erase(list.begin() + i);
                    quickDelete(i, list);
                    std::cout << "Mort de vieillesse"<<std::endl;
                    nb_mort++;
                }
                else {
                    // Verification colision
                    int j=i;
                    while (j<list.size()){
                        auto otherB=static_cast<Bestiole*>(&(list[j]));
                        if (otherB!=nullptr){ // si elle a été tué au tour d’avant
                            bool cond= (not (*b==*otherB));
                            if (cond){
                                // Définition d’une hitbox
                                nb_test++;
                                if (intersect(*b, *otherB)) {
                                    double p_m=((double) rand() / (RAND_MAX));
                                    double p_m1=p_m, p_m2=p_m;
//                                    double p_m1 = p_m * getCarapvalue(b->getAccessoires());
//                                    double p_m2 = p_m * getCarapvalue(otherB->getAccessoires());
                                    if (p_m1<b->getPDeath()) { //Destruction bestiole b
//                                        list.erase(list.begin()+i);
                                        quickDelete(i, list);
                                        std::cout << "Mort de collision"<<std::endl;
                                        nb_mort++;
                                    }
                                    else b->collide();
                                    if (p_m2<otherB->getPDeath()) { //Destruction otherB
//                                        list.erase(list.begin()+j);
                                        quickDelete(j, list);
                                        std::cout << "Mort de collision"<<std::endl;
                                        nb_mort++;
                                    }
                                    else otherB->collide();

                                }
                            }
                        }
                        j++;
                    }
                    // Clonage
                    double p_c=((double) rand() / (RAND_MAX));
                    if (p_c < b->getPClone()){
                        std::cout << "Clonning"  << std::endl;
                        Bestiole bc = Bestiole(static_cast<Bestiole>(*b));
                        bc.initCoords(xLim, yLim);
                        list.push_back(bc);
                        nb_clon++;
                    }
                }
            }
            i++;
    }
//    std::cout << "Nombre d'intersections testées" << nb_test << std::endl;
}

bool LifeManager::intersect(const Bestiole &b1, const Bestiole &b2) {
    if (not (b1==b2)){
        double dist1 =  distanceBestiole(b1, b2);
        double v2 =  b1.getSize() + b2.getSize();
//        std::cout << "intersect :: " << dist1 << " < " << v2 << std::endl;
        return (dist1 < v2);
    }
    else {
        return false;
    }
}

void LifeManager::getStat() {
    std::cout << "Nombre de morts : " << nb_mort << " Nombre de clonages : " << nb_clon << std::endl;
}
