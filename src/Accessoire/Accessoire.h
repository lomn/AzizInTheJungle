#ifndef _ACCESSOIRE_H_
#define _ACCESSOIRE_H_

#include <iostream>
#include <vector>

//using namespace std;





class Accessoire
{
private:
    //char* Type;

public:
    Accessoire(){};
    Accessoire(Accessoire const& accessoire){};
    virtual ~Accessoire(){};
    virtual const char* getType() const{return "None";};
    virtual double getCoefCarapace() const{return 0;};
    virtual double getCoefCamouflage() const{return 0;};
    virtual double getCoefNageoire() const{return 0;};
};


#endif
