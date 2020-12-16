#include "Fabrique.h"
#include "Accessoire/Accessoire.h"
#include "Accessoire/Carapace.h"
#include "Accessoire/Nageoire.h"
#include <iomanip>

Fabrique::Fabrique(int width, int height, int nbBestiolesGene,
        float kamikaze, float prevoyant, float gregaire, float peureux, 
        float carapace, float camouflage, float nageoire)
{
    this->m_height = height;
    this->m_width  = width;
    //this->probaComportement = {0., 0., 0., 0.};
    //this->probaAccessoires  = {0., 0., 0.};

    // Proba pour le comportement.
    float normalize = 1./(kamikaze + prevoyant + gregaire + peureux);
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

    this->nb_naiss[KAMIKAZE_IND]  = 0;
    this->nb_naiss[PREVOYANT_IND] = 0;
    this->nb_naiss[GREGAIRE_IND]  = 0;
    this->nb_naiss[PEUREUX_IND]   = 0;

    std::cout << "(-) kami proba : " << this->probaComportement[KAMIKAZE_IND] << std::endl;
    std::cout << "(-) kami : " << static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[KAMIKAZE_IND]) << std::endl;

    std::cout << "(-) prev proba : " << this->probaComportement[PREVOYANT_IND] << std::endl;
    std::cout << "(-) prev : " << static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[PREVOYANT_IND]) << std::endl;

    std::cout << "(-) greg proba : " << this->probaComportement[GREGAIRE_IND] << std::endl;
    std::cout << "(-) greg : " << static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[GREGAIRE_IND]) << std::endl;

    this->nb_naiss_totale[KAMIKAZE_IND]  = static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[KAMIKAZE_IND]);
    this->nb_naiss_totale[PREVOYANT_IND] = static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[PREVOYANT_IND]);
    this->nb_naiss_totale[GREGAIRE_IND]  = static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[GREGAIRE_IND]);
    this->nb_naiss_totale[PEUREUX_IND]   = static_cast<int>(static_cast<double>(nbBestiolesGene)*this->probaComportement[PEUREUX_IND]);
}

Fabrique::~Fabrique(){this->getStats();}

Bestiole & Fabrique::addMember(){
    std::cout << "[+] add member" <<std::endl;
    int p;
    Bestiole * b = new Bestiole();
    b->initCoords(rand()%m_width,rand()%m_height);
    
    // Ajout d'accessoirres ici :
        
        int cara = static_cast<int>(100*probaAccessoires[CARAPACE_IND]);
        int nage = static_cast<int>(100*probaAccessoires[NAGEOIRE_IND]);
        std::cout << "[+] Accessoires \r\n";

  
        double coefCaraMax = 1;
        double coefNageMax = 1;
        p = rand() % 101;
        if(p < cara){
                double coef = coefCaraMax*static_cast<double>(rand())/((double)RAND_MAX);
                std::cout << "ajout carapace coef : " << coef << std::endl;
                b->addAccessoire(new Carapace(coef));
        }
        p = rand() % 101;
        if(p < nage){
                double coef = 1+coefNageMax*static_cast<double>(rand())/((double)RAND_MAX);
                std::cout << "ajout nageoire coef : " << coef << std::endl;
                b->addAccessoire(new Nageoire(coef));
        }

    // Assignation de la personnalité ici :
    std::cout << "[+] Personalité \r\n";
    if(nb_naiss[PREVOYANT_IND] < nb_naiss_totale[PREVOYANT_IND]){
        std::cout << "[+] Set prevoyant \r\n";
        b->setComportement(PREVOYANT_IND);
        nb_naiss[PREVOYANT_IND]= nb_naiss[PREVOYANT_IND]+1;
    }
    else if(nb_naiss[PEUREUX_IND] < nb_naiss_totale[PEUREUX_IND]){
        std::cout << "[+] Set peureux \r\n";
        b->setComportement(PEUREUX_IND);
        nb_naiss[PEUREUX_IND]= nb_naiss[PEUREUX_IND]+1;
    }
    else if(nb_naiss[GREGAIRE_IND] < nb_naiss_totale[GREGAIRE_IND]){
        std::cout << "[+] Set gregaire \r\n";
        b->setComportement(GREGAIRE_IND);
        nb_naiss[GREGAIRE_IND]= nb_naiss[GREGAIRE_IND]+1;
    }
    else{
        std::cout << "[+] Set kamikaze\r\n";
        b->setComportement(KAMIKAZE_IND);
        nb_naiss[KAMIKAZE_IND]= nb_naiss[KAMIKAZE_IND]+1;
    }

    return *b;
}

void Fabrique::getStats() {
    std::cout<< "********************Statistiques naissances********************" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << std::setfill('0');;
    int sum_naiss=0;
    for(size_t k = 0; k <4; k++){
        if (k==KAMIKAZE_IND)  std::cout<< "Kamikaze  ::Nombre de naissances " << std::setw(3) << nb_naiss[k] << std::endl;
        if (k==GREGAIRE_IND)  std::cout<< "Gregaire  ::Nombre de naissances " << std::setw(3) << nb_naiss[k] << std::endl;
        if (k==PEUREUX_IND)   std::cout<< "Peureux   ::Nombre de naissances " << std::setw(3) << nb_naiss[k] << std::endl;
        if (k==PREVOYANT_IND) std::cout<< "Prevoyant ::Nombre de naissances " << std::setw(3) << nb_naiss[k] << std::endl;
        sum_naiss+=nb_naiss[k];
    }
    std::cout<< "Stats     ::Nombre de naissances " << std::setw(3) << sum_naiss << std::endl;
    std::cout<< "***************************************************************" << std::endl;
}
