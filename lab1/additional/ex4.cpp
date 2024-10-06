#include <iostream>
using namespace std;

class CarteB;  // Declarație înainte de definirea clasei CarteB

class CarteA {
private:
    int dataCarteA;

public:
    CarteA(int val) : dataCarteA(val) {}

    // Funcție friend care poate accesa membrii privați ai clasei CarteA
    friend void showData(const CarteA& carteA, const CarteB& carteB);

    // Metodă pentru a seta valoarea lui dataCarteA (pentru demonstrație)
    void setDataCarteA(int val) {
        dataCarteA = val;
    }

    // Metodă pentru a obține valoarea lui dataCarteA (pentru demonstrație)
    int getDataCarteA() const {
        return dataCarteA;
    }
};

class CarteB {
private:
    int dataCarteB;

public:
    CarteB(int val) : dataCarteB(val) {}

    // Funcție friend care poate accesa membrii privați ai clasei CarteB
    friend void showData(const CarteA& carteA, const CarteB& carteB);

    // Metodă pentru a seta valoarea lui dataCarteB (pentru demonstrație)
    void setDataCarteB(int val) {
        dataCarteB = val;
    }

    // Metodă pentru a obține valoarea lui dataCarteB (pentru demonstrație)
    int getDataCarteB() const {
        return dataCarteB;
    }
};

// Funcție friend care poate accesa datele private ale claselor CarteA și CarteB
void showData(const CarteA& carteA, const CarteB& carteB) {
    cout << "Data din clasa CarteA: " << carteA.dataCarteA << endl;
    cout << "Data din clasa CarteB: " << carteB.dataCarteB << endl;
}

int main() {
    CarteA carteA(10);   // Obiect al clasei CarteA
    CarteB carteB(20);   // Obiect al clasei CarteB

    // Afișează datele folosind funcția friend
    showData(carteA, carteB);

    // Modifică datele folosind metodele publice
    carteA.setDataCarteA(30);
    carteB.setDataCarteB(40);

    // Afișează datele actualizate
    showData(carteA, carteB);

    return 0;
}
