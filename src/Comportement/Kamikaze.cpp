#include "Kamikaze.h"
#include "../BestioleUtil.h"
#include "../Bestiole.h"
#include <cmath>
#include <iostream>

Kamikaze::Kamikaze(): Comportement("Kamikaze") {}

std::array<double, 2> Kamikaze::calculVitesse(Bestiole &b, std::vector<Bestiole> &list) {
    //Recherche de la bestiole la plus proche
    std::vector<Bestiole>::size_type idx;
    std::vector<Bestiole>::size_type tmp_best=0;
    double tmp_dist = 10000;
    bool found = false;
    for ( idx=0;idx<list.size();idx++){
//        std::cout << "[Kami] appel jeTevois" << std::endl;
        if(b.jeTeVois(list[idx]) &&  (b!=list[idx])){
            found = true;
            double curr_dist = distanceBestiole(list[idx], b);
            if ( tmp_dist>curr_dist) {
                tmp_dist = curr_dist;

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

    return newSpeed;


}
