#include "Fabrique.h"

Fabrique::Fabrique(int width, int height, unsigned float kamikaze, unsigned float prevoyant, unsigned float gregaire, unsigned float peureux)
{
    this->m_height = height;
    this->m_width  = width;
    this->pourcentageComportement = {0., 0., 0., 0.};

    float normalize = 1/(kamikaze + prevoyant + gregaire + peureux);

    //On s'assure que la somme des probas est égale a 1
    pourcentageComportement[KAMIKAZE_IND] = kamikaze*normalize;
    pourcentageComportement[PREVOYANT_IND] = prevoyant*normalize;
    pourcentageComportement[GREGAIRE_IND] = gregaire*normalize;
    pourcentageComportement[PEUREUX_IND] = peureux*normalize;
}