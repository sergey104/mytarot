mytarot : main.o 
	g++ -std=c++11  -o mytarot main.o `mysql_config --libs`
main.o : main.cpp my_global.h   
	g++  -c main.cpp  
clean :   
	rm mytarot main.o 
