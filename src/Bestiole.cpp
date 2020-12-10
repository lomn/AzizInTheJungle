#include "Bestiole.h"

#include "Milieu.h"
#include "Accessoire/Accessoire.h"
#include "Perception/Perception.h"
#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


T* Bestiole::getCouleur() const{
    return this->couleur;
}

Bestiole::Bestiole( void )
{

   identite = ++next;

   std::cout << "const Bestiole (" << identite << ") par defaut" << std::endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

    size=10 ; // taille
    lifeSpan=1000; // duree de vie
    pDeath=0.01; // Proba de mort par collision
    pClone=0.01; // Proba de clonage
    percep = Perception();
}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   std::cout << "const Bestiole (" << identite << ") par copie" << std::endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   //memcpy( couleur, b.couleur, 3*sizeof(T) );
   const T* bcoul = b.getCouleur();
    couleur[0] = bcoul[0];
    couleur[1] = bcoul[1];
    couleur[2] = bcoul[2];

    size=10 ; // taille
    lifeSpan=1000; // duree de vie
    pDeath=0.01; // Proba de mort par collision
    pClone=0.01; // Proba de clonage
    percep = Perception();
}


Bestiole::~Bestiole( void )
{

    std::cout << "Deleteing bestiole\r\n";
    std::cout << "Couleur : " << std::hex << &couleur << std::endl;
    delete[] couleur;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }
    this->lifeSpan--;
}


void Bestiole::action( Milieu & monMilieu )
{

   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

int Bestiole::getIdentite() const {
    return identite;
}

int Bestiole::getX() const {
    return x;
}

void Bestiole::setX(int x) {
    Bestiole::x = x;
}

int Bestiole::getY() const {
    return y;
}

void Bestiole::setY(int y) {
    Bestiole::y = y;
}

double Bestiole::getSize() const {
    return size;
}


int Bestiole::getLifeSpan() const {
    return lifeSpan;
}


double Bestiole::getOrientation() const {
    return orientation;
}

void Bestiole::setOrientation(double orientation) {
    Bestiole::orientation = orientation;
}

double Bestiole::getVitessePolaire() const {
    return vitesse;
}

void Bestiole::setVitessePolaire(double vitesse) {
    Bestiole::vitesse = vitesse;
}

bool Bestiole::getIsSchizo() const {
    return isSchizo;
}

double Bestiole::getPDeath() const {
    return pDeath;
}

void Bestiole::setPDeath(double pDeath) {
    Bestiole::pDeath = pDeath;
}

double Bestiole::getPClone() const {
    return pClone;
}

void Bestiole::setPClone(double pClone) {
    Bestiole::pClone = pClone;
}

void Bestiole::setVitesseCartesien(double x, double y) {
    this->setVitessePolaire(sqrt(x * x + y * y));
}

std::array<double, 2> Bestiole::getVitesseCartesien() {
    std::array<double,2> coord{};
    coord[0] = vitesse*cos(orientation);
    coord[1] = vitesse*sin(orientation);
    return coord;
}

std::vector<Accessoire> Bestiole::getAccessoires() {
    return this->listAccessoire;
}

void Bestiole::addAccessoires(Accessoire &acc) {
    this->listAccessoire.push_back(acc);
}

void Bestiole::collide() {
    orientation=-orientation;
}
