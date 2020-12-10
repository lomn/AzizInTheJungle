main : main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Accessoire.o Fabrique.o Perception.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o BestioleUtil.o Accessoire.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp Accessoire.o
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp LifeManager.o
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

BestioleUtil.o : BestioleUtil.h BestioleUtil.cpp Bestiole.o Accessoire.o
	g++ -Wall -std=c++11 -c BestioleUtil.cpp
	
LifeManager.o : LifeManager.h LifeManager.cpp BestioleUtil.o Accessoire.o
	g++ -Wall -std=c++11 -c LifeManager.cpp -I .

Fabrique.o	: Fabrique.h Fabrique.cpp Accessoire.o Camouflage.o Carapace.o Nageoire.o
	g++ -Wall -std=c++11 -c Fabrique.cpp -I .

# Accessoires
Accessoire.o : ./Accessoire/Accessoire.h ./Accessoire/Accessoire.cpp
	g++ -Wall -std=c++11 -c ./Accessoire/Accessoire.cpp -I .

Camouflage.o : ./Accessoire/Camouflage.h ./Accessoire/Camouflage.cpp
	g++ -Wall -std=c++11 -c ./Accessoire/Camouflage.cpp -I .

Carapace.o : ./Accessoire/Carapace.h ./Accessoire/Carapace.cpp
	g++ -Wall -std=c++11 -c ./Accessoire/Carapace.cpp -I .

Nageoire.o : ./Accessoire/Nageoire.h ./Accessoire/Nageoire.cpp
	g++ -Wall -std=c++11 -c ./Accessoire/Nageoire.cpp -I .

# Perception
Perception.o : ./Perception/Perception.h ./Perception/Perception.cpp Bestiole.o
	g++ -Wall -std=c++11 -c ./Perception/Perception.cpp -I .

Oreilles.o : ./Perception/Oreilles.h ./Perception/Oreilles.cpp
	g++ -Wall -std=c++11 -c ./Perception/Oreilles.cpp -I .

Yeux.o : ./Perception/Yeux.h ./Perception/Yeux.cpp
	g++ -Wall -std=c++11 -c ./Perception/Yeux.cpp -I .