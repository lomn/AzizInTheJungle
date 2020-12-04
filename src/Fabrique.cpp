#include "Fabrique.h"
#include "Accessoire/Accessoire.h"
#include "Accessoire/Carapace.h"
#include "Accessoire/Camouflage.h"
#include "Accessoire/Nageoire.h"

Fabrique::Fabrique(int width, int height, 
        unsigned float kamikaze, unsigned float prevoyant, unsigned float gregaire, unsigned float peureux, 
        unsigned float carapace, unsigned float camouflage, unsigned float nageoire)
{
    this->m_height = height;
    this->m_width  = width;
    this->probaComportement = {0., 0., 0., 0.};
    this->probaAccessoires  = {0., 0., 0.};

    // Proba pour le comportement.
    unsigned float normalize = 1/(kamikaze + prevoyant + gregaire + peureux);
    //On s'assure que la somme des probas est égale a 1
    probaComportement[KAMIKAZE_IND]  = kamikaze*normalize;
    probaComportement[PREVOYANT_IND] = prevoyant*normalize;
    probaComportement[GREGAIRE_IND]  = gregaire*normalize;
    probaComportement[PEUREUX_IND]   = peureux*normalize;

    // Proba accessoires.
    normalize = 1/(carapace + camouflage + nageoire);
    porbaAccessoires[CARAPACE_IND]   = carapace*normalize;
    porbaAccessoires[CAMOUFLAGE_IND] = camouflage*normalize;
    porbaAccessoires[NAGEOIRE_IND]   = nageoire*normalize;
}

Fabrique::~Fabrique()
{
    return;
}

Fabrique::Bestiole & addMember(){
    int p;
    Bestiole & b = new Bestiole();
    b.initCoords(300,300);

    
    // Ajout d'accessoirres ici :
    p = rand() % 101;
    if(p < probaAccessoires[CARAPACE_IND]){
            b.addAccessoires(new Carapace((double)rand()/(double)RAND_MAX));
    }
    // Assignation de la personnalité ici :

    // Ajout des attributs de perception ici :

    return b;
}