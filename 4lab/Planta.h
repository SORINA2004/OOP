#ifndef PLANTA_H
#define PLANTA_H

#include "EntitateEcosistem.h"
#include <memory>

class Planta : public EntitateEcosistem {
public:
    Planta(const std::string& n, float e, float rs, float x_pos, float y_pos);
    void mananca(EntitateEcosistem* prada) override;
    std::shared_ptr<Planta> reproduce();
    void afiseaza() const override;
};

#endif
