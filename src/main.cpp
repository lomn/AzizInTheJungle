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
   Aquarium       ecosysteme( width, height, 30 );
   Fabrique * createur = new Fabrique(width, height, 
      1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0, //Personalités
      1.0/3.0, 1.0/3.0, 1.0/3.0); // Accessoires

   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember(createur->addMember());
   ecosysteme.run();

   delete Bestiole::comportementArray[0];
   delete Bestiole::comportementArray[1];
   delete Bestiole::comportementArray[2];
   delete Bestiole::comportementArray[3];

   return 0;

}
