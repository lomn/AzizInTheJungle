/**
* @file Yeux.h
* @brief Il s'agit d'un des capteurs qu'un bestiole peut posséder, elle possède une distance et un angle de vision,
 * ainsi qu'une capacité de détection
 */

#ifndef _YEUX_H_
#define _YEUX_H_

class Bestiole;

class Yeux{
private:
    double m_angle;
    double m_distance;
    double m_capDetec;

public:
    Yeux(double angle, double distance, double detection);
    Yeux(): Yeux(0,0,0){};
    Yeux(const Yeux & yeuxOrigine);
    ~Yeux();
    Yeux & operator=(const Yeux & y);
    double getAngle() const;
    double getDistance() const;
    double getCapaDetec() const;
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const;
};

#endif