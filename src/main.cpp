#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Fabrique.h"

#include <iostream>

using namespace std;


int main()
{
   int width = 640;
   int height = 480;
   double pGreg = 1/3;
   double pPeur = 1/3;
   double pPrev = 0; // Pas encore implémenté
   double pKami = 1/3;

   double pCara = 1/3;
   double pCamou = 0; // Pas encore implémenté
   double pNage = 1/3

   Aquarium       ecosysteme( width, height, 30 );
   Fabrique * createur = new Fabrique(width, height, 
      pKami, pPrev, pGreg, pPeur, //Personalités
      pCara, pCamou, pNage); // Accessoires

   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember(createur->addMember());
   ecosysteme.run();

   delete Bestiole::comportementArray[0];
   delete Bestiole::comportementArray[1];
   delete Bestiole::comportementArray[2];
   delete Bestiole::comportementArray[3];

   return 0;

}
