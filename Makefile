parametrosCompilacao=-Wall -lncurses -ltinfo -g #-Wshadow
nomePrograma=pacman

all: $(nomePrograma)

$(nomePrograma): main.o Pacman.o ConsoleDraw.o Character.o Node.o Map.o Ghost.o Cell.o Behavior.o InvalidPositionException.o Scatter.o FrightenedBehavior.o ChaseAggresive.o ChaseAmbush.o ChaseSiege.o ChaseRandom.o Clock.o CharacterCollisionController.o
	g++ -o $(nomePrograma) main.o Pacman.o ConsoleDraw.o Character.o Node.o Map.o Ghost.o Cell.o Behavior.o InvalidPositionException.o Scatter.o FrightenedBehavior.o ChaseAggresive.o ChaseAmbush.o ChaseSiege.o ChaseRandom.o Clock.o CharacterCollisionController.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

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

ChaseAggresive.o: ChaseAggresive.hpp ChaseAggresive.cpp 
	g++ -c ChaseAggresive.cpp $(parametrosCompilacao)

FrightenedBehavior.o: FrightenedBehavior.hpp FrightenedBehavior.cpp 
	g++ -c FrightenedBehavior.cpp $(parametrosCompilacao)

Scatter.o: Scatter.hpp Scatter.cpp 
	g++ -c Scatter.cpp $(parametrosCompilacao)

ChaseAmbush.o: ChaseAmbush.hpp ChaseAmbush.cpp 
	g++ -c ChaseAmbush.cpp $(parametrosCompilacao)

ChaseSiege.o: ChaseSiege.hpp ChaseSiege.cpp 
	g++ -c ChaseSiege.cpp $(parametrosCompilacao)

ChaseRandom.o: ChaseRandom.hpp ChaseRandom.cpp 
	g++ -c ChaseRandom.cpp $(parametrosCompilacao)

InvalidPositionException.o: InvalidPositionException.hpp InvalidPositionException.cpp 
	g++ -c InvalidPositionException.cpp $(parametrosCompilacao)

CharacterCollisionController.o: CharacterCollisionController.hpp CharacterCollisionController.cpp 
	g++ -c CharacterCollisionController.cpp $(parametrosCompilacao)

Clock.o: Clock.hpp Clock.cpp 
	g++ -c Clock.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
