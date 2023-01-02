parametrosCompilacao=-Wall #-Wshadow
nomePrograma=pacman

all: $(nomePrograma)

$(nomePrograma): main.o Coordenada.o
	g++ -o $(nomePrograma) main.o Coordenada.o  $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Coordenada.o: Coordenada.hpp Coordenada.cpp
	g++ -c Coordenada.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
