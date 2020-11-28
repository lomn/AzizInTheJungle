#include<cmath>
#include "Bestiole.h"
#include "Accessoire/Accessoire.h"


double distance(const Bestiole a, const Bestiole b){
    double x =(float)(a.getX()-b.getX());
    double y =(float)(a.getY()-b.getY());
    return sqrt(x*x+y*y);
}

double getCarapvalue(std::vector<Accessoire> list){
    double res=0;
    for (int i=0; i<list.size(); i++){
        res+=list[i].getCoefCarapace();
    }
    return res;
}

double getCamvalue(std::vector<Accessoire> list){
    double res=0;
    for (int i=0; i<list.size(); i++){
        res+=list[i].getCoefCamouflage();
    }
    return res;
}

double getNagvalue(std::vector<Accessoire> list){
    double res=0;
    for (int i=0; i<list.size(); i++){
        res+=list[i].getCoefNageoire();
    }
    return res;
}

