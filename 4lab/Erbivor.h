#ifndef ERBIVOR_H
#define ERBIVOR_H

#include "Animal.h"
#include <memory>

class Erbivor : public Animal {
public:
    Erbivor(const std::string& n, float e, float rs, float x_pos, float y_pos);
    void mananca(EntitateEcosistem* prada) override;
    std::shared_ptr<Animal> reproduce() override;
};

#endif
