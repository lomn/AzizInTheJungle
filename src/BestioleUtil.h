/**
* @file BestiolUtil.h
* @brief Il s'agit d'une ensemble de méthodes utiles à la bestiole
 */


#ifndef _BESTIOLES_UTIL_H_
#define _BESTIOLES_UTIL_H_

#include <vector>
#include <array>

class Bestiole;
class Accessoire;

void showAll(std::vector<Bestiole> &);
double distanceBestiole(const Bestiole & a, const Bestiole & b);
std::array<double, 2> CartesienToPolaire(std::array<double, 2> v);
double getCarapvalue(std::vector<Accessoire> list);
double getCamvalue(std::vector<Accessoire> list);
double getNagvalue(std::vector<Accessoire> list);
void ShowAllIds(const std::vector<Bestiole> & list);

#endif
