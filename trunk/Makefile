all: bin/p1_main.o bin/Menu.o
	g++ -o bin/p1_main bin/p1_main.o bin/Menu.o
bin/Menu.o: src/Menu.cpp
	g++ -c src/Menu.cpp -o bin/Menu.o
bin/p1_main.o: src/p1_main.cpp
	g++ -c src/p1_main.cpp -o bin/p1_main.o
clean:
	rm bin/*
run:
	bin/p1_main
