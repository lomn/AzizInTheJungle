#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>
#include <array>
//using namespace std;


class Milieu;

class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite; // id
   int               x, y; // position
   double            size; // taille
   int               lifeSpan; // duree de vie
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   bool              isSchizo{}; // Indication de l'état mental de la bestiole...
   double            pDeath; // Proba de mort par collision
   double            pClone; // Proba de clonage

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole();                               // Constructeur par defaut
   Bestiole(const Bestiole & b);                 // Constructeur de copies
   ~Bestiole();                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action(Milieu & monMilieu);
   void draw(UImg & support);

   bool jeTeVois(const Bestiole & b) const;

   void initCoords(int xLim, int yLim);

   Bestiole & operator=(const Bestiole & b);
   friend bool operator==(const Bestiole & b1, const Bestiole & b2);
   friend bool operator!=(const Bestiole & b1, const Bestiole & b2){return not(b1 == b2);};

   T* getCouleur() const;

    // Méthode de personalité / identité
    int getIdentite() const;
    double getSize() const;
    bool getIsSchizo() const;

    // Méthodes relative aux propriété de vie/mort
    int getLifeSpan() const;
    double getPDeath() const;
    void setPDeath(double pDeath);
    double getPClone() const;
    void setPClone(double pClone);

    // Methodes de localisation / vitesse
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    double getOrientation() const;
    void setOrientation(double orientation);
    double getVitessePolaire() const;
    void setVitessePolaire(double vitesse);
    void setVitesseCartesien(double x, double y);
    std::array<double, 2> getVitesseCartesien();

    // Methodes accessoires
   
    void collide();

    // Methodes perception
    

};


#endif
