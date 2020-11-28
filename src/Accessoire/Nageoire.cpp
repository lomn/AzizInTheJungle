#include "Nageoire.h"

Nageoire::Nageoire(double coefNageoire){
    m_coefNageoire = coefNageoire;
    return;
}

Nageoire::Nageoire(const Nageoire & copieNageoire){
    m_coefNageoire = copieNageoire.getCoefNageoire();
}

//-_-_-

const char* Nageoire::getType() const {
    return "Nageoire";
}

double Nageoire::getCoefNageoire() const {
    return m_coefNageoire;
}

void Nageoire::setCoefNageoire(double coefNageoire){
    m_coefNageoire = coefNageoire;
}
