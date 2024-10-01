#ifndef USER_H
#define USER_H

#include<string>
#include<iostream>
#include <ctime>
#include "Book.h" 
#include "PublicationRank.h" 
#include "Journals.h"

using namespace std;


class User
{
private:
    string name;
    bool isTeacher;
    static const int MAX_BORROWED_BOOKS = 3; // Maximum number of books a user can borrow
    int borrowedCount;

public:
    Book *borrowedBooks[MAX_BORROWED_BOOKS];
    PublicationRank *borrowedbooks[MAX_BORROWED_BOOKS];
    Journals *borrowedJournals[MAX_BORROWED_BOOKS];
    time_t borrowedDates[MAX_BORROWED_BOOKS];
    User() ;
    User(const string &name, bool isTeacher) ;

    string getName();
    bool isTeacherUser();
    int getBorrowedCount();
    int getMaxBorrowedBooks() ;
    void incrementBorrowedCount();
    bool isBookBorrowed(Book *book) const;
    bool canBorrowMoreBooks() const;
    time_t getLastBorrowTime(const Book *book);
    void setLastBorrowTime(const Book *book, time_t borrowTime);
    time_t getLastBorrowPubTime(const PublicationRank *publicationRank) const;
    void setLastBorrowPubTime(const PublicationRank *publicationRank, time_t borrowTime);
};
#endif