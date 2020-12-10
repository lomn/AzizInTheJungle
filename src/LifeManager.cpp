#include "LifeManager.h"
#include "Bestiole.h"
#include "BestioleUtil.h"

void showAll(std::vector<Bestiole> & lst){
    std::cout << "lst : { ";
    for (std::vector<Bestiole>::size_type i =0;i<lst.size();i++){
        std::cout<< lst[i].getIdentite() << ", ";
    }
    std::cout << " }" << std::endl;
}

class isIdentity
        {
                private:
                int id;
                public:
                isIdentity(int n) : id(n) {  }
 
                bool operator () (const Bestiole & b) const {
                    return id == b.getIdentite();
                }
 
        };

void slowDelete (int id, std::vector<Bestiole> & list){ 
    list.erase( std::remove_if(list.begin(), list.end(), isIdentity(id)), list.end() );
}

void quickDelete( int idx , std::vector<Bestiole> & lst)
{
    
    std::cout << "[-] Quick delete b : " << lst[idx].getIdentite() << " ; "<< lst.size() << std::endl;

    std::cout << "[-] debut ";
    showAll(lst);

    if(idx != lst.size()-1){
       // Bestiole tmp = lst[idx];
        lst[idx] = lst.back();
       // lst.back() = tmp;
        std::cout << "[-] moved elt";
        showAll(lst);
    }
    lst.pop_back();
    std::cout << "[-] Quick delete e : " << lst.size() << std::endl;
    
    
    std::cout << "[-] fin ";
    showAll(lst);
    
}

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
