all:
	g++ -Iinc -c src/Matrix.cpp -o obj/Matrix.o 
	g++ -Iinc -c src/MathOperation.cpp -o obj/MathOp.o
	g++ -Iinc -c src/Printer.cpp -o obj/Printer.o
	g++ -Iinc -c src/main.cpp -o obj/main.o
	g++ obj/main.o obj/Matrix.o obj/MathOp.o obj/Printer.o -o bin/main.out
Matrix:
	g++ -Iinc -c src/Matrix.cpp -o obj/Matrix.o
MathOp:
	g++ -Iinc -c src/MathOperation.cpp -o obj/MathOp.o
Printer:
	g++ -Inc -c src/Printer.cpp -o obj/Printer.o
clean:
	rm -f obj/*
