#include<iostream>
#include "Journals.h"

using namespace std;

// Implement the constructor and methods declared in Journals.h

Journals::Journals(int ID, const string &title)
    : ID(ID), title(title)
{
}

int Journals::getID()
{
    return ID;
}

string Journals::getTitle() const
{
    return title;
}

void Journals::printDetails() const
{
    cout << "ID: " << ID << "\nJournal Title: " << title << "\n";
}
