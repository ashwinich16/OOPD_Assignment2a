#ifndef PUBLICATIONRANK_H
#define PUBLICATIONRANK_H

#include <string>
#include "LibraryItem.h"

class PublicationRank : public LibraryItem
{
private:
    int ID;
    std::string publication;
    int rank;
    double totalPaid;
    bool borrowed;

public:
    // Constructor
    PublicationRank(int ID, const std::string &publication, int rank, double totalPaid);

    // Getter methods
    int getID() const;
    std::string getPublication() const;
    int getRank() const; // Corrected function name to getRank()
    double getTotalPaid() const;
    bool isBorrowed() const;

    // Setter methods
    void setBorrowed(bool status);

    // Overriding the printDetails method from LibraryItem
    void printDetails() const override;
};

#endif
