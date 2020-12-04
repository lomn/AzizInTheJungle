main : main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o BestioleUtil.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp LifeManager.o
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

BestioleUtil.o : BestioleUtil.h BestioleUtil.cpp Bestiole.o
	g++ -Wall -std=c++11 -c BestioleUtil.cpp
	
LifeManager.o : LifeManager.h LifeManager.cpp BestioleUtil.o
	g++ -Wall -std=c++11 -c LifeManager.cpp -I .
