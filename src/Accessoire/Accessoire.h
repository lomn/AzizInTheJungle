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
    virtual char* getType(){return "None";};
    virtual double getCoefCarapace(){return 0;};
    virtual double getCoefCamouflage(){return 0;};
    virtual double getCoefNageoire(){return 0;};
};


#endif
