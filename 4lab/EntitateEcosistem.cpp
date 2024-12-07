#include "EntitateEcosistem.h"
#include <iostream>

EntitateEcosistem::EntitateEcosistem(const std::string& n, float e, float rs, float x_pos, float y_pos)
    : nume(n), energie(e), rataSupravietuire(rs), x(x_pos), y(y_pos) {}

std::string EntitateEcosistem::getNume() const { return nume; }
float EntitateEcosistem::getEnergie() const { return energie; }

void EntitateEcosistem::scadeEnergie(float valoare) { energie -= valoare; }
void EntitateEcosistem::muta(float dx, float dy) { x += dx; y += dy; }

void EntitateEcosistem::afiseaza() const {
    std::cout << "Nume: " << nume << ", Energie: " << energie 
              << ", Pozitie: (" << x << ", " << y << "), Rata Supravietuire: " << rataSupravietuire << std::endl;
}

EntitateEcosistem::~EntitateEcosistem() {}
