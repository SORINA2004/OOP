#ifndef CARNIVOR_H
#define CARNIVOR_H

#include "Animal.h"
#include <memory>

class Carnivor : public Animal {
public:
    Carnivor(const std::string& n, float e, float rs, float x_pos, float y_pos);
    void mananca(EntitateEcosistem* prada) override;
    std::shared_ptr<Animal> reproduce() override;
};

#endif
