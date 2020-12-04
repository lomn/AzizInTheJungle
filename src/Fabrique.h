#ifndef _FABRIQUE_H_
#define _FABRIQUE_H_

#include <iostream>
#include <vector>
#include "Bestiole.h"

#define KAMIKAZE_IND 0
#define PREVOYANT_IND 1
#define GREGAIRE_IND 2
#define PEUREUX_IND 3

#define CARAPACE_IND 0
#define CAMOUFLAGE_IND 1
#define NAGEOIRE_IND 2

class Fabrique {
private: 
    float probaComportement[4];
    float probaAccessoires[3];
    int m_width;
    int m_height;

public:
    // Les paramètres en floatindique les proportions de chaques comportement/accessoires etc dans la population.
    Fabrique(int width, int height, 
        float kamikaze, float prevoyant, float gregaire, float peureux, 
        float carapace, float camouflage, float nageoire); 
    ~Fabrique();
    Bestiole & addMember();

};


#endif