#include "Oreilles.h"
#include "../Bestiole.h"
#include <iostream>
#include <cmath>

Oreilles::Oreilles(double distance, double capa_detec)
{
    m_distance = distance;
    cap_detec=capa_detec;
}


Oreilles::Oreilles(const Oreilles & oreillesOrigine)
{
    m_distance = oreillesOrigine.getDistance();
    cap_detec = oreillesOrigine.getCapDetec();
}
Oreilles &Oreilles::operator=(const Oreilles &o) {
    m_distance = o.getDistance();
    cap_detec = o.getCapDetec();
    return *this;
}

Oreilles::~Oreilles() {}

bool Oreilles::jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const
{
    double         dist;
    double x=thisBestiole.getX();
    double y=thisBestiole.getY();
    dist = std::sqrt( (double)(x-bestiole.getX())*(x-bestiole.getY()) + (y-bestiole.getY())*(y-bestiole.getY()) );
    bool seen = ( dist <= m_distance );
//    if (seen) std::cout << "seen by ears" << std::endl;
    return seen&&(bestiole.getCapaCamo()<cap_detec);
}

double Oreilles::getDistance() const {return m_distance;}
double Oreilles::getCapDetec() const {return cap_detec;}



