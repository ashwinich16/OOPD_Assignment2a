#include <iostream>
#include "PublicationRank.h"

using namespace std;

// Constructor implementation
PublicationRank::PublicationRank(int ID, const std::string &publication, int rank, double totalPaid)
    : ID(ID), publication(publication), rank(rank), totalPaid(totalPaid), borrowed(false) // Initialize borrowed to false
{}

// Getter methods implementation
int PublicationRank::getID() const {
    return ID;
}

std::string PublicationRank::getPublication() const {
    return publication;
}

int PublicationRank::getRank() const {
    return rank;
}

double PublicationRank::getTotalPaid() const {
    return totalPaid;
}

bool PublicationRank::isBorrowed() const {
    return borrowed;
}

void PublicationRank::setBorrowed(bool status) {
    borrowed = status;
}

// Implementation of printDetails
void PublicationRank::printDetails() const {
    cout << "ID: " << ID
         << "\nPublication Name: " << publication
         << "\nRank: " << rank
         << "\nTotal Paid: " << totalPaid
         << "\nBorrowed: " << (borrowed ? "Yes" : "No") // Indicate if it's borrowed
         << "\n";
}
