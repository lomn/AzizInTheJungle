//
// Created by sella on 28/11/2020.
//

#ifndef AZIZINTHEJUNGLE_LIFEMANAGER_H
#define AZIZINTHEJUNGLE_LIFEMANAGER_H
#include <vector>
#include "Bestiole.h"


class LifeManager {
private:
    //noparam
    static bool intersect(Bestiole& b1, Bestiole& b2);
public:
    static void step(std::vector<Bestiole> & list);
};


#endif //AZIZINTHEJUNGLE_LIFEMANAGER_H
