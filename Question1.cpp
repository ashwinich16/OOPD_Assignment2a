#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cctype>
#include<bits/stdc++.h> 
using namespace std;

class Person {
protected:
    string name, telephone, email;
public:
    Person(string n, string t, string e) : name(n), telephone(t), email(e) {}
    
    virtual void fetchDetails() {
        cout << "\nTelephone: " << telephone << "\nEmail: " << email << "\n";
    }

    string getName() { return name; }
};

class AdminPerson : public Person {
private:
    string position, department, roomNo;
public:
    AdminPerson(string n, string p, string d, string r, string t, string e)
        : Person(n, t, e), position(p), department(d), roomNo(r) {}

    void fetchDetails(){
        Person::fetchDetails();
        cout<<"RoomNo:"<<roomNo;
    }
};

// Class to manage the administrative structure
class AdminDepartment {
    unordered_map<string, AdminPerson*> staff;
public:
    void addStaff(AdminPerson* p) {
        staff[p->getName()] = p;
    }

    void fetchPersonDetails(string name) {
        if (staff.find(name) != staff.end()) {
            staff[name]->fetchDetails();
        } else {
            cout << "Person not found in the administrative structure.\n";
        }
    }

    // Load data from CSV file
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
            // Assuming CSV has columns: Name, Position, Department, RoomNo, Telephone, Email
            transform(row[0].begin(), row[0].end(), row[0].begin(), ::tolower);
            row[3].erase(remove(row[3].begin(), row[3].end(), ' '), row[3].end());
            AdminPerson* person = new AdminPerson(row[0], row[1], row[2], row[3], row[4], row[5]);
            addStaff(person);
        }
    }
};
bool isStringOnly(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    AdminDepartment adminDept;
    
    // Load the data from the CSV
    adminDept.loadFromCSV("./IIITD_Administration.csv");

    // Fetch the details of a particular person (user can input the name)
    string nameToFetch;
    cout << "Enter the name of the person to fetch details: ";
    transform(nameToFetch.begin(), nameToFetch.end(), nameToFetch.begin(), ::tolower);
    cin>>nameToFetch;
    if (isStringOnly(nameToFetch)) 
        adminDept.fetchPersonDetails(nameToFetch);
    else   
        cout<<"Enter Name Corretly";
    return 0;
}
