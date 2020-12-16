#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>
#include <array>
#include "Comportement/Comportement.h"
#include "Perception/Perception.h"

#define KAMIKAZE_IND 0
#define PREVOYANT_IND 1
#define GREGAIRE_IND 2
#define PEUREUX_IND 3

class Comportement;
class Accessoire;
class Milieu;

class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

public:
   static std::array<Comportement*, 4> comportementArray;
   static std::array<Comportement*, 4> initComportements();
private :
    int               identite;           ///< id
    int               x, y;               ///< position
    double            size;               ///< taille
    int               lifeSpan;           ///< duree de vie
    double            cumulX, cumulY;     ///<
    double            orientation;        ///< orientation de la bestiole
    double            vitesse;            ///< norme de la vitesse de la bestiole
    bool              isSchizo{};         ///< Indication de l'état mental de la bestiole...
    double            pDeath;             ///< Proba de mort par collision
    double            pClone;             ///< Proba de clonage
    int               comportement;       ///< indice du comportement
    std::vector<Accessoire*> accessoireArray;
    int               scareCount;         ///< pour les bestioles peureuses: nombre de tour de fuite
    double            prevSpeed;          ///< pour les bestioles peureuses: mémoire de l'ancienne vitesse avant fuite
    Perception        percep;             ///< instance de Perception pour la gestion des capteurs
    T               * couleur;            ///< couleur de la bestiole

private :
   void bouge( int xLim, int yLim, std::vector<Bestiole> & list );

public :
    Bestiole();                               ///< Constructeur par defaut
    Bestiole(const Bestiole & b);             ///< Constructeur de copies
    ~Bestiole();                              ///< Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action(Milieu & monMilieu);
   void draw(UImg & support);

    /**
     * @brief  détermine si la bestiole en voit une autre
     * @param b bestiole à voir
     * @return bool
     */
   bool jeTeVois(const Bestiole & b) const;

    /**
     * @brief initialise les coordonnées de la bestiole de manière aléatoire
     * @param xLim abscisse max
     * @param yLim ordonnée max
     */
   void initCoords(int xLim, int yLim);

   Bestiole & operator=(const Bestiole & b);
   friend bool operator==(const Bestiole & b1, const Bestiole & b2);
   friend bool operator!=(const Bestiole & b1, const Bestiole & b2){return not(b1 == b2);};

   T* getCouleur() const;

    // Méthode de personalité / identité
    // Méthode de personalité / identité
    /** @name Identite
     * @brief  Getters et Setters pour le comportement et l'identité
     */
    ///@{
    int getIdentite() const;                     ///< getter de l'identité
    double getSize() const;                      ///< getter de la taille
    bool getIsSchizo() const;                    ///< getter du booléen indiquant la schizophrénie
    void setComportement(int comportement);      ///< setter de l'indice du comportement
    int getComportement() const;                 ///< getter de l'indice du comportement
    int getScareCount() const;                   ///< getter du nombre de tours de fuite
    void setScareCount(int scareCount);          ///< setter du nombre de tours de fuite
    double getPrevSpeed() const;                 ///< getter de vitesse avant fuite (polaire)
    void setPrevSpeed(double prevSpeed);         ///< setter de vitesse avant fuite (polaire)
    ///@}

    // Méthodes relative aux propriété de vie/mort
    /** @name Vie
     * @brief  Getters et Setters pour les propriétés de vie/mort
     */
    ///@{
    int getLifeSpan() const;               ///< getter de la durée de vie
    double getPDeath() const;              ///< getter de la probbilité de mort
    double getPDeathPondere() const;
    void setPDeath(double pDeath);         ///< setter de la probabilité de mort                        
    double getPClone() const;              ///< getter de la probabilité de clonage                     
    void setPClone(double pClone);         ///< setter de la probabilité de clonage                     
    void collide();                        ///< change l'orientation de la bestiole après une collision 
    ///@}

    // Methodes de localisation / vitesse
    // Methodes de localisation / vitesse
    /** @name Localisation
     * @brief  Getters et Setters pour la localisation  et la vitesse de la bestiole
     */
    ///@{
    int getX() const;                                                ///< getter de l'abscisse
    void setX(int x);                                                ///< setter de X
    int getY() const;                                                ///< getter de l'ordonnée
    void setY(int y);                                                ///< setter de Y
    double getOrientation() const;                                   ///< getter de l'orientation de la bestiole
    void setOrientation(double orientation);                         ///< setter de l'orientation
    double getVitessePolaire() const;                                ///< getter de la vitesse polaire de la Bestiole
    double getVitessePolairePondere() const;
    void setVitessePolaire(double vitesse);                          ///< setter de la vitesse en polaire   
    void setVitesseCartesien(double x, double y);                    ///< setter de la vitesse en cartésien 
    std::array<double, 2> getVitesseCartesien() const;               ///< getter de la vitesse en cartésien 
    std::array<double, 2> getVitesseCartesienPondere() const;
    ///@}

    // Methodes accessoires
    // Methodes accessoires
    /** @name Accessoires
     * @brief  Méthodes de gestion d'accessoires
     */
    ///@{
    void addAccessoire(Accessoire * acc);
    std::vector<Accessoire*> getAccessoire() const;
    ///@}

    // Methodes perception
    // Methodes perception
    /** @name Perception
     * @brief  Méthodes de gestion de perception
     */
    ///@{
    void addYeux(const Yeux &y);              ///< ajout du capteur Yeux
    void addOreilles(const Oreilles &o);      ///< ajout du capteur Oreilles
    const Perception &getPercep() const;      ///< getter de perception
    double getCapaCamo() const;               ///< getter de la capacité de camouflage
    ///@}

};


#endif
