#include<cmath>
#include "Bestiole.h"
#include "Accessoire/Accessoire.h"

# define M_PI           3.14159265358979323846  /* pi */

double * CartesienToPolaire(double v[2]){
    double result[2];
    double norm;
    double ang;
    norm = sqrt(v[0]*v[0]+v[1]*v[1]);
    double x_norm, y_norm;
    x_norm = v[0]/norm;
    y_norm = v[1]/norm;
    if (v[1]>0){
        result[0] = norm;
        result[1] = acos(y_norm);
        return result;
    }
    else{
        result[0] = norm;
        result[1] = acos(-y_norm)+M_PI;
        return result;
    }
}



double distanceBestiole(const Bestiole & a, const Bestiole & b){
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

