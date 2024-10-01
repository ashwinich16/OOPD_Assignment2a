#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

extern int ID;  
const int MAX_ITEMS = 500; 

class LibraryItem
{
public:
    virtual void printDetails() const = 0;
    virtual ~LibraryItem() {}
};

#endif



