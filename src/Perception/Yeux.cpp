#include "Yeux.h"
#include "../Bestiole.h"


Yeux::Yeux(double angle, double distance)
{
    m_angle = angle;
    m_distance = distance;
}


Yeux::Yeux(const Yeux & yeuxOrigine)
{
    m_angle = yeuxOrigine.getAngle();
    m_distance = yeuxOrigine.getDistance();
}


Yeux::~Yeux() {}


double Yeux::getAngle() const
{
    return m_angle;
}

double Yeux::getDistance() const
{
    return m_distance;
}

bool Yeux::jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole)
{   
    //Récupère la position, vitesse et direction de la bestiole avec les yeux
    double thisX = thisBestiole.getX();
    double thisY = thisBestiole.getY();

    double vitesse = thisBestiole.getVitessePolaire();

    double direction = bestiole.getOrientation();

    //Calcule le vecteur défini entre la bestiole qui voit et la bestiole à voir
    double vecteurEntreBestioles[2] {0};

    vecteurEntreBestioles[0] = thisX - bestiole.getX();
    vecteurEntreBestioles[1] = thisY - bestiole.getY();

    //Exprimer la vitesse de la bestiole sous forme de vecteur

    double vecteurVitesseBestiole[2] {0};

    vecteurVitesseBestiole[0] = cos( direction )*vitesse;
    vecteurVitesseBestiole[1] = sin( direction )*vitesse;

    // Calcule l'angle entre le vecteur vitesse de la bestiole avec les yeux, et le vecteur formé par les 2 bestioles avec la formule du produit scalaire

    double angleEntreBestioles = acos( (vecteurVitesseBestiole[0]*vecteurEntreBestioles[0]+vecteurVitesseBestiole[1]*vecteurEntreBestioles[1]) / (vitesse * bestiole.getVitessePolaire()));
    
    //vérifie d'abord si la bestiole est bien à portée des yeux, puis si elle est bien dans le champ de vision et retourne le booléen correspondant

    if (((bestiole.getX()-thisX)*(bestiole.getX()-thisX)+(bestiole.getY()-thisY)*(bestiole.getY()-thisY)) <= this->getDistance()*this->getDistance()) {

        return (abs(angleEntreBestioles) <= (this->getAngle()/2));


    };
    return false;
}


