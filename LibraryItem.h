#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

extern int ID;  // Declare ID to be used in other files
const int MAX_ITEMS = 500; // Define constant for maximum items

class LibraryItem
{
public:
    virtual void printDetails() const = 0; // Pure virtual function
    virtual ~LibraryItem() {} // Virtual destructor
};

#endif