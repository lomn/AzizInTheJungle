//
// Created by sella on 04/12/2020.
//

#include "Gregaire.h"

Gregaire::Gregaire(): Comportement("Gregaire") {}

double *Gregaire::calculVitesse(const Bestiole &b, std::vector<Bestiole> &list) {
    double vitesse[2];
    for (auto it = list.begin(); it != list.end(); ++it) { // fonce sur la première bestiole
        if (b.jeTeVois(*it) && not(b == *it)) {
            ;
        }
    }
}