#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class representing a person in the department
class Person {
protected:
    string position;
public:
    Person(string p) : position(p) {}

    virtual bool resolveComplaint() {
        cout << position<< endl;
        return false;
    }

    string getPosition() {
        return position;
    }
};

// Classes for Administrative Department
class JuniorAdministrativeOfficer : public Person {
public:
    JuniorAdministrativeOfficer() : Person("Junior Administrative Officer") {}
};

class AssistantAdministrativeOfficer : public Person {
public:
    AssistantAdministrativeOfficer() : Person("Assistant Administrative Officer") {}
};

class DeputyAdministrativeOfficer : public Person {
public:
    DeputyAdministrativeOfficer() : Person("Deputy Administrative Officer") {}
};

class AdministrativeOfficer : public Person {
public:
    AdministrativeOfficer() : Person("Administrative Officer") {}
};

class Registrar : public Person {
public:
    Registrar() : Person("Registrar") {}
};

class SRegistrar : public Person {
public:
    SRegistrar() : Person("Registrar") {}
    bool resolveComplaint() override {
        cout << "Registrar has resolved the complaint.\n";
        return true;
    }
};

class Dean : public Person {
public:
    Dean() : Person("Dean") {}

    bool resolveComplaint() override {
        cout << "Dean has resolved the complaint.\n";
        return true;
    }
};

// Classes for Academic Department
class Professor : public Person {
public:
    Professor() : Person("Professor/Assistant Professor") {}
};


class HeadOfDepartment : public Person {
public:
    HeadOfDepartment() : Person("Head of Department") {}
};

class HeadAdministrativeOfficer : public Person {
public:
    HeadAdministrativeOfficer() : Person("Administrative officer of Academic Department") {}

    bool resolveComplaint() override {
        cout << "Administrative officer has resolved the complaint.\n";
        return true;
    }
};

// Class for handling complaints and escalation
class EscalationMatrix {
    vector<Person*> hierarchy;
public:
    void addPerson(Person* p) {
        hierarchy.push_back(p);
    }

    void escalateComplaint() {
        for (Person* person : hierarchy) {
            if (person->resolveComplaint()) {
                cout << "Complaint resolved by " << person->getPosition() << ".\n";
                return;
            }
        }
        cout << "Complaint could not be resolved at any level.\n";
    }
};

// Function to set up administrative department escalation
void setupAdministrativeEscalation(string department, EscalationMatrix& matrix) {
    if (department == "IRD") {
        cout << "IRD Department Escalation Path: \n";
        matrix.addPerson(new JuniorAdministrativeOfficer());
        matrix.addPerson(new AssistantAdministrativeOfficer());
        matrix.addPerson(new AdministrativeOfficer());
        matrix.addPerson(new Registrar());
        matrix.addPerson(new Dean());
    } else if (department == "Academics") {
        cout << "Academics Department Escalation Path: \n";
        matrix.addPerson(new JuniorAdministrativeOfficer());
        matrix.addPerson(new AssistantAdministrativeOfficer());
        matrix.addPerson(new DeputyAdministrativeOfficer());
        matrix.addPerson(new AdministrativeOfficer());
        matrix.addPerson(new Registrar());
        matrix.addPerson(new Dean());
    } else if (department == "Student Affairs") {
        cout << "Student Affairs Department Escalation Path: \n";
        matrix.addPerson(new JuniorAdministrativeOfficer());
        matrix.addPerson(new AdministrativeOfficer());
        matrix.addPerson(new Registrar());
        matrix.addPerson(new Dean());
    } else if (department == "Store and Purchase") {
        cout << "Store and Purchase Department Escalation Path: \n";
        matrix.addPerson(new AssistantAdministrativeOfficer());
        matrix.addPerson(new AdministrativeOfficer());
        matrix.addPerson(new SRegistrar());
    } else if (department == "Library") {
        cout << "Library Department Escalation Path: \n";
        matrix.addPerson(new AssistantAdministrativeOfficer());
        matrix.addPerson(new AdministrativeOfficer());
        matrix.addPerson(new SRegistrar());
    }
}

// Function to set up academic department escalation
void setupAcademicEscalation(EscalationMatrix& matrix) {
    cout <<" Departments Escalation Path: \n";
    matrix.addPerson(new Professor());
    matrix.addPerson(new HeadOfDepartment());
    matrix.addPerson(new HeadAdministrativeOfficer());
}

int main() {
    EscalationMatrix matrix;

    //IRD
    cout << "Setting up escalation for IRD Department\n";
    setupAdministrativeEscalation("IRD", matrix);
    matrix.escalateComplaint();

    cout << "\n";

    //Academics
    EscalationMatrix adminMatrix;
    cout << "Setting up escalation for Academics Department\n";
    setupAdministrativeEscalation("Academics", adminMatrix);
    adminMatrix.escalateComplaint();

    cout << "\n";

    //Student Affairs
    EscalationMatrix studentAffairsMatrix;
    cout << "Setting up escalation for Student Affairs Department\n";
    setupAdministrativeEscalation("Student Affairs", studentAffairsMatrix);
    studentAffairsMatrix.escalateComplaint();

    cout << "\n";
    //Store And Purchase
    EscalationMatrix storematrix;
    cout << "Setting up escalation for Store and Purchase Department\n";
    setupAdministrativeEscalation("Student Affairs", storematrix);
    storematrix.escalateComplaint();
    cout << "\n";

    //Library
    EscalationMatrix librarymatrix;
    cout << "Setting up escalation for Library Department\n";
    setupAdministrativeEscalation("Student Affairs", librarymatrix);
    librarymatrix.escalateComplaint();
    cout << "\n";

    //Academic departments
    EscalationMatrix academicMatrix;
    cout << "Setting up escalation for All Academic Departments\n";
    setupAcademicEscalation(academicMatrix);
    academicMatrix.escalateComplaint();

    return 0;
}
