#ifndef ANIMAL_H
#define ANIMAL_H

#include "EntitateEcosistem.h"
#include <memory>

class Animal : public EntitateEcosistem {
public:
    Animal(const std::string& n, float e, float rs, float x_pos, float y_pos);
    virtual void mananca(EntitateEcosistem* prada) = 0;
    virtual std::shared_ptr<Animal> reproduce() = 0;
};

#endif
