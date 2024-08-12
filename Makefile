OBJ=obj
BIN=bin

bin/main: obj/main.o
	[ -d $(BIN) ] || mkdir -p $(BIN)
	g++ obj/main.o -o bin/main.exe -Iinclude -Llib -lsfml-system -lsfml-window -lsfml-graphics -rpath lib

obj/main.o: src/main.cpp
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	g++ -c -Iinclude -o obj/main.o src/main.cpp

run:
	./bin/main.exe