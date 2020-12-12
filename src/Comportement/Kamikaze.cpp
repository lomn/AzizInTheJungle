//
// Created by sella on 04/12/2020.
//

#include "Kamikaze.h"
#include "../BestioleUtil.h"
#include "../Bestiole.h"


Kamikaze::Kamikaze(): Comportement("Kamikaze") {}

std::array<double, 2> Kamikaze::calculVitesse(const Bestiole &b, std::vector<Bestiole> &list) {
    std::array<double, 2> vitesse{};
    double vx, vy;
    double dx, dy;
    for ( auto it = list.begin() ; it != list.end() ; ++it ){ // fonce sur la première bestiole
        if(b.jeTeVois(*it) && not (b==*it)){
            dx = b.getX() - it->getX();
            dy = b.getY() - it->getY();
            vx = dx*b.getVitessePolaire()/sqrt(dx*dx+dy*dy);
            vy = dy*b.getVitessePolaire()/sqrt(dx*dx+dy*dy);
            vitesse[0]=vx;
            vitesse[1]=vy;
            return CartesienToPolaire(vitesse);
        }
    }
    return std::array<double, 2>{b.getVitessePolaire(), b.getOrientation()};
    /* Recherche de la bestiole la plus proche
    std::vector<Bestiole>::iterator tmp_best;
    double tmp_dist = 10000;
    for ( auto it = list.begin() ; it != list.end() ; ++it ){
        if(b.jeTeVois(*it) && not (b==*it)){
            double curr_dist = distanceBestiole(*it, b);
            if ( tmp_dist>curr_dist) {
                tmp_dist = curr_dist;
                tmp_best=it;
            }
        }
    }
    dx = b.getX() - tmp_best->getX();
    dy = b.getY() - tmp_best->getY();
    vx = dx*b.getVitessePolaire()/sqrt(dx*dx+dy*dy);
    vy = dy*b.getVitessePolaire()/sqrt(dx*dx+dy*dy);
    vitesse[0]=vx;
    vitesse[1]=vy;
    return CartesienToPolaire(vitesse);
     */

}


