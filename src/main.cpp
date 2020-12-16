/**
 * @file main.cpp
 * @brief Il s'agit d'une extension de fonctionnalités d'une simulation d'écosystème
 * @author authors
 * Contact: contact@contact.org
 */
#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Fabrique.h"

#include <iostream>

using namespace std;

//int Fabrique::nb_naiss[4]={0,0,0,0};

int main()
{
   int width = 640;
   int height = 480;
   int nbBestiolesGene = 20;

   double pGreg = 1./3.;
   double pPeur = 1./3.;
   double pPrev = 0; // Pas encore implémenté
   double pKami = 1./3.;

   double pCara = 1./3.;
   double pCamou = 0; // Pas encore implémenté
   double pNage = 1./3.;

   double pOreilles = 1./1.3;
   double pYeux = 1./1.3;

   Aquarium       ecosysteme( width, height, 30 );
   Fabrique * createur = new Fabrique(width, height, nbBestiolesGene,
      pKami, pPrev, pGreg, pPeur, //Personalités
      pCara, pCamou, pNage,
      pYeux, pOreilles); // Accessoires

   for ( int i = 1; i <= nbBestiolesGene; ++i )
      ecosysteme.getMilieu().addMember(createur->addMember());
   ecosysteme.run();

   delete Bestiole::comportementArray[0];
   delete Bestiole::comportementArray[1];
   delete Bestiole::comportementArray[2];
   delete Bestiole::comportementArray[3];
   delete createur;
   return 0;

}
