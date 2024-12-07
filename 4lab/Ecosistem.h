#ifndef ECOSISTEM_H
#define ECOSISTEM_H

#include "EntitateEcosistem.h"
#include <vector>
#include <string>
#include <memory>

class Ecosistem {
private:
    std::vector<std::shared_ptr<EntitateEcosistem>> entitati;
    std::vector<std::string> jurnalInteractiuni;

public:
    void adaugaEntitate(std::shared_ptr<EntitateEcosistem> entitate);
    void simuleaza();
    void atac();
    void reproducere();
    void adaugaEntitateDinInput();
    void genereazaEvenimentAleator();
    void genereazaRaport();
};

#endif
