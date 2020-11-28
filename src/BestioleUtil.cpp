#include<math.h>

double distanceBestioles(const Bestiole a, const Bestile b){
    double x =(float)(a.getX()-b.getX());
    double y =(float)(a.getY()-b.getY());
    return math.sqrt(x*x+y*y)
}