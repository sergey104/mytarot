all		: mytarot  
.PHONY	: all   

mytarot : main.o 
	g++ -std=c++11  -o mytarot main.o `mysql_config --libs`
main.o : main.cpp my_global.h general.h  pp.h direct.h
	g++  -c main.cpp  
clean :   
	rm mytarot main.o 
