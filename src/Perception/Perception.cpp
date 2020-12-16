#include "../Bestiole.h"
#include "Perception.h"
#include "Oreilles.h"
#include "Yeux.h"
#include <vector>
#include <iostream>


Perception::Perception(){
    std::cout << "Percep init" << std::endl;
    yeuxVect = std::vector<Yeux>();
    oreilleVect = std::vector<Oreilles>();
}

Perception::Perception(const Perception &p) {
    std::cout << "Percep copie prof" << std::endl;
    yeuxVect = std::vector<Yeux>();
    oreilleVect = std::vector<Oreilles>();

    if (!p.getOreilleVect().empty()){
        for (std::vector<Oreilles>::size_type i=0;i<p.getOreilleVect().size();i++){
            oreilleVect.push_back(p.getOreilleVect()[i]);
        }
    }
    if (!p.getYeuxVect().empty()){
        for (std::vector<Yeux>::size_type i=0;i<p.getYeuxVect().size();i++){
            yeuxVect.push_back(p.getYeuxVect()[i]);
        }
    }
};


Perception &Perception::operator=(const Perception &p) {
    yeuxVect = std::vector<Yeux>();
    oreilleVect = std::vector<Oreilles>();
    std::cout << "Percep copie affec" << std::endl;
    if (!p.getOreilleVect().empty()){
        for (std::vector<Oreilles>::size_type i=0;i<p.getOreilleVect().size();i++){
            oreilleVect.push_back(p.getOreilleVect()[i]);
        }
    }
    if (!p.getYeuxVect().empty()){
        for (std::vector<Yeux>::size_type j=0;j<p.getYeuxVect().size();j++){
            yeuxVect.push_back(p.getYeuxVect()[j]);
        }
    }
    return *this;
}

Perception::~Perception() {}

bool Perception::jeTeVois(const Bestiole & thisBestiole, const Bestiole & bestiole) const{
//    std::cout << "Perception par oreilles in" << std::endl;

    if (!oreilleVect.empty()){
//        std::cout << "not empty" << std::endl;
        for (std::vector<Oreilles>::size_type i=0;i<oreilleVect.size();i++){
//            std::cout << "inloop" << std::endl;
            std::cout << oreilleVect[i].jeTeVois(thisBestiole, bestiole) << std::endl;
            if (oreilleVect[i].jeTeVois(thisBestiole, bestiole)){
                std::cout << "Perception par oreilles" << std::endl;
                return true;
            }
        }
    }
//    std::cout << "Perception par oreilles out" << std::endl;
//    std::cout << "Perception par yeux in" << std::endl;

    if (yeuxVect.size()>0){
        for (std::vector<Oreilles>::size_type i=0;i<yeuxVect.size();i++){
            if (yeuxVect[i].jeTeVois(thisBestiole, bestiole)){
                std::cout << "Perception par yeux" << std::endl;
                return true;
            }
        }
    }
//    std::cout << "Perception par yeux out" << std::endl;
    return false;
}

void Perception::addYeux(const Yeux& y) {
    yeuxVect.push_back(y);
}

void Perception::addOreille(const Oreilles& o) {
    oreilleVect.push_back(o);}

const std::vector<Yeux> &Perception::getYeuxVect() const {return yeuxVect;}

const std::vector<Oreilles> &Perception::getOreilleVect() const {return oreilleVect;}

