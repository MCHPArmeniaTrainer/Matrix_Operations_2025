obj/Matrix.o : inc/Matrix.h src/Matrix.cpp
	g++ -Iinc -c src/Matrix.cpp -o obj/Matrix.o

obj/MathOperation.o : inc/MathOperation.h src/MathOperation.cpp
	g++ -Iinc -c src/MathOperation.cpp -o obj/MathOperation.o

obj/Printer.o : inc/Printer.h src/Printer.cpp
	g++ -Iinc -c src/Printer.cpp -o obj/Printer.o

obj/main.o:  src/main.cpp inc/Matrix.h inc/MathOperation.h inc/Printer.h
	g++ -Iinc -c src/main.cpp -o obj/main.o
 
bin/main.exe : obj/main.o obj/Matrix.o obj/MathOperation.o obj/Printer.o
	g++ obj/Matrix.o obj/MathOperation.o obj/Printer.o obj/main.o -o bin/main.exe

