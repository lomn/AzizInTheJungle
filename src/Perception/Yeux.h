#ifndef _YEUX_H_
#define _YEUX_H_

#include "../Bestiole.h"

class Yeux{
private:
    const Bestiole * thisBestiole;
    double m_angle;
    double m_distance;

public:
    Yeux(double angle, double distance, const Bestiole & bestiole);
    Yeux(const Yeux & yeuxOrigine);
    ~Yeux();

    double getAngle() const;
    double getDistance() const;
    Bestiole * getBestiole() const;
    bool jeTeVois(const Bestiole & bestiole);
};

#endif