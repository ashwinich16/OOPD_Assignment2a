test : 
# Question 1
	g++ -c Question1.cpp
	g++ -g -o debug1_1 Question1.o

# Question 1 Optimized version
	g++ -c Question1.cpp
	g++ -g -o debug1_2 Question1.o
	g++ -O3 -o optimize1_2 Question1.o

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

