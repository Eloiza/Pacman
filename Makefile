parametrosCompilacao=-Wall -lncurses -ltinfo -g #-Wshadow
nomePrograma=pacman

all: $(nomePrograma)

$(nomePrograma): main.o Coordenada.o Pacman.o ConsoleDraw.o Character.o Node.o Map.o Ghost.o Cell.o ChaseBehavior.o Behavior.o InvalidPositionException.o ScatterBehavior.o AmbushBehavior.o FrightenedBehavior.o
	g++ -o $(nomePrograma) main.o Coordenada.o Pacman.o ConsoleDraw.o Character.o Node.o Map.o Ghost.o Cell.o ChaseBehavior.o Behavior.o InvalidPositionException.o ScatterBehavior.o AmbushBehavior.o FrightenedBehavior.o $(parametrosCompilacao)

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

Node.o: Node.hpp Node.cpp 
	g++ -c Node.cpp $(parametrosCompilacao)

Cell.o: Cell.hpp Cell.cpp 
	g++ -c Cell.cpp $(parametrosCompilacao)

Map.o: Map.hpp Map.cpp
	g++ -c Map.cpp $(parametrosCompilacao)

Ghost.o: Ghost.hpp Ghost.cpp 
	g++ -c Ghost.cpp $(parametrosCompilacao)

Behavior.o: Behavior.hpp Behavior.cpp 
	g++ -c Behavior.cpp $(parametrosCompilacao)

ChaseBehavior.o: ChaseBehavior.hpp ChaseBehavior.cpp 
	g++ -c ChaseBehavior.cpp $(parametrosCompilacao)

FrightenedBehavior.o: FrightenedBehavior.hpp FrightenedBehavior.cpp 
	g++ -c FrightenedBehavior.cpp $(parametrosCompilacao)

ScatterBehavior.o: ScatterBehavior.hpp ScatterBehavior.cpp 
	g++ -c ScatterBehavior.cpp $(parametrosCompilacao)

AmbushBehavior.o: AmbushBehavior.hpp AmbushBehavior.cpp 
	g++ -c AmbushBehavior.cpp $(parametrosCompilacao)

InvalidPositionException.o: InvalidPositionException.hpp InvalidPositionException.cpp 
	g++ -c InvalidPositionException.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
