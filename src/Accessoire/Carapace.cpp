#include "Carapace.h"

Carapace::Carapace(double coefCarapace){
    m_coefCarapace = coefCarapace;
    return;
}

Carapace::Carapace(const Carapace & copieCarapace){
    m_coefCarapace = copieCarapace.getCoefCarapace();
}

//-_-_-

const char* Carapace::getType() const {
    return "Carapace";
}

double Carapace::getCoefCarapace() const {
    return m_coefCarapace;
}

void Carapace::setCoefCarapace(double coefCarapace){
    m_coefCarapace = coefCarapace;
}
