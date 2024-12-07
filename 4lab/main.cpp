#include <iostream>
#include "EntitateEcosistem.h"
#include "Ecosistem.h"
#include "Erbivor.h"
#include "Planta.h"
#include "Carnivor.h"
#include "Animal.h"

int main() {
    srand(time(0));

    Ecosistem ecosistem;

    while (true) {
        std::cout << "\n============================\n";
        std::cout << "       Meniu Principal       \n";
        std::cout << "============================\n";
        std::cout << "1. Adauga entitate\n";
        std::cout << "2. Simuleaza ecosistem\n";
        std::cout << "3. Generare eveniment aleatoriu\n";
        std::cout << "4. Atac intre entitati\n";
        std::cout << "5. Reproducere entitate\n";
        std::cout << "6. Raport\n";
        std::cout << "7. Iesire\n";
        std::cout << "============================\n";
        std::cout << "Alege o optiune (1-7): ";

        int optiune;
        std::cin >> optiune;

        if (optiune == 1) {
            ecosistem.adaugaEntitateDinInput();
        } else if (optiune == 2) {
            ecosistem.simuleaza();
        } else if (optiune == 3) {
            ecosistem.genereazaEvenimentAleator();
        } else if (optiune == 4) {
            ecosistem.atac();
        } else if (optiune == 5) {
            ecosistem.reproducere();
        } else if (optiune == 6) {
            ecosistem.genereazaRaport();
        } else if (optiune == 7) {
            std::cout << "Iesire din program. La revedere!\n";
            break;
        } else {
            std::cout << "Optiune invalida! Te rugam sa alegi o optiune intre 1 si 7.\n";
        }
    }

    return 0;
}
