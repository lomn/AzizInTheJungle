#include "Peureux.h"
#include "../BestioleUtil.h"
#include "../Bestiole.h"

const double MAX_VITESSE = 10.0;
const int SCARE_TIME = 10;

Peureux::Peureux(): Comportement("Peureux"){};


std::array<double,2> Peureux::calculVitesse(Bestiole &b, std::vector<Bestiole> &list) {
    std::array<double,2>  vitessePolaire{};
    int nb_voisins=0;
    vitessePolaire[1] = b.getOrientation();

    if (b.getPrevSpeed()==0){
        b.setPrevSpeed(b.getVitessePolaire());
    }

    for (auto it = list.begin(); it != list.end(); ++it) {
        if (b.jeTeVois(*it) && not(b == *it)) {
            nb_voisins++;
        }
    }
    //If the beast is not scared and encounter 3 beasts or more, the beast do a u-turn and become scared (which is represented by scare count <= 10)
    if (nb_voisins>=3 && b.getScareCount() > SCARE_TIME){
        vitessePolaire[1] = fmod(b.getOrientation() + M_PI,2*M_PI);
        b.setScareCount(0);
    }
    //If the beast is scared it goes fast
    if (b.getScareCount()<=10){
        vitessePolaire[0] = MAX_VITESSE;
    }
        //else it has a normal speed
    else {
        vitessePolaire[0] = b.getPrevSpeed();
    }
    //every turn the scare count is incremented so the beast is calm after 10 rounds
    b.setScareCount(b.getScareCount()+1);

    return vitessePolaire;

}