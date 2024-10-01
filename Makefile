# Makefile for compiling the program

# Default target
all: main.o Library.o LibraryItem.o PublicationRank.o User.o Book.o functions.o Journals.o
	g++ main.o Library.o LibraryItem.o PublicationRank.o User.o Book.o functions.o Journals.o -o my_program -pthread

# Object file targets
main.o: main.cpp
	g++ -c main.cpp

Library.o: Library.cpp
	g++ -c Library.cpp

LibraryItem.o: LibraryItem.cpp
	g++ -c LibraryItem.cpp

PublicationRank.o: PublicationRank.cpp
	g++ -c PublicationRank.cpp

User.o: User.cpp
	g++ -c User.cpp

Book.o: Book.cpp
	g++ -c Book.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

Journals.o: Journals.cpp
	g++ -c Journals.cpp

# Clean target
clean:
	rm -f *.o my_program
