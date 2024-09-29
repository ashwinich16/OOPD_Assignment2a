test : 
# Question 2
	g++ -c Question2.cpp
	g++ -g -o debug2_1 Question2.o

# Question 2 optimized version
	g++ -c Question2.cpp
	g++ -g -o debug2_2 Question2.o
	g++ -O3 -o optimize2_2 Question2.o

# Question 3
	g++ -c Question3.cpp
	g++ -g -o debug3_1 Question3.o
	

# Question 3 Optimized version
	g++ -c Question3.cpp
	g++ -g -o debug3_2 Question3.o
	g++ -O3 -o optimize3_2 Question3.o

