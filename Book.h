#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "LibraryItem.h"

class Book : public LibraryItem
{
private:
    int ID;
    int book_id;
    int isbn;
    std::string title;
    std::string authors;
    int original_publication_year;
    bool borrowed;

public:
    // Constructors
    Book();
    Book(int ID, int book_id, int isbn, const std::string &title, const std::string &authors, int original_publication_year);

    // Getter and Setter functions
    int getID() const;
    void setID(int id);

    int getBookID() const;
    void setBookID(int bookid);

    int getISBN() const;
    void setISBN(int Isbn);

    std::string getTitle() const;
    void setTitle(const std::string &newTitle);

    std::string getAuthors() const;
    void setAuthors(const std::string &newAuthor);

    int getPublicationYear() const;
    void setPublicationYear(int year);

    bool isBorrowed() const;
    void setBorrowed(bool status);

    // Override the pure virtual function from LibraryItem
    void printDetails() const override;
};

#endif
