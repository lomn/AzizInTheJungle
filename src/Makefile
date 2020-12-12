main : main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Fabrique.o BestioleUtil.o Comportement.o Gregaire.o Kamikaze.o Peureux.o Prevoyant.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o LifeManager.o Fabrique.o BestioleUtil.o Comportement.o Gregaire.o Kamikaze.o Peureux.o Prevoyant.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp ./Perception/Perception.h ./Perception/Yeux.h ./Perception/Oreilles.h
	g++ -Wall -std=c++11 -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp LifeManager.h 
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

BestioleUtil.o : BestioleUtil.h BestioleUtil.cpp Bestiole.h ./Accessoire/Accessoire.h
	g++ -Wall -std=c++11 -c BestioleUtil.cpp
	
LifeManager.o : LifeManager.h LifeManager.cpp BestioleUtil.h ./Accessoire/Accessoire.h Bestiole.h
	g++ -Wall -std=c++11 -c LifeManager.cpp -I .

Fabrique.o	: Fabrique.h Fabrique.cpp Bestiole.h
	g++ -Wall -std=c++11 -c Fabrique.cpp -I .

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