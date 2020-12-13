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
    if(p < probaAccessoires[NAGEOIRE_IND]){
            b->addAccessoires(*new Nageoire((double)rand()/(double)RAND_MAX));
    }*/

    // Assignation de la personnalité ici :
        p = rand() % 101;
        int prev = static_cast<int>(100*probaComportement[PREVOYANT_IND]);
        int peur = static_cast<int>(100*probaComportement[PEUREUX_IND  ]);
        int greg = static_cast<int>(100*probaComportement[GREGAIRE_IND ]);
        int kami = static_cast<int>(100*probaComportement[KAMIKAZE_IND ]);
        std::cout << "[+] branching \r\n";
        if(p < prev){
                std::cout << "[+] Set prevoyant \r\n";
                b->setComportement(PREVOYANT_IND);
        }
        else if((p-=prev) < peur){
                std::cout << "[+] Set peureux \r\n";
                b->setComportement(PEUREUX_IND);
        }
        else if((p-=peur) < greg){
                std::cout << "[+] Set gregaire \r\n";
                b->setComportement(GREGAIRE_IND);
        }
        else{
                std::cout << "[+] Set kamikaze \r\n";
                b->setComportement(KAMIKAZE_IND);
        }
    // Ajout des attributs de perception ici :

    return *b;
}