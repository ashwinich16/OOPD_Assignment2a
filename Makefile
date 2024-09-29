test : 
# Question 3
	g++ -c Question3.cpp
	g++ -g -o debug1 Question3.o
	

# Question 3 Optimized version
	g++ -c Question3.cpp
	g++ -g -o debug2 Question3.o
	g++ -O3 -o optimize2 Question3.o

