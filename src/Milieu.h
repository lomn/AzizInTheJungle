/**
* @file Milieu.h
* @brief Il s'agit d'une classe gérant le Milieu d'évolution des bestioles
 */

#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"
#include "Bestiole.h"
#include "LifeManager.h"

#include <iostream>
#include <vector>

using namespace std;

class LifeManager;

class Milieu : public UImg
{

private :
   static const T          white[];
   static int stepcount;
   int                     width, height;
   std::vector<Bestiole>   listeBestioles;
   LifeManager            lifeMana;
public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins( const Bestiole & b );
    std::vector<Bestiole> & getListeBestiole(){return listeBestioles;};

};


#endif
