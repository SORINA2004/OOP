#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Carte {
public:
    string titlu;
    string autor;
    int ISBN;

    Carte(string t, string a, int i) : titlu(t), autor(a), ISBN(i) {}
};

class Biblioteca {
private:
    vector<Carte> carti;  

public:
    
    void adaugaCarte(const Carte& carte) {
        carti.push_back(carte);
        cout << "Cartea a fost adaugata cu succes!\n";
    }

    void stergeCarte(int isbn) {
        for (auto it = carti.begin(); it != carti.end(); ++it) {
            if (it->ISBN == isbn) {
                carti.erase(it);
                cout << "Cartea cu ISBN " << isbn << " a fost stearsa.\n";
                return;
            }
        }
        cout << "Cartea cu ISBN " << isbn << " nu a fost gasita.\n";
    }

    void afiseazaCarti() const {
        if (carti.empty()) {
            cout << "Nu exista carti in biblioteca.\n";
        } else {
            for (const auto& carte : carti) {
                cout << "Titlu: " << carte.titlu << ", Autor: " << carte.autor << ", ISBN: " << carte.ISBN << endl;
            }
        }
    }
};

void meniu() {
    cout << "===== Meniu Biblioteca =====\n";
    cout << "1. Adauga o carte\n";
    cout << "2. Sterge o carte\n";
    cout << "3. Afiseaza cartile\n";
    cout << "4. Iesi\n";
    cout << "Alege o optiune: ";
}

int main() {
    Biblioteca biblioteca; 
    int optiune;

    do {
        meniu();
        cin >> optiune;

        cin.ignore();

        switch (optiune) {
        case 1: {
            string titlu, autor;
            int isbn;

            cout << "\nIntrodu titlul cartii: ";
            getline(cin, titlu);

            cout << "Introdu autorul cartii: ";
            getline(cin, autor);

            cout << "Introdu ISBN-ul cartii: ";
            cin >> isbn;

            Carte carteNoua(titlu, autor, isbn);
            biblioteca.adaugaCarte(carteNoua); 
            break;
        }
        case 2: {
            int isbn;
            cout << "\nIntrodu ISBN-ul cartii de sters: ";
            cin >> isbn;

            biblioteca.stergeCarte(isbn); 
            break;
        }
        case 3: {
            cout << "\nCartile din biblioteca:\n";
            biblioteca.afiseazaCarti(); 
            break;
        }
        case 4: {
            cout << "Iesire din program.\n";
            break;
        }
        default:
            cout << "Optiune invalida! Te rog sa alegi din nou.\n";
        }

        cout << endl;

    } while (optiune != 4);

    return 0;
}
