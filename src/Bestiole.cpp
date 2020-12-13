#include "Bestiole.h"

#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include "Comportement/Comportement.h"
#include "Comportement/Gregaire.h"
#include "Comportement/Kamikaze.h"
#include "Comportement/Prevoyant.h"
#include "Comportement/Peureux.h"
#include "Accessoire/Accessoire.h"
#include "Accessoire/Carapace.h"
#include "Accessoire/Nageoire.h"

const double INIT_SIZE = 4;
const int INIT_LIFESPAN = 150;
const double INIT_PDEATH = 0.01;
const double INIT_PCLONE = 0.005;
const bool INIT_ISSCHIZO = false;

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 100.;

int               Bestiole::next = 0;
std::array<Comportement *, 4>  Bestiole::comportementArray = initComportements();

std::array<Comportement *, 4> Bestiole::initComportements() {
    std::array<Comportement*, 4> array = {new Kamikaze(), new Prevoyant(), new Gregaire(), new Peureux()};
    return array;
}


T* Bestiole::getCouleur() const{
    return this->couleur;
}

Bestiole::Bestiole()
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

    size=INIT_SIZE ; // taille
    lifeSpan= INIT_LIFESPAN + (int)(((double)rand()/(double)RAND_MAX)*200-100); // duree de vie
    pDeath=INIT_PDEATH; // Proba de mort par collision
    pClone=INIT_PCLONE; // Proba de clonage
    isSchizo=INIT_ISSCHIZO;
    comportement=PEUREUX_IND;
    //accessoireArray;
}


Bestiole::Bestiole( const Bestiole & b )
{

    identite = ++next;

    std::cout << "const Bestiole (" << identite << ") par copie" << std::endl;

    x = b.getX();
    y = b.getY();
    cumulX = cumulY = 0.;
    orientation = b.getOrientation();
    vitesse = b.getVitessePolaire();
    couleur = new T[ 3 ];
    printf("T (const) : %p\n", couleur);
    memcpy( couleur, b.couleur, 3*sizeof(T) );

    size=b.getSize(); // taille
    lifeSpan=INIT_LIFESPAN + (int)(((double)rand()/(double)RAND_MAX)*200-100); // duree de vie
    pDeath=b.getPDeath(); // Proba de mort par collision
    pClone=b.getPClone(); // Proba de clonage
    isSchizo=b.getIsSchizo();
    comportement = b.getComportement();

    //Copie des accessoires
    std::vector<Accessoire*> acc = b.getAccessoire();
    for(size_t i = acc.size()-1; ((int)i) >= 0; i--) {
        if(acc[i]->getCoefCarapace() > 0){
            this->addAccessoire(new Carapace(acc[i]->getCoefCarapace()));
        }
        else if(acc[i]->getCoefNageoire() > 0){
            this->addAccessoire(new Nageoire(acc[i]->getCoefNageoire()));
        }
    }
}

Bestiole & Bestiole::operator=(const Bestiole & b){

    identite = b.getIdentite();

    x = b.getX();
    y = b.getY();
    cumulX = cumulY = 0.;
    orientation = b.getOrientation();
    vitesse = b.getVitessePolaire();
    delete[] couleur;
    couleur = new T[ 3 ];
    printf("T (const) : %p\n", couleur);
    memcpy( couleur, b.couleur, 3*sizeof(T) );

    size=b.getSize(); // taille
    lifeSpan=b.getLifeSpan(); // duree de vie
    pDeath=b.getPDeath(); // Proba de mort par collision
    pClone=b.getPClone(); // Proba de clonage
    isSchizo=b.getIsSchizo();
    comportement=b.getComportement();
    
    std::vector<Accessoire*> acc = b.getAccessoire();
    for(size_t i = acc.size()-1; ((int)i) >= 0; i--) {
        if(acc[i]->getCoefCarapace() > 0){
            this->addAccessoire(new Carapace(acc[i]->getCoefCarapace()));
        }
        else if(acc[i]->getCoefNageoire() > 0){
            this->addAccessoire(new Nageoire(acc[i]->getCoefNageoire()));
        }
    }

    return *this;
}


Bestiole::~Bestiole()
{

    std::cout << "Deleteing bestiole (" << identite << ")" << std::endl;
    std::cout << "Couleur : " << std::hex << &couleur << std::oct <<std::endl;
    delete[] couleur;
    
    for(size_t i = accessoireArray.size()-1; ((int)i) >= 0; i--) {
        delete accessoireArray[i];
    }

}


void Bestiole::initCoords( int xLim, int yLim )
{
   x = rand() % xLim;
   y = rand() % yLim;
}


void Bestiole::bouge( int xLim, int yLim, std::vector<Bestiole> & list )
{
    std::array<double, 2> update_vitesse = comportementArray[comportement]->calculVitesse(*this, list);
    std::cout << "New v = (" << update_vitesse[0] << ", " << update_vitesse[1] << ")" << std::endl;
    vitesse= update_vitesse[0];
    orientation=update_vitesse[1];
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

   bouge( monMilieu.getWidth(), monMilieu.getHeight() , monMilieu.getListeBestiole());

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

    dist = std::sqrt( (x-b.getX())*(x-b.getY()) + (y-b.getY())*(y-b.getY()) );
    return ( dist <= LIMITE_VUE );
}

std::array<double, 2> Bestiole::getVitesseCartesien() {
    std::array<double,2> coord{};
    coord[0] = vitesse*cos(orientation);
    coord[1] = vitesse*sin(orientation);
    return coord;
}



void Bestiole::collide() {
    orientation=-orientation;
}



//Getters and Setters
int Bestiole::getIdentite() const {return identite;}
int Bestiole::getX() const {return x;}
void Bestiole::setX(int x) {Bestiole::x = x;}
int Bestiole::getY() const {return y;}
void Bestiole::setY(int y) {Bestiole::y = y;}
double Bestiole::getSize() const {return size;}
int Bestiole::getLifeSpan() const {return lifeSpan;}
double Bestiole::getOrientation() const {return orientation;}
void Bestiole::setOrientation(double orientation) {Bestiole::orientation = orientation;}
double Bestiole::getVitessePolaire() const {return vitesse;}
void Bestiole::setVitessePolaire(double vitesse) {Bestiole::vitesse = vitesse;}
bool Bestiole::getIsSchizo() const {return isSchizo;}
double Bestiole::getPDeath() const {return pDeath;}
void Bestiole::setPDeath(double pDeath) {Bestiole::pDeath = pDeath;}
double Bestiole::getPClone() const {return pClone;}
void Bestiole::setPClone(double pClone) {Bestiole::pClone = pClone;}
void Bestiole::setVitesseCartesien(double x, double y) {this->setVitessePolaire(sqrt(x * x + y * y));}
int Bestiole::getComportement() const {return this->comportement;}
void Bestiole::setComportement(int c){this->comportement = c;}
std::vector<Accessoire*> Bestiole::getAccessoire() const {return this->accessoireArray;}
void Bestiole::addAccessoire(Accessoire* acc){this->accessoireArray.push_back(acc);}