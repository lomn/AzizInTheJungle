/**
* @file Comportement.h
* @brief Il s'agit de la classe comportement dont héritent tout les comportements
 */
#ifndef AZIZINTHEJUNGLE_COMPORTEMENT_H
#define AZIZINTHEJUNGLE_COMPORTEMENT_H
#include <vector>
#include <array>

class Bestiole;
/**
 * @brief Comportements des bestioles
 */
class Comportement {
private:
    const char * nom; ///< nom du comportement
public:
    /**
     * @brief Constructeur de base d'un Comportement
     */
    Comportement();

    /**
     * @brief Constructeur d'un comportement avec comme paramètre son nom (utilisé par les classes filles)
     * @param nom
     */
    Comportement(const char * nom);

    /**
     * @brief simple destructeur
     */
    virtual ~Comportement(){};

    /**
     * @brief Getter su nom
     * @return nom
     */
    virtual const char* getNom(){return nom;};

    /**
     * @brief Calcule la nouvelle vitesse et orientation de la bestiole selon son comportement
     * @param b  Bestiole pour qui il faut calculer la vitesse
     * @param list liste des Bestioles environnantes pour les comportements qui dépendent de l'environnement
     * @return array avec les coordonnées polaires de la vitesse, soit la norme et l'orientation
     */
    virtual std::array<double, 2> calculVitesse(Bestiole &b, std::vector<Bestiole> & list);
};


#endif //AZIZINTHEJUNGLE_COMPORTEMENT_H
