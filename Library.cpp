#include <string>
#include <iostream>
#include "Library.h"

using namespace std;

// Implement Library's methods here
Library::Library() : itemCount(0), studentCount(0), teacherCount(0), nextBookId(100), totalCopies(1) {}

int Library::getStudentCount() const {
    return studentCount;
}

int Library::getTeacherCount() const {
    return teacherCount;
}

int Library::getTotalUsers() const {
    return studentCount + teacherCount;
}

int Library::getTotalItems() const {
    return itemCount;
}

void Library::addItem(LibraryItem *item) {
    if (itemCount < MAX_ITEMS) {
        libraryItems[itemCount] = item;
        itemCount++;
    } else {
        cout << "Library is full. Cannot add more items." << endl;
    }
}

// Implement other methods similarly...

// Destructor
Library::~Library() {
    // Clean up if necessary
}
