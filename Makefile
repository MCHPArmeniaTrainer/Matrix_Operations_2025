all:
	@mkdir -p bin
	g++ -std=c++11 -Iinc src/*.cpp -o bin/matrix_app

run: all
	./bin/matrix_app

clean:
	rm -f bin/matrix_app
