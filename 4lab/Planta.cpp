#include "Planta.h"
#include <iostream>

Planta::Planta(const std::string& n, float e, float rs, float x_pos, float y_pos)
    : EntitateEcosistem(n, e, rs, x_pos, y_pos) {}

void Planta::mananca(EntitateEcosistem* prada) {
    // Plantele nu pot mânca.
}

std::shared_ptr<Planta> Planta::reproduce() {
    return std::make_shared<Planta>("Noua Planta", rand() % 10 + 5, 0.9, x + rand() % 10 - 5, y + rand() % 10 - 5);
}

void Planta::afiseaza() const {
    std::cout << "Planta " << nume << " la pozitia (" << x << ", " << y << ") cu energie: " << energie << " si rata de supravietuire: " << rataSupravietuire << std::endl;
}
