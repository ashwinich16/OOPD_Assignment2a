# Makefile for compiling the program

# Default target
all: my_program

# Linking all object files into the final executable
my_program: main.o Library.o LibraryItem.o PublicationRank.o User.o Book.o classfunctions.o functions.o Journals.o
	g++ main.o Library.o LibraryItem.o PublicationRank.o User.o Book.o classfunctions.o functions.o Journals.o -o my_program

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

classfunctions.o: classfunctions.cpp
	g++ -c classfunctions.cpp


# Clean target
clean:
	rm -f *.o my_program
