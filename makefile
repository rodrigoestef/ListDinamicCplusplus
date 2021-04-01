all: List


List: List.o
	g++ -shared ./objs/List.o -o ./Release/List.dll

List.o:
	g++ ./src/List.cpp -c -o ./objs/List.o
	cp ./src/*.h ./Release

debug: Teste

Teste: Teste.o
	g++ -Wall -g -o ./Debug/teste ./objs/teste.o ./objs/List.o

Teste.o: Listdebug.o
	g++ -Wall -g -I ./src ./test/teste.cpp -c -o ./objs/teste.o
Listdebug.o:
	g++ -Wall -g ./src/List.cpp -c -o ./objs/List.o


clear:
	rm -rf ./objs/*
	rm -rf ./Debug/*
	rm -rf ./Release/*
