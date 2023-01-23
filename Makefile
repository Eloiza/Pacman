parametrosCompilacao=-Wall -lncurses -ltinfo #-Wshadow
nomePrograma=pacman

all: $(nomePrograma)

$(nomePrograma): main.o Coordenada.o Pacman.o ConsoleDraw.o
	g++ -o $(nomePrograma) main.o Coordenada.o Pacman.o ConsoleDraw.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Coordenada.o: Coordenada.hpp Coordenada.cpp
	g++ -c Coordenada.cpp $(parametrosCompilacao)

Pacman.o: Pacman.hpp Pacman.cpp
	g++ -c Pacman.cpp $(parametrosCompilacao)

ConsoleDraw.o: ConsoleDraw.hpp ConsoleDraw.cpp
	g++ -c ConsoleDraw.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
