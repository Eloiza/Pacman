parametrosCompilacao=-Wall -lncurses -ltinfo #-Wshadow
nomePrograma=pacman

all: $(nomePrograma)

$(nomePrograma): main.o Coordenada.o Pacman.o ConsoleDraw.o Character.o
	g++ -o $(nomePrograma) main.o Coordenada.o Pacman.o ConsoleDraw.o Character.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Coordenada.o: Coordenada.hpp Coordenada.cpp
	g++ -c Coordenada.cpp $(parametrosCompilacao)

Pacman.o: Pacman.hpp Pacman.cpp
	g++ -c Pacman.cpp $(parametrosCompilacao)

ConsoleDraw.o: ConsoleDraw.hpp ConsoleDraw.cpp
	g++ -c ConsoleDraw.cpp $(parametrosCompilacao)

Character.o: Character.hpp Character.cpp
	g++ -c Character.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
