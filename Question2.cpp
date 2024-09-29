#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name, position, department;
public:
    Person(string n, string p, string d) : name(n), position(p), department(d) {}
    
    virtual void fetchDetails() {
        cout << "\nName: " << name 
             << "\nPosition: " << position 
             << "\nDepartment: " << department;
    }

    string getName() { return name; }
};

class FacultyMember : public Person {
private:
    string roomno, telephone;
public:
    FacultyMember(string n, string p, string d, string r, string t)
        : Person(n, p, d), roomno(r), telephone(t){}

    void fetchDetails()  {
        Person::fetchDetails();
        cout << "\nRoom No: " << roomno 
             << "\nTelephone: " << telephone<<"\n"; 
    }
};

class AcademicDepartment {
    vector<FacultyMember*> faculty;
public:
    void addFaculty(FacultyMember* f) {
        faculty.push_back(f);
    }

    void fetchAllFacultyDetails() {
        for (auto& member : faculty) {
            member->fetchDetails();
        }
    }
    void loadFromCSV(string filename) {
        ifstream file(filename);
        string line, word;
        vector<string> row;

        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        while (getline(file, line)) {
            row.clear();
            stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }

            transform(row[0].begin(), row[0].end(), row[0].begin(), ::tolower); 
            row[3].erase(remove(row[3].begin(), row[3].end(), ' '), row[3].end()); 
            FacultyMember* facultyMember = new FacultyMember(row[0], row[1], row[2], row[3], row[4]);
            addFaculty(facultyMember);
        }
    }
};

int main() {
    AcademicDepartment academicDept;
    
    academicDept.loadFromCSV("IIITD_Academic.csv");
    academicDept.fetchAllFacultyDetails();

    return 0;
}
