/**
 * @file LifeManager.h
 * @brief Classe faisant la gestion de la vie/mort des bestioles à chaque tour
 */

#ifndef AZIZINTHEJUNGLE_LIFEMANAGER_H
#define AZIZINTHEJUNGLE_LIFEMANAGER_H
#include <vector>
#include "Bestiole.h"


/**
 * @brief Classe faisant la gestion de la vie/mort des bestioles à chaque tour
 */
class LifeManager {
private:
    static int nb_mort[4];
    static int nb_clon[4];
    static bool intersect(const Bestiole& b1, const Bestiole& b2);
public:
    static void step(std::vector<Bestiole> & list, int xLim, int yLim);
    void getStat();
};


#endif //AZIZINTHEJUNGLE_LIFEMANAGER_H
