all		: test  
.PHONY	: all   

test : main.o 
	g++ -std=c++11  -o test main.o -L/usr/local/lib -lgumbo
main.o : main.cpp 
	g++  -c main.cpp  
clean :   
	rm testt main.o 
