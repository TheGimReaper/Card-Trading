all: program1

run: program1
	./program1 

program1: Program1.cpp Program1.h
	g++ -std=c++11 Program1.cpp -o program1

clean: 
	rm -vf program1 output.txt
