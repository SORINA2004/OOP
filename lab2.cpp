#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>

// Custom Exceptions
class StudentNotFoundException : public std::exception {
    std::string message;
public:
    StudentNotFoundException(const std::string& studentID)
        : message("Student not found: " + studentID) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidFacultyOperation : public std::exception {
    std::string message;
public:
    InvalidFacultyOperation(const std::string& msg)
        : message("Invalid Faculty Operation: " + msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Base Abstract Class: Person
class Person {
protected:
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}
    virtual std::string getRole() const = 0;
    virtual ~Person() {}
};

// Derived Class: Student
class Student : public Person {
    std::string studentID;
    int credits;
    std::string faculty;
    bool graduated;
public:
    Student(const std::string& n, int a, const std::string& id, const std::string& f)
        : Person(n, a), studentID(id), faculty(f), credits(0), graduated(false) {}

    std::string getRole() const override {
        return "Student";
    }

    void graduate() {
        graduated = true;
    }

    bool isGraduated() const {
        return graduated;
    }

    std::string getStudentID() const {
        return studentID;
    }

    std::string getFaculty() const {
        return faculty;
    }

    // Operator Overloading
    Student& operator+=(int additionalCredits) {
        credits += additionalCredits;
        return *this;
    }

    friend Student operator+(const Student& s1, const Student& s2) {
        Student result = s1;
        result.credits += s2.credits;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.name << " (" << student.studentID << ") - Faculty: " 
           << student.faculty << ", Credits: " << student.credits;
        if (student.graduated) os << " [Graduated]";
        return os;
    }
};

// Logging System with Polymorphism
class OperationLogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~OperationLogger() {}
};

class FileLogger : public OperationLogger {
    std::ofstream file;
public:
    FileLogger(const std::string& filename) {
        file.open(filename, std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open log file");
        }
    }

    void log(const std::string& message) override {
        file << message << std::endl;
    }

    ~FileLogger() {
        file.close();
    }
};

class ConsoleLogger : public OperationLogger {
public:
    void log(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

// Class Faculty
class Faculty {
    std::string name;
    std::vector<Student> students;
public:
    Faculty(const std::string& n) : name(n) {}

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void graduateStudent(const std::string& studentID) {
        for (Student& s : students) {
            if (s.getStudentID() == studentID) {
                s.graduate();
                return;
            }
        }
        throw StudentNotFoundException(studentID);
    }

    void displayStudents(bool graduatedStatus) const {
        for (const Student& s : students) {
            if (s.isGraduated() == graduatedStatus) {
                std::cout << s << std::endl;
            }
        }
    }

    bool hasStudent(const std::string& studentID) const {
        for (const Student& s : students) {
            if (s.getStudentID() == studentID) return true;
        }
        return false;
    }

    const std::string& getName() const {
        return name;
    }
};

// SaveManager to handle persistence
class SaveManager {
public:
    static void saveData(const std::vector<Faculty>& faculties) {
        std::ofstream file("data.txt");
        for (const Faculty& faculty : faculties) {
            file << faculty.getName() << std::endl;
        }
        file.close();
    }

    static std::vector<Faculty> loadData() {
        std::vector<Faculty> faculties;
        std::ifstream file("data.txt");
        std::string facultyName;
        while (std::getline(file, facultyName)) {
            faculties.push_back(Faculty(facultyName));
        }
        file.close();
        return faculties;
    }
};

// Main System
class UniversitySystem {
    std::vector<Faculty> faculties;
    OperationLogger* logger;

public:
    UniversitySystem(OperationLogger* log) : logger(log) {}

    void createFaculty(const std::string& name) {
        faculties.push_back(Faculty(name));
        logger->log("Faculty created: " + name);
    }

    void addStudentToFaculty(const std::string& studentID, const std::string& name, int age, const std::string& facultyName) {
        for (Faculty& f : faculties) {
            if (f.getName() == facultyName) {
                f.addStudent(Student(name, age, studentID, facultyName));
                logger->log("Student added: " + studentID + " to faculty " + facultyName);
                return;
            }
        }
        throw InvalidFacultyOperation("Faculty not found: " + facultyName);
    }

    void graduateStudent(const std::string& studentID) {
        for (Faculty& f : faculties) {
            if (f.hasStudent(studentID)) {
                f.graduateStudent(studentID);
                logger->log("Student graduated: " + studentID);
                return;
            }
        }
        throw StudentNotFoundException(studentID);
    }

    void displayAllFaculties() const {
        for (const Faculty& f : faculties) {
            std::cout << "Faculty: " << f.getName() << std::endl;
        }
    }

    void displayFacultyStudents(const std::string& facultyName, bool graduatedStatus) const {
        for (const Faculty& f : faculties) {
            if (f.getName() == facultyName) {
                f.displayStudents(graduatedStatus);
                return;
            }
        }
        std::cout << "Faculty not found: " << facultyName << std::endl;
    }

    void saveState() {
        SaveManager::saveData(faculties);
        logger->log("System state saved.");
    }

    void loadState() {
        faculties = SaveManager::loadData();
        logger->log("System state loaded.");
    }

    void menu() {
        int choice;
        do {
            std::cout << "\nMenu: \n";
            std::cout << "1. Create Faculty\n";
            std::cout << "2. Add Student to Faculty\n";
            std::cout << "3. Graduate Student\n";
            std::cout << "4. Display Faculties\n";
            std::cout << "5. Display Faculty Students\n";
            std::cout << "6. Save & Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::string facultyName;
                    std::cout << "Enter faculty name: ";
                    std::cin >> facultyName;
                    createFaculty(facultyName);
                    break;
                }
                case 2: {
                    std::string studentID, name, facultyName;
                    int age;
                    std::cout << "Enter student ID: ";
                    std::cin >> studentID;
                    std::cout << "Enter student name: ";
                    std::cin >> name;
                    std::cout << "Enter student age: ";
                    std::cin >> age;
                    std::cout << "Enter faculty name: ";
                    std::cin >> facultyName;
                    addStudentToFaculty(studentID, name, age, facultyName);
                    break;
                }
                case 3: {
                    std::string studentID;
                    std::cout << "Enter student ID to graduate: ";
                    std::cin >> studentID;
                    graduateStudent(studentID);
                    break;
                }
                case 4: {
                    displayAllFaculties();
                    break;
                }
                case 5: {
                    std::string facultyName;
                    bool graduatedStatus;
                    std::cout << "Enter faculty name: ";
                    std::cin >> facultyName;
                    std::cout << "Display graduated students? (1 for Yes, 0 for No): ";
                    std::cin >> graduatedStatus;
                    displayFacultyStudents(facultyName, graduatedStatus);
                    break;
                }
                case 6: {
                    saveState();
                    break;
                }
                default: {
                    std::cout << "Invalid choice!\n";
                }
            }
        } while (choice != 6);
    }
};

int main() {
    ConsoleLogger logger;
    UniversitySystem system(&logger);

    system.loadState();
    system.menu();

    return 0;
}

