/**
* @file Oreilles.h
* @brief Il s'agit d'un des capteurs qu'un bestiole peut posséder, elle possède une distance d'audition,
 * ainsi qu'une capacité de détection
 */

#ifndef _OREILLES_H_
#define _OREILLES_H_


class Bestiole;

class Oreilles{
private:
    double m_distance;
    double cap_detec;

public:
    Oreilles(double distance, double capa_detec);
    Oreilles(const Oreilles & OreillesOrigine);
    Oreilles(): Oreilles((double)0, (double)0) {};
    ~Oreilles();
    Oreilles & operator=(const Oreilles & o);
    double getDistance() const;
    double getCapDetec() const;
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const;
};

#endif