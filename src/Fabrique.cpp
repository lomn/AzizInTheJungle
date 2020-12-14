#include "Fabrique.h"

Fabrique::Fabrique(int width, int height, 
        float kamikaze, float prevoyant, float gregaire, float peureux, 
        float carapace, float camouflage, float nageoire)
{
    this->m_height = height;
    this->m_width  = width;
    //this->probaComportement = {0., 0., 0., 0.};
    //this->probaAccessoires  = {0., 0., 0.};

    // Proba pour le comportement.
    float normalize = 1/(kamikaze + prevoyant + gregaire + peureux);
    //On s'assure que la somme des probas est égale a 1
    this->probaComportement[KAMIKAZE_IND]  = kamikaze*normalize;
    this->probaComportement[PREVOYANT_IND] = prevoyant*normalize;
    this->probaComportement[GREGAIRE_IND]  = gregaire*normalize;
    this->probaComportement[PEUREUX_IND]   = peureux*normalize;

    // Proba accessoires.
    normalize = 1/(carapace + camouflage + nageoire);
    this->probaAccessoires[CARAPACE_IND]   = carapace*normalize;
    this->probaAccessoires[CAMOUFLAGE_IND] = camouflage*normalize;
    this->probaAccessoires[NAGEOIRE_IND]   = nageoire*normalize;
}

Fabrique::~Fabrique()
{
    return;
}

Bestiole & Fabrique::addMember(){
    int p;
    Bestiole * b = new Bestiole();
    b->initCoords(rand()%m_width,rand()%m_height);

    
    // Ajout d'accessoirres ici :
    /*
    p = rand() % 101;
    if(p < probaAccessoires[CARAPACE_IND]){
            b->addAccessoires(*new Carapace((double)rand()/(double)RAND_MAX));
    }

    p = rand() % 101;
    if(p < probaAccessoires[CAMOUFLAGE_IND]){
            b->addAccessoires(*new Camouflage((double)rand()/(double)RAND_MAX));
    }

    p = rand() % 101;
    if(p < probaAccessoires[NAGEOIRE_IND]){
            b->addAccessoires(*new Nageoire((double)rand()/(double)RAND_MAX));
    }*/

    // Assignation de la personnalité ici :
//        p = rand() % 101;
//        if(p < probaComportement[KAMIKAZE_IND]){
//                b->setComportement(KAMIKAZE_IND);
//        }
//
//        p = rand() % 101;
//        if(p < probaComportement[GREGAIRE_IND]){
//                b->setComportement(GREGAIRE_IND);
//        }
//
//        p = rand() % 101;
//        if(p < probaComportement[PEUREUX_IND]){
//                b->setComportement(PEUREUX_IND);
//        }
//
//        p = rand() % 101;
//        if(p < probaComportement[PREVOYANT_IND]){
//                b->setComportement(PREVOYANT_IND);
//        }
        b->setComportement(PEUREUX_IND);

    // Ajout des attributs de perception ici :

    return *b;
}