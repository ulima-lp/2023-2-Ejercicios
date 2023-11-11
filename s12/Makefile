all: build
build:
	g++ -c herencia.cpp
	g++ -c instrumentos.cpp
	g++ herencia.o instrumentos.o main.cpp -o main
	main.exe

clean:
	-rm -rf *.o
	-rm -rf *.exe