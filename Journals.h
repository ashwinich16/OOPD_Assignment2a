#ifndef JOURNALS_H
#define JOURNALS_H

#include<iostream>
#include "LibraryItem.h"

using namespace std;

class Journals : public LibraryItem
{
private:
    int ID;
    string title;

public:
    // Constructor
    Journals(int ID, const string &title);
    int getID();
    string getTitle() const;
    void printDetails() const override;
};

#endif
