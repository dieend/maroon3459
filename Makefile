all: bin/p1_main.o bin/Menu.o bin/Cart.o bin/Date.o bin/Cart_item.o \
     bin/Product.o bin/Customer.o bin/Category.o
	g++ -o p1_main bin/p1_main.o bin/Menu.o bin/Cart.o bin/Date.o \
	bin/Cart_item.o bin/Product.o bin/Customer.o bin/Category.o \
	 -Wall

bin/Menu.o: src/Menu.cpp
	g++ -c src/Menu.cpp -o bin/Menu.o -Wall

bin/p1_main.o: src/p1_main.cpp
	g++ -c src/p1_main.cpp -o bin/p1_main.o -Wall

bin/Cart.o: src/Cart.cpp
	g++ -c src/Cart.cpp -o bin/Cart.o -Wall

bin/Date.o: src/Date.cpp
	g++ -c src/Date.cpp -o bin/Date.o -Wall

bin/Cart_item.o: src/Cart_item.cpp
	g++ -c src/Cart_item.cpp -o bin/Cart_item.o -Wall

bin/Product.o: src/Product.cpp
	g++ -c src/Product.cpp -o bin/Product.o -Wall

bin/Customer.o: src/Customer.cpp
	g++ -c src/Customer.cpp -o bin/Customer.o -Wall
bin/Category.o: src/Category.cpp
	g++ -c src/Category.cpp -o bin/Category.o -Wall

clean:
	rm bin/* p1_main src/*~

run:
	./p1_main
