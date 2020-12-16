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

const int nbBestiolesGene = 20;

Aquarium parser(int argc, char * argv[], Fabrique* & createur){
   int width = 640;
   int height = 480;

   double pGreg = 1./3.;
   double pPeur = 1./3.;
   double pPrev = 0; // Pas encore implémenté
   double pKami = 1./3.;

   double pCara = 1./3.;
   double pCamou = 0; // Pas encore implémenté
   double pNage = 1./3.;

   double pOreilles = 1./1.;
   double pYeux = 1./1.;

   for(int i = 0; i < argc; i++){

      if(strcmp(argv[i], "-w") == 0 && i+1<argc){
         width = stoi(argv[i+1]);
         std::cout << "width : " << width << std::endl;
      }
      else if(strcmp(argv[i], "-h") == 0 && i+1<argc){
         height = stoi(argv[i+1]);
         std::cout << "height : " << height << std::endl;
      }
      else if(strcmp(argv[i], "-pG") == 0 && i+1<argc){
         pGreg = stod(argv[i+1]);
         std::cout << "proba gregaire : " << pGreg << std::endl;
      }
      else if(strcmp(argv[i], "-pK") == 0 && i+1<argc){
         pKami = stod(argv[i+1]);
         std::cout << "proba kamikaze : " << pKami << std::endl;
      }
      else if(strcmp(argv[i], "-pP") == 0 && i+1<argc){
         pPeur = stod(argv[i+1]);
         std::cout << "proba peureux : " << pPeur << std::endl;
      }
      else if(strcmp(argv[i], "-pCar") == 0 && i+1<argc){
         pCara = stod(argv[i+1]);
         std::cout << "proba peureux : " << pCara << std::endl;
      }
      else if(strcmp(argv[i], "-pCam") == 0 && i+1<argc){
         pCamou = stod(argv[i+1]);
         std::cout << "proba peureux : " << pCamou << std::endl;
      }
      else if(strcmp(argv[i], "-pNage") == 0 && i+1<argc){
         pNage = stod(argv[i+1]);
         std::cout << "proba peureux : " << pNage << std::endl;
      }
      else if(strcmp(argv[i], "-pO") == 0 && i+1<argc){
         pOreilles = stod(argv[i+1]);
         std::cout << "proba peureux : " << pOreilles << std::endl;
      }
      else if(strcmp(argv[i], "-pY") == 0 && i+1<argc){
         pYeux = stod(argv[i+1]);
         std::cout << "proba peureux : " << pYeux << std::endl;
      }
   }

   printf("crateur : %x\r\n", createur);
   createur = new Fabrique(width, height, nbBestiolesGene,
      pKami, pPrev, pGreg, pPeur, //Personalités
      pCara, pCamou, pNage,
      pYeux, pOreilles); // Accessoires
   printf("crateur : %x\r\n", createur);

   return Aquarium( width, height, 30 );
}


int main(int argc, char * argv[])
{
   Fabrique * createur = nullptr;

   Aquarium ecosysteme = parser(argc, argv, createur);

   printf("$ Fabrique : %p\r\n$ aquarium %p\r\n", createur, &ecosysteme);

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
