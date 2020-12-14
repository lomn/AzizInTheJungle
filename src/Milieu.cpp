#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include "LifeManager.h"
#include "BestioleUtil.h"

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
int Milieu::stepcount=0;
int LifeManager::nb_mort;
int LifeManager::nb_clon;

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;
   lifeMana.getStat();

}


void Milieu::step( void )
{

    cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
    std::cout << "step nb : " << stepcount++ << std::endl;
    lifeMana.step(this->listeBestioles, width, height);
    for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      std::cout << "[+] Act" << std::endl;
       it->action( *this );
      std::cout << "[+] Act" << std::endl;
       it->draw( *this );
   } // for
}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
