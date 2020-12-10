//
// Created by sella on 04/12/2020.
//

#include "Gregaire.h"
#include "../BestioleUtil.h"


Gregaire::Gregaire(): Comportement("Gregaire") {}

std::array<double,2> Gregaire::calculVitesse(const Bestiole &b, std::vector<Bestiole> &list) {
    std::array<double,2>  vitesseCartesien{};
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
    return CartesienToPolaire(vitesseCartesien); // on la convertit en polaire et on récupérera la direction
}