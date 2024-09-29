test : 
# Question 2
	g++ -c Question2.cpp
	g++ -g -o debug1 Question2.o

# Question 2 optimized version
	g++ -c Question2.cpp
	g++ -g -o debug2 Question2.o
	g++ -O3 -o optimize2 Question2.o
