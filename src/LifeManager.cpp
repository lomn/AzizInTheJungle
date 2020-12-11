#include "LifeManager.h"
#include "Bestiole.h"
#include "BestioleUtil.h"

void quickDelete( int idx , std::vector<Bestiole> & list)
{
    list[idx] = list.back();
    list.pop_back();
}

void LifeManager::step(std::vector<Bestiole> & list, int xLim, int yLim) {
    void LifeManager::step(std::vector<Bestiole> & lst, int xLim, int yLim) {
    std::cout << "[L] ";
    showAll(lst);
    
    for(size_t i = lst.size()-1; ((int)i) >= 0; i--) 
    {
        Bestiole * besti = & lst[i];
        std::cout << "[L] " << besti->getIdentite() << "\n";

            if (besti->getLifeSpan() <= 0) 
            {
                std::cout << "[L] Mort de vieillesse, id : "<<  besti->getIdentite() << " life span : " << besti->getLifeSpan() <<std::endl;
                lst.erase(lst.begin()+i);
                nb_mort++;
            }
            else
            {
                for(size_t j = i+1; ((int)j) <= lst.size(); j++)//erreur il faut parcourir dans l'autre sens pour la deuxième boucle
                {
                    Bestiole * bestj = & lst[j];
                    if(intersect(*besti, *bestj))
                    {
                        std::cout << "[L] Colision entre " <<  besti->getIdentite() << " et " << bestj->getIdentite() << std::endl;
                        double pi = ((double) rand()) / ((double) RAND_MAX);
                        double pj = ((double) rand()) / ((double) RAND_MAX);

                        if(pj < bestj->getPDeath())
                        {
                            std::cout << "[L] Mort par colision 2 : " << bestj->getIdentite() << std::endl;
                            //lst.erase(find(lst.begin(),lst.end(),*bestj));
                            slowDelete(bestj->getIdentite(), lst);
                        }
                        else{bestj->collide();}

                        if(pi < besti->getPDeath())
                        {
                            std::cout << "[L] Mort par colision 1 : " << besti->getIdentite() << std::endl;
                            //lst.erase(find(lst.begin(),lst.end(),*besti));//sa call le destructeur de lst.end wtf
                            slowDelete(besti->getIdentite(), lst);
                        }
                        else{besti->collide();}
                    }
                }
            }
            
    }
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
