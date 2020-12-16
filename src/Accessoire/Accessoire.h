/**
* @file Comportement.h
* @brief Il s'agit de la classe accessoire dont héritent tous les accessoires
 */
#ifndef _ACCESSOIRE_H_
#define _ACCESSOIRE_H_

#include <iostream>
#include <vector>

/**
 * @brief Accessoire, classe mère
 */
class Accessoire
{
private:
    //char* Type;

public:
    Accessoire(){};
    Accessoire(Accessoire const& accessoire){};
    virtual ~Accessoire(){};
    virtual const char* getType() const{return "None";};
    virtual double getCoefCarapace() const{return 0;};        ///< getter du coefficient de carapace
    virtual double getCoefCamouflage() const{return 0;};      ///< getter du coefficient de camouflage
    virtual double getCoefNageoire() const{return 0;};        ///< getter du coefficient de nageoire
};


#endif
