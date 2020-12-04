#include "Comportement.h"

double * Comportement::calculVitesse(const Bestiole &b, std::vector<Bestiole> & list) {
    double vitesse[2];
    return static_cast<double *>(vitesse);
}

Comportement::Comportement() {
    this->nom="Comportement";
}

Comportement::Comportement(const char *nom) {
    this->nom = nom;
}
