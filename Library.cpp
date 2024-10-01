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
void Library::printAllItems() const
    {
        for (int i = 0; i < itemCount; ++i)
        {
            if (libraryItems[i])
            {
                libraryItems[i]->printDetails();
                cout << "------------------------\n";
            }
        }
    }
Book* Library::getBookByID(int bookID) const {
    for (int i = 0; i < itemCount; i++) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book && book->getBookID() == bookID) {
            return book; // Found the book with the specified ID
        }
    }
    return nullptr; // Book with the specified ID not found
}

Book* Library::getBookByIsbn(int bookIsbn) const {
    for (int i = 0; i < itemCount; i++) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book && book->getISBN() == bookIsbn) {
            return book; // Found the book with the specified ISBN
        }
    }
    return nullptr; // Book with the specified ISBN not found
}
void Library::registerUser(const string &name, bool isTeacher) {
    if (isTeacher) {
        teachers[teacherCount++] = User(name, true);
        cout << "Registered as a Teacher." << endl;
    } else {
        students[studentCount++] = User(name, false);
        cout << "Registered as a Student." << endl;
    }
    cout << "-------------------------" << endl;
}

void Library::showAllRegisteredUsers() {
    cout << "Registered Students:" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << students[i].getName() << endl;
    }

    cout << "Registered Teachers:" << endl;
    for (int i = 0; i < teacherCount; ++i) {
        cout << teachers[i].getName() << endl;
    }
    cout << "-------------------------" << endl;
}

bool Library::isEqualIgnoreCase(const string &str1, const string &str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    for (size_t i = 0; i < str1.size(); ++i) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}

bool Library::isEqualIgnore(const std::string &str1, const std::string &str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    for (size_t i = 0; i < str1.length(); ++i) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}

// Function to add a new book to the library
void Library::addBook(int isbn, const string &author, const string &title, int originalPublicationYear) {
    if (itemCount >= MAX_ITEMS) {
        cout << "The library is full. Cannot add more books." << endl;
        return;
    }

    // Create a new Book object with the next available book ID
    Book *newBook = new Book();
    newBook->setID(ID++); // Assuming ID is defined and managed elsewhere
    newBook->setBookID(nextBookId++);
    newBook->setISBN(isbn);
    newBook->setAuthors(author);
    newBook->setTitle(title);
    newBook->setPublicationYear(originalPublicationYear);

    // Add the new book to the library
    addItem(newBook);

    cout << "Added book with ID " << newBook->getBookID() << " to the library." << endl;
}

// Destructor
Library::~Library() {
    // Clean up if necessary
}
