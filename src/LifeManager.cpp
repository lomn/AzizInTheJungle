#include "LifeManager.h"
#include "Bestiole.h"
#include "BestioleUtil.h"
#include <iomanip>

void quickDelete( int idx , std::vector<Bestiole> & list)
{
    list[idx] = list.back();
    list.pop_back();
}

void LifeManager::step(std::vector<Bestiole> & lst, int xLim, int yLim) {
    std::cout << "[L] Entering" << std::endl;
    for(size_t i = lst.size()-1; ((int)i) >= 0; i--) 
    {
        Bestiole * besti = & lst[i];
        std::cout << "[L] " << besti->getIdentite() << "\n";

            if (besti->getLifeSpan() <= 0) 
            {
                std::cout << "[L] Mort de vieillesse, id : "<<  besti->getIdentite() << " life span : " << besti->getLifeSpan() <<std::endl;
                lst.erase(lst.begin()+i);
                nb_mort[besti->getComportement()] = nb_mort[besti->getComportement()]+1;
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
                            lst.erase(lst.begin()+j);
                            nb_mort[bestj->getComportement()] = nb_mort[bestj->getComportement()]+1;
                        }
                        else{bestj->collide();}

                        if(pi < besti->getPDeath())
                        {
                            std::cout << "[L] Mort par colision 1 : " << besti->getIdentite() << std::endl;
                            lst.erase(lst.begin()+i);
                            nb_mort[besti->getComportement()] = nb_mort[besti->getComportement()]+1;
                        }
                        else{besti->collide();} //et bestj?
                    }
                }
            
                double p_c=((double) rand() / (RAND_MAX));
                if (p_c < lst[i].getPClone()){
                    std::cout << "Clonning : "  << lst[i].getIdentite() << std::endl;
                    Bestiole * bc = new Bestiole(lst[i]);
                    bc->initCoords(xLim, yLim);
                    lst.push_back(*bc);
                    nb_clon[lst[i].getComportement()]=nb_clon[lst[i].getComportement()]+1;
                    std::cout << "End clone" << std::endl;
                }
            }
    }
    std::cout << "[L] Exiting" << std::endl;
}

bool LifeManager::intersect(const Bestiole &b1, const Bestiole &b2) {
    if (not (b1==b2)){
        double dist1 =  distanceBestiole(b1, b2);
        double v2 =  b1.getSize() + b2.getSize();
        return (dist1 < v2);
    }
    else {
        return false;
    }
}

void LifeManager::getStat() {
    std::cout<< "********************   Statistiques morts  ********************" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << std::setfill('0');;
    int sum_mort=0;
    int sum_clon=0;
    for(size_t k = 0; k <4; k++){
        if (k==KAMIKAZE_IND)  std::cout<< "Kamikaze  ::Nombre de morts " << std::setw(3) << nb_mort[k] << " Nombre de clonages " << std::setw(3) << nb_clon[k] << std::endl;
        if (k==GREGAIRE_IND)  std::cout<< "Gregaire  ::Nombre de morts " << std::setw(3) << nb_mort[k] << " Nombre de clonages " << std::setw(3) << nb_clon[k] << std::endl;
        if (k==PEUREUX_IND)   std::cout<< "Peureux   ::Nombre de morts " << std::setw(3) << nb_mort[k] << " Nombre de clonages " << std::setw(3) << nb_clon[k] << std::endl;
        if (k==PREVOYANT_IND) std::cout<< "Prevoyant ::Nombre de morts " << std::setw(3) << nb_mort[k] << " Nombre de clonages " << std::setw(3) << nb_clon[k] << std::endl;
        sum_mort+=nb_mort[k];
        sum_clon+=nb_clon[k];
    }
    std::cout<< "Stats     ::Nombre de morts " << std::setw(3) << sum_mort << " Nombre de clonages " << std::setw(3) << sum_clon << std::endl;
    std::cout<< "***************************************************************" << std::endl;

}
