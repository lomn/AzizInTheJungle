main : main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Fabrique.o BestioleUtil.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Fabrique.o BestioleUtil.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp ./Accessoire/Accessoire.h ./Accessoire/Carapace.h ./Accessoire/Camouflage.h ./Accessoire/Nageoire.h ./Perception/Perception.h ./Perception/Yeux.h ./Perception/Oreilles.h
	g++ -Wall -std=c++11 -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp LifeManager.h 
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

BestioleUtil.o : BestioleUtil.h BestioleUtil.cpp Bestiole.h ./Accessoire/Accessoire.h
	g++ -Wall -std=c++11 -c BestioleUtil.cpp
	
LifeManager.o : LifeManager.h LifeManager.cpp BestioleUtil.h ./Accessoire/Accessoire.h Bestiole.h
	g++ -Wall -std=c++11 -c LifeManager.cpp -I .

Fabrique.o	: Fabrique.h Fabrique.cpp ./Accessoire/Accessoire.h ./Accessoire/Camouflage.h ./Accessoire/Carapace.h ./Accessoire/Nageoire.h Bestiole.h
	g++ -Wall -std=c++11 -c Fabrique.cpp -I .-I .
