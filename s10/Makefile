all: build
build:
	g++ -c instrumentos.cpp
	g++ instrumentos.o main.cpp -o main
	main.exe

clean:
	-rm -rf *.o
	-rm -rf *.exe