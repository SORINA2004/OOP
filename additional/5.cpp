#include <iostream>

class BMW;  

class Audi {
private:
    int speed;  

public:
    Audi(int s) : speed(s) {}

    friend void compareSpeed(const Audi& a, const BMW& b);
};

class BMW {
private:
    int speed;  

public:
    BMW(int s) : speed(s) {}

    friend void compareSpeed(const Audi& a, const BMW& b);
};

// Funcția friend care accesează viteza privată din ambele clase și le compară
void compareSpeed(const Audi& a, const BMW& b) {
    std::cout << "Viteza Audi: " << a.speed << " km/h" << std::endl;
    std::cout << "Viteza BMW: " << b.speed << " km/h" << std::endl;

    if (a.speed > b.speed)
        std::cout << "Audi este mai rapid." << std::endl;
    else if (a.speed < b.speed)
        std::cout << "BMW este mai rapid." << std::endl;
    else
        std::cout << "Ambele masini au aceeași viteză." << std::endl;
}

int main() {
    Audi myAudi(220);  
    BMW myBMW(240);    

    compareSpeed(myAudi, myBMW);

    return 0;
}
