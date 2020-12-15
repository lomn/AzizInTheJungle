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



// Constructors

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
    scareCount=0;
    prevSpeed=0.;
    accessoireArray.clear();
}


Bestiole::Bestiole( const Bestiole & b )
{

    identite = ++next;

    std::cout << "const Bestiole (" << identite << ") par copie " << accessoireArray.size() << std::endl;

    x = b.getX();
    y = b.getY();
    cumulX = cumulY = 0.;
    orientation = b.getOrientation();
    vitesse = b.getVitessePolaire();
    couleur = new T[ 3 ];
    memcpy( couleur, b.couleur, 3*sizeof(T) );

    size=b.getSize(); // taille
    lifeSpan=INIT_LIFESPAN + (int)(((double)rand()/(double)RAND_MAX)*200-100); // duree de vie
    pDeath=b.getPDeath(); // Proba de mort par collision
    pClone=b.getPClone(); // Proba de clonage
    isSchizo=b.getIsSchizo();
    comportement = b.getComportement();
    scareCount=b.getScareCount();
    prevSpeed=b.getPrevSpeed();
    accessoireArray.clear();

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

Bestiole::~Bestiole()
{

    std::cout << "Deleteing bestiole (" << identite << ")" << std::endl;
    std::cout << "Couleur : " << std::hex << &couleur << std::oct <<std::endl;
    delete[] couleur;

}

// Operators
Bestiole & Bestiole::operator=(const Bestiole & b){

    identite = b.getIdentite();

    x = b.getX();
    y = b.getY();
    cumulX = cumulY = 0.;
    orientation = b.getOrientation();
    vitesse = b.getVitessePolaire();
    delete[] couleur;
    couleur = new T[ 3 ];
    printf("T (const) : %p      \n", couleur);
    memcpy( couleur, b.couleur, 3*sizeof(T) );

    size=b.getSize(); // taille
    lifeSpan=b.getLifeSpan(); // duree de vie
    pDeath=b.getPDeath(); // Proba de mort par collision
    pClone=b.getPClone(); // Proba de clonage
    isSchizo=b.getIsSchizo();
    comportement=b.getComportement();
    scareCount=b.getScareCount();
    prevSpeed=b.getPrevSpeed();

    for(size_t i = accessoireArray.size()-1; ((int)i) >= 0; i--) {
        delete accessoireArray[i];
    }
    accessoireArray.clear();

    std::cout << "0 " << this->accessoireArray.size() << std::endl;
    std::vector<Accessoire*> acc = b.getAccessoire();
    for(size_t i = acc.size()-1; ((int)i) >= 0; i--) {
        if(acc[i]->getCoefCarapace() > 0){
            this->addAccessoire(new Carapace(acc[i]->getCoefCarapace()));
        }
        else if(acc[i]->getCoefNageoire() > 0){
            this->addAccessoire(new Nageoire(acc[i]->getCoefNageoire()));
        }
    }
    std::cout << "0 " << this->accessoireArray.size() << std::endl;

    return *this;
}

bool operator==( const Bestiole & b1, const Bestiole & b2 )
{
    return ( b1.identite == b2.identite );
}

void Bestiole::initCoords( int xLim, int yLim )
{
   x = rand() % xLim;
   y = rand() % yLim;
}

void Bestiole::action( Milieu & monMilieu )
{
    bouge( monMilieu.getWidth(), monMilieu.getHeight() , monMilieu.getListeBestiole());
}

void Bestiole::bouge( int xLim, int yLim, std::vector<Bestiole> & list )
{
    std::array<double, 2> update_vitesse = comportementArray[comportement]->calculVitesse(*this, list);
//    std::cout << "New v = (" << update_vitesse[0] << ", " << update_vitesse[1] << ")" << std::endl;
    this->setVitessePolaire(update_vitesse[0]);
    this->setOrientation(update_vitesse[1]);
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




void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}

bool Bestiole::jeTeVois( const Bestiole & b ) const
{
    double         dist;

    dist = std::sqrt( (x-b.getX())*(x-b.getY()) + (y-b.getY())*(y-b.getY()) );
    return ( dist <= LIMITE_VUE );
}

std::array<double, 2> Bestiole::getVitesseCartesienPondere() const {
    std::array<double,2> coord{};
    coord[0] = this->getVitessePolairePondere()*cos(orientation);
    coord[1] = this->getVitessePolairePondere()*sin(orientation);
    return coord;
}

std::array<double, 2> Bestiole::getVitesseCartesien() const {
    std::array<double,2> coord{};
    coord[0] = this->getVitessePolaire()*cos(orientation);
    coord[1] = this->getVitessePolaire()*sin(orientation);
    return coord;
}

double Bestiole::getVitessePolaire() const {
    double c = 1;
    for(size_t i = 0; i != accessoireArray.size(); i++){
        if(accessoireArray[i]->getCoefNageoire() > 0){
            c *= accessoireArray[i]->getCoefNageoire();
        }
    }
    return vitesse*c;
}


void Bestiole::collide() {
    orientation=-orientation;
}


double Bestiole::getPDeathPondere() const {
    double c = 0;
    for(size_t i = 0; i != accessoireArray.size(); i++){
        c += accessoireArray[i]->getCoefCarapace();
    }
    if(c > 1){c=1;}
    return pDeath*(1-c);
}


//Getters and Setters
int Bestiole::getIdentite() const {return identite;}
int Bestiole::getX() const {return x;}
void Bestiole::setX(int nx) {Bestiole::x = nx;}
int Bestiole::getY() const {return y;}
void Bestiole::setY(int ny) {Bestiole::y = ny;}
double Bestiole::getSize() const {return size;}
int Bestiole::getLifeSpan() const {return lifeSpan;}
double Bestiole::getOrientation() const {return orientation;}
void Bestiole::setOrientation(double o) {Bestiole::orientation = o;}
void Bestiole::setVitessePolaire(double v) {
    if (v<MAX_VITESSE) {Bestiole::vitesse = v;}
    else{Bestiole::vitesse = MAX_VITESSE;}
}
bool Bestiole::getIsSchizo() const {return isSchizo;}
double Bestiole::getPDeath() const {return pDeath;}
void Bestiole::setPDeath(double probaDeath) {Bestiole::pDeath = probaDeath;}
double Bestiole::getPClone() const {return pClone;}
void Bestiole::setPClone(double probaClone) {Bestiole::pClone = probaClone;}
void Bestiole::setVitesseCartesien(double nx, double ny) {this->setVitessePolaire(sqrt(nx * nx + ny * ny));}
int Bestiole::getComportement() const {return this->comportement;}
std::vector<Accessoire*> Bestiole::getAccessoire() const {return this->accessoireArray;}
void Bestiole::addAccessoire(Accessoire* acc){this->accessoireArray.push_back(acc);}
double Bestiole::getVitessePolairePondere() const {return vitesse;}
void Bestiole::setComportement(int c){
    this->comportement = c;
    if (c==KAMIKAZE_IND)  couleur[ 0 ]=255, couleur[ 1 ]=000, couleur[ 2 ]=000;
    if (c==GREGAIRE_IND)  couleur[ 0 ]=000, couleur[ 1 ]=255, couleur[ 2 ]=000;
    if (c==PEUREUX_IND)   couleur[ 0 ]=000, couleur[ 1 ]=000, couleur[ 2 ]=255;
    if (c==PREVOYANT_IND) couleur[ 0 ]=000, couleur[ 1 ]=000, couleur[ 2 ]=000;
}
int Bestiole::getScareCount() const {return scareCount;}
void Bestiole::setScareCount(int sc) {Bestiole::scareCount = sc;}
double Bestiole::getPrevSpeed() const {return prevSpeed;}
void Bestiole::setPrevSpeed(double ps) {Bestiole::prevSpeed = ps;}
T* Bestiole::getCouleur() const{
    return this->couleur;
}

