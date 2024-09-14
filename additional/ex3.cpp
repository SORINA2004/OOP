#include <iostream>
#include <string>
using namespace std;

class Carte {
public:
    string titlu;
    string autor;
    int ISBN;

    Carte(string t, string a, int i) : titlu(t), autor(a), ISBN(i) {
        cout << "Constructorul pentru cartea '" << titlu << "' a fost apelat.\n";
    }

    ~Carte() {
        cout << "Destructorul pentru cartea '" << titlu << "' a fost apelat.\n";
    }
};

int main() {
   
    Carte carteNoua("Micul Print", "Mark Twain", 215403);

    return 0;
}
