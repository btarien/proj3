CPU.out : decoder.o main.o  reader.o registers.o 
	g++ -Wall -ansi -o CPU.out decoder.o  main.o reader.o registers.o  

decoder.o: decoder.cpp decoder.h registers.h reader.h instruction.h main.h 
	g++ -Wall -ansi -c decoder.cpp

main.o: main.cpp registers.h decoder.h  reader.h instruction.h main.h 
	g++ -Wall -ansi -c main.cpp

reader.o: reader.cpp reader.h registers.h main.h 
	g++ -Wall -ansi -c reader.cpp

registers.o: registers.cpp registers.h main.h 
	g++ -Wall -ansi -c registers.cpp


clean:
	rm -f CPU.out decoder.o  main.o  reader.o registers.o  
