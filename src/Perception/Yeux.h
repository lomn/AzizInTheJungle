#ifndef _YEUX_H_
#define _YEUX_H_

class Bestiole;

class Yeux{
private:
    double m_angle;
    double m_distance;

public:
    Yeux(double angle, double distance);
    Yeux(const Yeux & yeuxOrigine);
    ~Yeux();

    double getAngle() const;
    double getDistance() const;
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole);
};

#endif