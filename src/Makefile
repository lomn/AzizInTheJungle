main : main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Accessoire.o Camouflage.o Carapace.o Nageoire.o Fabrique.o Perception.o Oreilles.o Yeux.o BestioleUtil.o Comportement.o Gregaire.o Kamikaze.o Peureux.o Prevoyant.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Accessoire.o Camouflage.o Carapace.o Nageoire.o Fabrique.o Perception.o Oreilles.o Yeux.o BestioleUtil.o Comportement.o Gregaire.o Kamikaze.o Peureux.o Prevoyant.o -I . -lX11 -lpthread

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

Fabrique.o	: Fabrique.h Fabrique.cpp Bestiole.h ./Accessoire/Accessoire.h ./Accessoire/Carapace.h ./Accessoire/Camouflage.h ./Accessoire/Nageoire.h ./Perception/Perception.h ./Perception/Yeux.h ./Perception/Oreilles.h
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
Perception.o : ./Perception/Perception.h ./Perception/Perception.cpp Bestiole.h ./Perception/Oreilles.h ./Perception/Yeux.h
	g++ -Wall -std=c++11 -c ./Perception/Perception.cpp -I .

Oreilles.o : ./Perception/Oreilles.h ./Perception/Oreilles.cpp Bestiole.h
	g++ -Wall -std=c++11 -c ./Perception/Oreilles.cpp -I .

Yeux.o : ./Perception/Yeux.h ./Perception/Yeux.cpp Bestiole.h
	g++ -Wall -std=c++11 -c ./Perception/Yeux.cpp -I .

# Comportements

Comportement.o : Comportement/Comportement.h Comportement/Comportement.cpp Bestiole.h
	g++ -Wall -std=c++11 -c Comportement/Comportement.cpp -I .

Gregaire.o : Comportement/Comportement.h Bestiole.h Comportement/Gregaire.h Comportement/Gregaire.cpp
	g++ -Wall -std=c++11 -c Comportement/Gregaire.cpp -I .

Kamikaze.o : Comportement/Comportement.h Bestiole.h Comportement/Kamikaze.h Comportement/Kamikaze.cpp
	g++ -Wall -std=c++11 -c Comportement/Kamikaze.cpp -I .

Peureux.o : Comportement/Comportement.h Bestiole.h Comportement/Peureux.h Comportement/Peureux.cpp
	g++ -Wall -std=c++11 -c Comportement/Peureux.cpp -I .

Prevoyant.o : Comportement/Comportement.h Bestiole.h Comportement/Prevoyant.h Comportement/Prevoyant.cpp
	g++ -Wall -std=c++11 -c Comportement/Prevoyant.cpp -I .