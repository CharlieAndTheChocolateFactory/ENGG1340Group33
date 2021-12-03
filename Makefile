FLAGS = -pedantic-errors -std=c++11

main: main.o game.o
	g++ $(FLAGS) $^ -o $@

main.o: main.cpp main.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h
	g++ $(FLAGS) -c $<

clean:
	rm -f main main.o game.o

.PHONY: clean
