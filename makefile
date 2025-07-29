CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinc

TARGET = bin/matrix_app

SRCS = src/main.cpp src/Matrix.cpp src/Printer.cpp src/MathOperation.cpp

OBJS = obj/main.o obj/Matrix.o obj/Printer.o obj/MathOperation.o

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p bin
	$(CXX) $(OBJS) -o $(TARGET)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj bin

run: all
	./$(TARGET)
