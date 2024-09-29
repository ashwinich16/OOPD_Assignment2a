test : 
# Question 1
	g++ -c Question1.cpp
	g++ -g -o debug1 Question1.o
	

# Question 1 Optimized version
	g++ -c Question1.cpp
	g++ -g -o debug2 Question1.o
	g++ -O3 -o optimize1 Question1.o

