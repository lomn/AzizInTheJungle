#include "Oreilles.h"
#include "../Bestiole.h"


Oreilles::Oreilles(double distance, Bestiole *bestiole)
{
    thisBestiole = static_cast<Bestiole*>(bestiole);
    m_distance = distance;
}


Oreilles::Oreilles(const Oreilles & oreillesOrigine)
{
    m_distance = oreillesOrigine.getDistance();
}


Oreilles::~Oreilles()
{
}

double Oreilles::getDistance() const {
    return m_distance;
}

bool Oreilles::jeTeVois(const Bestiole & bestiole)
{
    double thisX = thisBestiole->getX();
    double thisY = thisBestiole->getY();

    //Déroule le code

    return (((bestiole.getX()-thisX)*(bestiole.getX()-thisX)+(bestiole.getY()-thisY)*(bestiole.getY()-thisY)) <= this->getDistance()*this->getDistance());

}

