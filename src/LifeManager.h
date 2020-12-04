//
// Created by sella on 28/11/2020.
//

#ifndef AZIZINTHEJUNGLE_LIFEMANAGER_H
#define AZIZINTHEJUNGLE_LIFEMANAGER_H
#include <vector>
#include "Bestiole.h"


class LifeManager {
private:
    static int nb_mort;
    static int nb_clon;
    static bool intersect(const Bestiole& b1, const Bestiole& b2);
public:
    static void step(std::vector<Bestiole> & list, int xLim, int yLim);
    void getStat();
};


#endif //AZIZINTHEJUNGLE_LIFEMANAGER_H
