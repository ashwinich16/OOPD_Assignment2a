#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <iostream>
#include "PublicationRank.h"
#include "Book.h"
#include "LibraryItem.h"
#include "User.h"

using namespace std;

class Library
{
private:
    LibraryItem *libraryItems[MAX_ITEMS];
    int itemCount;
    int nextBookId;
    int totalCopies;
    
    User students[100]; // Assuming a maximum of 100 students
    int studentCount = 0;
    
    User teachers[50]; // Assuming a maximum of 50 teachers
    int teacherCount = 0;

public:
    Library();
    int getStudentCount() const;
    int getTeacherCount() const;
    int getTotalUsers() const;
    int getTotalItems() const;
    void addItem(LibraryItem *item);
    void printAllItems() const;

    Book *getBookByID(int bookID) const;
    Book *getBookByIsbn(int bookIsbn) const;
    
    void searchBooksByAuthor(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const string &bookTitle, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const string &bookAuthor, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const string &bookAuthor, Journals *matchingBooks[], int &matchingCount);
    void registerUser(const string &name, bool isTeacher);
    void showAllRegisteredUsers();
    bool isEqualIgnoreCase(const string &str1, const string &str2);
    bool isEqualIgnore(const std::string &str1, const std::string &str2);
    void addBook(int isbn, const string &author, const string &title, int originalPublicationYear);
    bool borrowBook(const string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);
    bool borrowPublication(const string &userName, int publication);
    bool returnPub(PublicationRank *publicationRank);
    bool borrowJournal(const string &userName, int title);
    virtual ~Library();
};

#endif
