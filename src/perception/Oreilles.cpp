#include "Oreilles.h"
#include "../Bestiole.h"


Oreilles::Oreilles(double distance, const Bestiole & bestiole)
{
    thisBestiole = bestiole;
    m_distance = distance;
    return;
}


Oreilles::Oreilles(Oreilles oreillesOrigine)
{
    m_distance = oreillesOrigine.getDistance();
    return;
}


Oreilles::~Oreilles()
{
    return;
}

double Oreilles::getDistance()
{
    return m_distance;
}

bool Oreilles::jeTeVois(const Bestiole & bestiole)
{
    double thisX = thisBestiole.getX();
    double thisY = thisBestiole.getY();

    //Déroule le code

    return (((bestiole.getX()-thisX)*(bestiole.getX()-thisX)+(bestiole.getY()-thisY)*(bestiole.getY()-thisY)) <= this->getDistance()*this->getDistance());

}