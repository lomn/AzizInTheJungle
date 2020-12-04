#ifndef _FABRIQUE_H_
#define _FABRIQUE_H_

#include <iostream>
#include <vector>
#include "Bestiole.h"

#define KAMIKAZE_IND 0
#define PREVOYANT_IND 1
#define GREGAIRE_IND 2
#define PEUREUX_IND 3

class Fabrique {
private: 
    float[] pourcentageComportement;
    int m_width;
    int m_height;

public:
    Fabrique(int width, int height, unsigned float kamikaze, unsigned float prevoyant, unsigned float gregaire, unsigned float peureux); // Les paramètres en floatindique les proportions de chaques comportement
    ~Fabrique();
    Bestiole & addMember();

};


#endif