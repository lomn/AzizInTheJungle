#include "Gregaire.h"
#include "../BestioleUtil.h"
#include "../Bestiole.h"
#include <iostream>


Gregaire::Gregaire(): Comportement("Gregaire") {}

std::array<double,2> Gregaire::calculVitesse(Bestiole &b, std::vector<Bestiole> &list) {
    /* std::array<double,2>  vitesseCartesien{};
    int nb_voisins;
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (b.jeTeVois(*it) && not(b == *it)) {
            vitesseCartesien[0] += it->getVitesseCartesien()[0];
            vitesseCartesien[1] += it->getVitesseCartesien()[1];
            nb_voisins++;
        }
    }
    vitesseCartesien[0] += vitesseCartesien[0]/nb_voisins; //on calcule la vitesse moyenne cartésienne
    vitesseCartesien[1] += vitesseCartesien[1]/nb_voisins;
    return CartesienToPolaire(vitesseCartesien); // on la convertit en polaire et on récupérera la direction */
    
    std::array<double,2>  vitessePolaire{};
    int nb_voisins = 0;
    vitessePolaire[0] = b.getVitessePolaire();
    vitessePolaire[1] = 0;

    for (auto it = list.begin(); it != list.end(); ++it) {
        if (b.jeTeVois(*it) && not(b == *it)) {
            vitessePolaire[1] += it->getOrientation();
            nb_voisins++;
        }
    }
//    std::cout << " nb vois" << nb_voisins << " vit pol " << vitessePolaire[1] <<std::endl;
    vitessePolaire[1] = vitessePolaire[1]/(double)nb_voisins;
//    std::cout << " nb vois" << nb_voisins << " vit pol " << vitessePolaire[1] <<std::endl;
    if (nb_voisins >0) return vitessePolaire;
    return std::array<double, 2>{b.getVitessePolaire(), b.getOrientation()};

}