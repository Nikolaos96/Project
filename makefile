main: main.o Hero.o Grid.o Square.o
	g++ main.o Hero.o Grid.o Square.o -o main

main.o: main.cc
	g++ -c main.cc

Hero.o: Hero.cc
	g++ -c Hero.cc

Grid.o: Grid.cc
	gcc -c Grid.cc

Square.o: Square.cc
	gcc -c Square.cc

clean:
	rm -f main.o main Hero.o Grid.o Square.o        


