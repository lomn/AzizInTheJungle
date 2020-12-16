/** Fabrique a Bestioles
* Design Pattern : Fabrique
* @file Fabrique.h
* @brief Il s'agit d'une fabrique à bestioles
*
* Cette Classe permet la fabrique permet la créations de bestioles en prenant en compte :
* - les Comportements
* - les Accessoires
* - les Capteurs
 */
#ifndef _FABRIQUE_H_
#define _FABRIQUE_H_

#include <iostream>
#include <vector>
#include "Bestiole.h"

#define CARAPACE_IND 0
#define CAMOUFLAGE_IND 1
#define NAGEOIRE_IND 2

#define YEUX_IND 0
#define OREILLES_IND 1

class Comportement;

class Fabrique {
private:
    int nb_naiss[4];
    int nb_naiss_totale[4];
private: 
    float probaComportement[4];
    float probaAccessoires[3];
    float probaCapteurs[2];
    int m_width;
    int m_height;

public:
    // Les paramètres en floatindique les proportions de chaques comportement/accessoires etc dans la population.
    Fabrique(int width, int height, int nbBestiolesGene,
        float kamikaze, float prevoyant, float gregaire, float peureux, 
        float carapace, float camouflage, float nageoire,
        float yeux, float oreilles);
    ~Fabrique();
    Bestiole & addMember();
    void getStats();

};


#endif