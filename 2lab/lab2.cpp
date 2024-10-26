#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  // pentru funcția find
using namespace std;

// Verifica daca fisierul este gol
bool check_if_file_is_empty(const string& file_path) {
    ifstream file(file_path);
    return file.peek() == ifstream::traits_type::eof();
}

// Functie pentru a imparti un string pe baza unui delimitator
vector<string> split(const string& str, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0, end = str.find(delimiter);
    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

// Clasa Student
class Student {
public:
    string id;
    string name;
    string surname;
    string group;
    string faculty;
    string status;

    Student(string id, string name, string surname, string group, string faculty, string status)
        : id(id), name(name), surname(surname), group(group), faculty(faculty), status(status) {}

    string toString() const {
        return id + ", " + name + ", " + surname + ", " + group + ", " + faculty + ", " + status;
    }
};

// Clasa Catalog
class Catalog {
private:
    vector<Student> catalog;
    vector<Student> graduated_students;
    int session;

public:
    Catalog() : session(1) {}

    string check_if_faculty_exists(const string& faculty, const vector<string>& faculties) {
        string f = faculty;
        while (true) {
            if (find(faculties.begin(), faculties.end(), f) != faculties.end()) {
                return f;
            } else {
                cout << "Aceasta facultate nu exista, te rog sa alegi alta: ";
                cin >> f;
            }
        }
    }

    void load_students() {
        if (!check_if_file_is_empty("catalog.txt")) {
            ifstream file("catalog.txt");
            string line;
            while (getline(file, line)) {
                vector<string> data = split(line, ", ");
                if (data.size() == 6) {
                    Student student(data[0], data[1], data[2], data[3], data[4], data[5]);
                    catalog.push_back(student);
                }
            }
        }
    }

    void load_graduated_students() {
        if (!check_if_file_is_empty("graduated.txt")) {
            ifstream file("graduated.txt");
            string line;
            while (getline(file, line)) {
                vector<string> data = split(line, ", ");
                if (data.size() == 6) {
                    Student student(data[0], data[1], data[2], data[3], data[4], data[5]);
                    graduated_students.push_back(student);
                }
            }
        }
    }

    void enroll(const vector<string>& faculties) {
        string id, name, surname, group, faculty;
        cout << "ID student: ";
        cin >> id;
        cin.ignore();

        for (const auto& student : catalog) {
            if (student.id == id) {
                cout << "Un student cu acest ID exista deja. Te rog sa incerci alt ID.\n";
                return;
            }
        }

        cout << "Nume student: ";
        getline(cin, name);
        cout << "Prenume student: ";
        getline(cin, surname);
        cout << "Grupa studentului: ";
        cin >> group;
        cout << "Facultatea: ";
        cin >> faculty;

        faculty = check_if_faculty_exists(faculty, faculties);
        string status = "neabsolvent";

        Student new_student(id, name, surname, group, faculty, status);
        catalog.push_back(new_student);

        ofstream file("catalog.txt", ios::app);
        file << new_student.toString() + "\n";
    }

    void display_students() const {
        if (catalog.empty()) {
            cout << "Nu exista studenti inscrisi inca.\n";
        } else {
            for (size_t i = 0; i < catalog.size(); ++i) {
                cout << i + 1 << ") " << catalog[i].toString() << endl;
            }
        }
    }

    void graduate_student() {
        string id;
        cout << "Introdu ID-ul studentului: ";
        cin >> id;

        for (auto it = catalog.begin(); it != catalog.end(); ++it) {
            if (it->id == id) {
                it->status = "absolvent";
                graduated_students.push_back(*it);
                ofstream file("graduated.txt", ios::app);
                file << it->toString() + "\n";
                catalog.erase(it);
                update_catalog_file();
                cout << "Studentul a absolvit.\n";
                return;
            }
        }
        cout << "Studentul nu a fost gasit.\n";
    }

    void update_catalog_file() {
        ofstream file("catalog.txt");
        for (const auto& student : catalog) {
            file << student.toString() + "\n";
        }
    }

    void display_graduated_students() const {
        if (graduated_students.empty()) {
            cout << "Nu exista absolventi inca.\n";
        } else {
            for (size_t i = 0; i < graduated_students.size(); ++i) {
                cout << i + 1 << ") " << graduated_students[i].toString() << endl;
            }
        }
    }

    void check_student_faculty() {
        string id, faculty;
        cout << "Introdu ID-ul studentului: ";
        cin >> id;
        cout << "Introdu facultatea: ";
        cin >> faculty;

        for (const auto& student : catalog) {
            if (student.id == id && student.faculty == faculty) {
                cout << "Studentul " << student.name << " " << student.surname << " apartine facultatii " << faculty << ".\n";
                return;
            }
        }
        cout << "Studentul nu apartine acestei facultati.\n";
    }
};

// Functii pentru gestionarea facultatilor
void view_faculties(const vector<string>& faculties) {
    if (faculties.empty()) {
        cout << "Nu exista facultati disponibile.\n";
    } else {
        cout << "Facultati disponibile:\n";
        for (const auto& faculty : faculties) {
            cout << faculty << endl;
        }
    }
}

void add_new_faculty(vector<string>& faculties) {
    string new_faculty;
    cout << "Introdu numele noii facultati: ";
    cin >> new_faculty;
    faculties.push_back(new_faculty);

    ofstream file("faculties.txt", ios::app);
    file << new_faculty + "\n";
    cout << "Facultatea a fost adaugata.\n";
}

void remove_faculty(vector<string>& faculties) {
    string faculty_to_remove;
    cout << "Introdu numele facultatii de eliminat: ";
    cin >> faculty_to_remove;

    auto it = find(faculties.begin(), faculties.end(), faculty_to_remove);
    if (it != faculties.end()) {
        faculties.erase(it);
        ofstream file("faculties.txt");
        for (const auto& faculty : faculties) {
            file << faculty + "\n";
        }
        cout << "Facultatea a fost eliminata.\n";
    } else {
        cout << "Facultatea nu exista.\n";
    }
}

bool check_if_account_exists() {
    ifstream file("log.txt");
    return file.peek() != ifstream::traits_type::eof();
}

void create_account() {
    string login, password;
    cout << "Login: ";
    cin >> login;
    cout << "Parola: ";
    cin >> password;

    ofstream file("log.txt", ios::app);
    file << login + "\n" + password + "\n";
}

bool login_system() {
    string login, password, stored_login, stored_password;
    cout << "Login: ";
    cin >> login;
    cout << "Parola: ";
    cin >> password;

    ifstream file("log.txt");
    getline(file, stored_login);
    getline(file, stored_password);

    return login == stored_login && password == stored_password;
}

int main() {
    Catalog catalog;
    vector<string> faculties;

    if (!check_if_file_is_empty("faculties.txt")) {
        ifstream file("faculties.txt");
        string line;
        while (getline(file, line)) {
            faculties.push_back(line);
        }
    }

    if (check_if_account_exists()) {
        if (!login_system()) {
            cout << "Login esuat.\n";
            return 0;
        }
    } else {
        create_account();
    }

    catalog.load_students();
    catalog.load_graduated_students();

    while (true) {
        cout << "\nMeniu:\n1. Inscriere student\n2. Afisare studenti\n3. Absolvire student\n4. Afisare absolventi\n5. Verificare facultate student\n6. Afisare facultati\n7. Adaugare facultate\n8. Stergere facultate\n9. Iesire\n";
        int option;
        cin >> option;

        switch (option) {
            case 1: catalog.enroll(faculties); break;
            case 2: catalog.display_students(); break;
            case 3: catalog.graduate_student(); break;
            case 4: catalog.display_graduated_students(); break;
            case 5: catalog.check_student_faculty(); break;
            case 6: view_faculties(faculties); break;
            case 7: add_new_faculty(faculties); break;
            case 8: remove_faculty(faculties); break;
            case 9: return 0;
            default: cout << "Optiune invalida.\n"; break;
        }
    }
}
