#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

using namespace std;


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
   double            lifeSpan; // duree de vie
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   bool              isSchizo; // Indication de l'état mental de la bestiole...
   double            pDeath; // Proba de mort par collision
   double            pClone; // Proba de clonage
   std::unique_ptr<std::vector<Bestiole>>   listBestiole;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   int               getIdentite(); // id
   int               getCoordonne(); // position
   double            getSize(); // taille
   double            getLifeSpan(); // duree de vie
   double            getOrientation();
   double            getVitesse();
   bool              isSchizo(); // Indication de l'état mental de la bestiole...
   double            getPDeath(); // Proba de mort par collision
   double            getPClone(); // Proba de clonage

   int               setCoordonne(); // position
   double            setSize(); // taille
   double            setLifeSpan(); // duree de vie
   double            setOrientation();
   double            setVitesse();
   bool              setSchizo(); // Indication de l'état mental de la bestiole...
   double            setPDeath(); // Proba de mort par collision
   double            setPClone(); // Proba de clonage

};


#endif
