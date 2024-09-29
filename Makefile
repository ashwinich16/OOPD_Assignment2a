test : 
# Question 3
	g++ -c Question3.cpp
	g++ -g -o debug3_1 Question3.o
	

# Question 3 Optimized version
	g++ -c Question3.cpp
	g++ -g -o debug3_2 Question3.o
	g++ -O3 -o optimize3_2 Question3.o

