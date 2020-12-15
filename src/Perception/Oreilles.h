#ifndef _OREILLES_H_
#define _OREILLES_H_


class Bestiole;

class Oreilles{
private:
    double m_distance;

public:
    Oreilles(double distance);
    Oreilles(const Oreilles & OreillesOrigine);
    Oreilles(): Oreilles((double)0) {};
    ~Oreilles();
    Oreilles & operator=(const Oreilles & o);
    double getDistance() const;
    bool jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const;
};

#endif