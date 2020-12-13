//
// Created by sella on 04/12/2020.
//

#include "Kamikaze.h"
#include "../BestioleUtil.h"
#include "../Bestiole.h"
#include <cmath>
#include <iostream>

Kamikaze::Kamikaze(): Comportement("Kamikaze") {}

std::array<double, 2> Kamikaze::calculVitesse(Bestiole &b, std::vector<Bestiole> &list) {
//    std::array<double, 2> vitesse{};
//    double vx, vy;
//    double dx, dy;
//    for ( auto it = list.begin() ; it != list.end() ; ++it ){ // fonce sur la première bestiole
//        if(b.jeTeVois(*it) && not (b==*it)){
//            dx = b.getX() - it->getX();
//            dy = b.getY() - it->getY();
//            vx = dx*b.getVitessePolaire()/sqrt(dx*dx+dy*dy);
//            vy = dy*b.getVitessePolaire()/sqrt(dx*dx+dy*dy);
//            vitesse[0]=vx;
//            vitesse[1]=vy;
//            return CartesienToPolaire(vitesse);
//        }
//    }
//    return std::array<double, 2>{b.getVitessePolaire(), b.getOrientation()};
    //Recherche de la bestiole la plus proche
    std::vector<Bestiole>::size_type idx;
    std::vector<Bestiole>::size_type tmp_best=0;
    double tmp_dist = 10000;
    bool found = false;
    for ( idx=0;idx<list.size();idx++){
        if(b.jeTeVois(list[idx]) &&  (b!=list[idx])){
            found = true;
            double curr_dist = distanceBestiole(list[idx], b);
            if ( tmp_dist>curr_dist) {
                tmp_dist = curr_dist;
//                if (b.getIdentite()==list[0].getIdentite()) std::cout << "[K] dist ? " << tmp_dist << std::endl;

                tmp_best=idx;
            }
        }
    }
    if (!found) return std::array<double, 2>{b.getVitessePolaire(), b.getOrientation()};
    std::array<double, 2> newSpeed{};
    double dx, dy, ang;
    dx = -(double)(b.getX() - list[tmp_best].getX());
    dy = (double)(b.getY() - list[tmp_best].getY());
    ang = atan2(dy, dx);
    newSpeed[0] = b.getVitessePolaire();
    newSpeed[1]=ang;
//    if (ang>=0) newSpeed[1]=ang;
//    if (ang<0) newSpeed[1]= ang+2*M_PI;
//    if (b.getIdentite()==list[0].getIdentite()) {
//        std::cout << "---------------------" << std::endl;
//        std::cout << "[K] ang :: " << ang << std::endl;
//        std::cout << "[K] dx, dy :: " << dx << ", " << dy << std::endl;
//        std::cout << "[K] found ? " << found << std::endl;
//        std::cout << "[K] oldSpeed :: " << newSpeed[0] << ", " << b.getOrientation() << std::endl;
//        std::cout << "[K] newSpeed :: " << newSpeed[0] << ", " << newSpeed[1] << std::endl;
//    }
    return newSpeed;


}


