#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Student {
public:
    string firstName, lastName, email, dob;
    bool graduated;

    Student(string fName = "", string lName = "", string email = "", string dob = "") 
        : firstName(fName), lastName(lName), email(email), dob(dob), graduated(false) {}
};

class Faculty {
public:
    string name, abbreviation, field;
    vector<Student*> students;
    vector<Student*> graduatedStudents;

    Faculty(string name = "", string abbreviation = "", string field = "") 
        : name(name), abbreviation(abbreviation), field(field) {}

    void addStudent(Student* student) {
        students.push_back(student);
    }

    void graduateStudent(string email) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->email == email) {
                (*it)->graduated = true;
                graduatedStudents.push_back(*it);
                students.erase(it);
                return;
            }
        }
    }

    void displayStudents() {
        for (Student* s : students) {
            cout << s->firstName << " " << s->lastName << " - " << s->email << " - " << s->dob << endl;
        }
    }

    void displayGraduatedStudents() {
        for (Student* s : graduatedStudents) {
            cout << s->firstName << " " << s->lastName << " - " << s->email << " - " << s->dob << endl;
        }
    }
};

class University {
public:
    unordered_map<string, Faculty*> faculties;

    void createFaculty(string name, string abbreviation, string field) {
        faculties[abbreviation] = new Faculty(name, abbreviation, field);
        cout << "Faculty " << name << " created successfully." << endl;
    }

    void addStudentToFaculty(string abbreviation, string fName, string lName, string email, string dob) {
        if (faculties.find(abbreviation) != faculties.end()) {
            Student* student = new Student(fName, lName, email, dob);
            faculties[abbreviation]->addStudent(student);
            cout << "Student added successfully to " << abbreviation << "." << endl;
        } else {
            cout << "Faculty not found!" << endl;
        }
    }

    void graduateStudent(string abbreviation, string email) {
        if (faculties.find(abbreviation) != faculties.end()) {
            faculties[abbreviation]->graduateStudent(email);
            cout << "Student graduated successfully." << endl;
        } else {
            cout << "Faculty not found!" << endl;
        }
    }

    void displayFaculties() {
        for (auto& f : faculties) {
            cout << f.second->name << " (" << f.first << ")" << endl;
        }
    }

    void displayStudentsInFaculty(string abbreviation) {
        if (faculties.find(abbreviation) != faculties.end()) {
            faculties[abbreviation]->displayStudents();
        } else {
            cout << "Faculty not found!" << endl;
        }
    }

    void displayGraduatedStudentsInFaculty(string abbreviation) {
        if (faculties.find(abbreviation) != faculties.end()) {
            faculties[abbreviation]->displayGraduatedStudents();
        } else {
            cout << "Faculty not found!" << endl;
        }
    }

    void checkStudentBelongsToFaculty(string abbreviation, string email) {
        if (faculties.find(abbreviation) != faculties.end()) {
            for (Student* s : faculties[abbreviation]->students) {
                if (s->email == email) {
                    cout << "Student belongs to " << abbreviation << endl;
                    return;
                }
            }
            cout << "Student does not belong to " << abbreviation << endl;
        } else {
            cout << "Faculty not found!" << endl;
        }
    }
};

void showMainMenu() {
    cout << "\nWelcome to TUM's student management system!" << endl;
    cout << "What do you want to do?" << endl;
    cout << "g - General operations" << endl;
    cout << "f - Faculty operations" << endl;
    cout << "s - Student operations" << endl;
    cout << "q - Quit Program" << endl;
    cout << "your input> ";
}

void showGeneralOperationsMenu() {
    cout << "\nGeneral operations" << endl;
    cout << "What do you want to do?" << endl;
    cout << "nf/<faculty name>/<faculty abbreviation>/<field> - create faculty" << endl;
    cout << "df - display faculties" << endl;
    cout << "df/<field> - display all faculties of a field" << endl;
    cout << "b - Back" << endl;
    cout << "q - Quit Program" << endl;
    cout << "your input> ";
}

void showFacultyOperationsMenu() {
    cout << "\nFaculty operations" << endl;
    cout << "What do you want to do?" << endl;
    cout << "ns/<faculty abbreviation>/<first name>/<last name>/<email>/<day>/<month>/<year> - create student" << endl;
    cout << "gs/<email> - graduate student" << endl;
    cout << "ds/<faculty abbreviation> - display enrolled students" << endl;
    cout << "dg/<faculty abbreviation> - display graduated students" << endl;
    cout << "bf/<faculty abbreviation>/<email> - check if student belongs to faculty" << endl;
    cout << "b - Back" << endl;
    cout << "q - Quit Program" << endl;
    cout << "your input> ";
}

int main() {
    University university;
    string input;

    while (true) {
        showMainMenu();
        cin >> input;

        if (input == "q") {
            break;
        } else if (input == "g") {
            while (true) {
                showGeneralOperationsMenu();
                cin >> input;
                
                if (input == "b") break;
                else if (input == "q") return 0;
                else if (input.substr(0, 2) == "nf") {
                    string facultyName, abbreviation, field;
                    sscanf(input.c_str(), "nf/%[^/]/%[^/]/%s", &facultyName[0], &abbreviation[0], &field[0]);
                    university.createFaculty(facultyName, abbreviation, field);
                } else if (input == "df") {
                    university.displayFaculties();
                }
            }
        } else if (input == "f") {
            while (true) {
                showFacultyOperationsMenu();
                cin >> input;

                if (input == "b") break;
                else if (input == "q") return 0;
                else if (input.substr(0, 2) == "ns") {
                    string abbreviation, firstName, lastName, email, dob;
                    sscanf(input.c_str(), "ns/%[^/]/%[^/]/%[^/]/%[^/]/%s", &abbreviation[0], &firstName[0], &lastName[0], &email[0], &dob[0]);
                    university.addStudentToFaculty(abbreviation, firstName, lastName, email, dob);
                } else if (input.substr(0, 2) == "gs") {
                    string abbreviation, email;
                    sscanf(input.c_str(), "gs/%[^/]", &email[0]);
                    university.graduateStudent(abbreviation, email);
                } else if (input.substr(0, 2) == "ds") {
                    string abbreviation;
                    sscanf(input.c_str(), "ds/%s", &abbreviation[0]);
                    university.displayStudentsInFaculty(abbreviation);
                }
            }
        }
    }

    return 0;
}
