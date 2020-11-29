#ifndef _YEUX_H_
#define _YEUX_H_

#include "../Bestiole.h"

class Yeux{
private:
    const Bestiole & thisBestiole;
    double m_angle;
    double m_distance;

public:
    Yeux(double angle, double distance, const Bestiole & bestiole);
    Yeux(Yeux yeuxOrigine);
    ~Yeux();

    double getAngle();
    double getDistance();
    double jeTeVois(const Bestiole & bestiole);
};

#endif