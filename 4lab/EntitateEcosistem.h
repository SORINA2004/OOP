#ifndef ENTITATE_ECOSISTEM_H
#define ENTITATE_ECOSISTEM_H

#include <string>

class EntitateEcosistem {
protected:
    std::string nume;
    float energie;
    float rataSupravietuire;
    float x, y;  // Pozitie (x, y)

public:
    EntitateEcosistem(const std::string& n, float e, float rs, float x_pos, float y_pos);
    virtual std::string getNume() const;
    virtual float getEnergie() const;
    virtual void mananca(EntitateEcosistem* prada) = 0;
    virtual void scadeEnergie(float valoare);
    virtual void muta(float dx, float dy);
    virtual void afiseaza() const;
    virtual ~EntitateEcosistem();
};

#endif
