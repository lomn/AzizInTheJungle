//
// Created by sella on 04/12/2020.
//

#include "Peureux.h"
#include "../BestioleUtil.h"
#include "../Bestiole.h"

const double MAX_VITESSE = 10.0;

Peureux::Peureux(){
    Comportement("Peureux");
    this->scare_count = 11;
    this->vitesse_calme = 0; //A counter which is reset everytime the beast is scared. While this counter is less than 10, the beast is running faster and doesnt change direction.
}
;
//Getters and setters
int Peureux::getScare_count(){
    return this->scare_count;
};

void Peureux::setScare_count(int scare){
    this->scare_count = scare;
};

double Peureux::getVitesseCalme(){
    return this->vitesse_calme;
};

void Peureux::setVitesseCalme(double speedCalm){
    this->vitesse_calme = speedCalm;
}


std::array<double,2> Peureux::calculVitesse(const Bestiole &b, std::vector<Bestiole> &list) {
    std::array<double,2>  vitessePolaire{};
    int nb_voisins=0;
    vitessePolaire[1] = b.getOrientation();

    if (this->getVitesseCalme()==0){
        this->setVitesseCalme(b.getVitessePolaire());
    }

    for (auto it = list.begin(); it != list.end(); ++it) {
        if (b.jeTeVois(*it) && not(b == *it)) {
            nb_voisins++;
        }
    }
    //If the beast is not scared and encounter 3 beasts or more, the beast do a u-turn and become scared (which is represented by scare count <= 10)
    if (nb_voisins>=3 && this->getScare_count() > 10){
        vitessePolaire[1] = fmod(b.getOrientation() + M_PI,2*M_PI);
        this->setScare_count(0);
    }
    //If the beast is scared it goes fast
    if (this->getScare_count()<=10){
        vitessePolaire[0] = MAX_VITESSE;
    }
    //else it has a normal speed
    else {
        vitessePolaire[0] = this->getVitesseCalme();
    }
    //every turn the scare count is incremented so the beast is calm after 10 rounds
    this->setScare_count(this->getScare_count()+1);

    return vitessePolaire;

}