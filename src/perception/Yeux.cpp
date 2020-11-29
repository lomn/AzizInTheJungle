#include "Yeux.h"
#include "../Bestiole.h"


Yeux::Yeux(double angle, double distance, const Bestiole & bestiole)
{
    thisBestiole = bestiole;
    m_angle = angle;
    m_distance = distance;
    return;
}


Yeux::Yeux(Yeux yeuxOrigine)
{
    m_angle = yeuxOrigine.getAngle();
    m_distance = yeuxOrigine.getDistance();
    return;
}


Yeux::~Yeux()
{
    return;
}


double Yeux::getAngle()
{
    return m_angle;
}

double Yeux::getDistance()
{
    return m_distance;
}

double Yeux::jeTeVois(const Bestiole & bestiole)
{
    double thisX = thisBestiole.getX();
    double thisY = thisBestiole.getY();

    double direction = bestiole.getOrientation;

    //Déroule le code
}