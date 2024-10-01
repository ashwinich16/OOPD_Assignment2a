#include<string>
#include<iostream>
#include"PublicationRank.h"
#include"Book.h"
#include"LibraryItem.h"
#include"User.h"

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
    Library() : itemCount(0), studentCount(0), teacherCount(0)
    {       
        nextBookId = 100;
        totalCopies = 1;
    }
    // Library() : libraryItems{}, itemCount(0), students{}, studentCount(0), teachers{}, teacherCount(0), nextBookId(100) {}

    int getStudentCount() const
    {
        return studentCount;
    }
    int getTeacherCount() const
    {
        return teacherCount;
    }
    int getTotalUsers() const
    {
        return studentCount + teacherCount;
    }

    int getTotalItems() const
    {
        return itemCount;
    }

    void addItem(LibraryItem *item)
    {
        if (itemCount < MAX_ITEMS)
        {
                         libraryItems[itemCount] = item;
            itemCount++;
        }
        else
        {
            cout << "Library is full. Cannot add more items." << endl;
        }
    }

    void printAllItems() const
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

    Book *getBookByID(int bookID) const
    {
        for (int i = 0; i < itemCount; i++)
        {
            Book *book = dynamic_cast<Book *>(libraryItems[i]);
            if (book && book->getBookID() == bookID)
            {
                return book; // Found the book with the specified ID
            }
        }
        return nullptr; // Book with the specified ID not found
    }
    Book *getBookByIsbn(int bookIsbn) const
    {
        for (int i = 0; i < itemCount; i++)
        {
            Book *book = dynamic_cast<Book *>(libraryItems[i]);
            if (book && book->getISBN() == bookIsbn)
            {
                return book; // Found the book with the specified Isbn
            }
        }
return nullptr; // Book with the specified Isbn not found
    }
    void searchBooksByAuthor(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const string &bookAuthor, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const string &bookAuthor, Journals *matchingBooks[], int &matchingCount);

    void registerUser(const string &name, bool isTeacher);

    void showAllRegisteredUsers();

    bool isEqualIgnoreCase(const string &str1, const string &str2);
    bool isEqualIgnore(const std::string &str1, const std::string &str2);

    // Function to add a new book to the library
    void addBook(int isbn, const string &author, const string &title, int originalPublicationYear);

    bool borrowBook(const string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);
    bool borrowPublication(const string &userName, int publication);
    bool returnPub(PublicationRank *publicationRank);
    bool borrowJournal(const string &userName, int title);

    virtual ~Library() {} // Virtual destructor
};

