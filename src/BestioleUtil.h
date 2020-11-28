#ifndef _BESTIOLES_UTIL_H_
#define _BESTIOLES_UTIL_H_

#include <vector>

class Bestiole;
class Accessoire;


double distance(const Bestiole a, const Bestiole b);
double getCarapvalue(std::vector<Accessoire> list);
double getCamvalue(std::vector<Accessoire> list);
double getNagvalue(std::vector<Accessoire> list);

#endif
