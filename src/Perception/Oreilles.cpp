#include "Oreilles.h"
#include "../Bestiole.h"
#include <iostream>
#include <cmath>

Oreilles::Oreilles(double distance)
{
    m_distance = distance;
}


Oreilles::Oreilles(const Oreilles & oreillesOrigine)
{
    m_distance = oreillesOrigine.getDistance();
}
Oreilles &Oreilles::operator=(const Oreilles &o) {
    m_distance = o.getDistance();
    return *this;
}

Oreilles::~Oreilles() {}

double Oreilles::getDistance() const {
    return m_distance;
}

bool Oreilles::jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const
{
//    if (thisBestiole==bestiole) return false;
    double         dist;
    double x=thisBestiole.getX();
    double y=thisBestiole.getY();
    dist = std::sqrt( (double)(x-bestiole.getX())*(x-bestiole.getY()) + (y-bestiole.getY())*(y-bestiole.getY()) );
    bool seen = ( dist <= m_distance );
    if (seen) std::cout << "seen by ears" << std::endl;
    return seen;
}



