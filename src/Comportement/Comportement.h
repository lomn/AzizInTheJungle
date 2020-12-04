//
// Created by sella on 04/12/2020.
//

#ifndef AZIZINTHEJUNGLE_COMPORTEMENT_H
#define AZIZINTHEJUNGLE_COMPORTEMENT_H

class Bestiole;

class Comportement {
private:
    const char * nom;
public:
    Comportement();
    virtual float * calculVitesse(const Bestiole &b);
};


#endif //AZIZINTHEJUNGLE_COMPORTEMENT_H
