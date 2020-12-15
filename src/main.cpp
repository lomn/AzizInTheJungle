#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Fabrique.h"

#include <iostream>

using namespace std;

int Fabrique::nb_naiss[4]={0,0,0,0};

int main()
{
   int width = 100;
   int height = 100;
   Aquarium       ecosysteme( width, height, 30 );
   Fabrique * createur = new Fabrique(width, height, 
      1.0/3.0, 0.0/3.0, 1.0/3.0, 1.0/3.0, //Personalités
      1.0/3.0, 1.0/3.0, 1.0/3.0, // Accessoires
      1.0/2.0, 1.0/2.0); // Capteurs

   for ( int i = 1; i <= 2; ++i )
      ecosysteme.getMilieu().addMember(createur->addMember());
   ecosysteme.run();

   delete Bestiole::comportementArray[0];
   delete Bestiole::comportementArray[1];
   delete Bestiole::comportementArray[2];
   delete Bestiole::comportementArray[3];
   delete createur;
   return 0;

}
