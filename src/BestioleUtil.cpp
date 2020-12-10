#include<cmath>
#include "Bestiole.h"
#include "Accessoire/Accessoire.h"
#include <array>

std::array<double, 2> CartesienToPolaire(std::array<double, 2> v){
    std::array<double, 2>  result{};
    double norm;
    double ang;
    norm = sqrt(v[0]*v[0]+v[1]*v[1]);
    double x_norm, y_norm;
    x_norm = v[0]/norm;
    y_norm = v[1]/norm;
    result[0] = norm;
    ang = atan2(y_norm, x_norm);
    if (ang>=0) result[1]=ang;
    if (ang<0) result[1]= ang+2*M_PI;
    return result;
}



double distanceBestiole(const Bestiole & a, const Bestiole & b){
    double x =(float)(a.getX()-b.getX());
    double y =(float)(a.getY()-b.getY());
    return sqrt(x*x+y*y);
}

double getCarapvalue(std::vector<Accessoire> list){
    double res=0;
    for (std::vector<Accessoire>::size_type i=0; i<list.size(); i++){
        res+=list[i].getCoefCarapace();
    }
    return res;
}

double getCamvalue(std::vector<Accessoire> list){
    double res=0;
    for (std::vector<Accessoire>::size_type i=0; i<list.size(); i++){
        res+=list[i].getCoefCamouflage();
    }
    return res;
}

double getNagvalue(std::vector<Accessoire> list){
    double res=0;
    for (std::vector<Accessoire>::size_type i=0; i<list.size(); i++){
        res+=list[i].getCoefNageoire();
    }
    return res;
}

void ShowAllIds(const std::vector<Bestiole> & list){
    for (std::vector<Bestiole>::size_type i=0; i<list.size();i++){
        std::cout << list[i].getIdentite() << ", ";
    }
    std::cout << std::endl;
}
