Decks_game: Character.o Hero.o Enemy.o Archer.o Warrior.o Wizzard.o Troll.o Ghost.o Dragon.o Card.o Deck.o Hand.o Set.o Main.o
	g++ Character.o Hero.o Enemy.o Archer.o Warrior.o Wizzard.o Troll.o Ghost.o Dragon.o Card.o Deck.o Hand.o Set.o Main.o -o Decks_game

Character.o: Character.h Character.cpp
	g++ -c Character.cpp

Hero.o: Hero.h Hero.cpp Character.h
	g++ -c Hero.cpp

Enemy.o: Enemy.h Enemy.cpp Character.h
	g++ -c Enemy.cpp

Archer.o: Archer.cpp Archer.h Hero.h Character.h Enemy.h Set.h Hand.h Deck.h Card.h
	g++ -c Archer.cpp

Warrior.o: Warrior.cpp Warrior.h Hero.h Character.h Enemy.h Set.h Hand.h Deck.h Card.h
	g++ -c Warrior.cpp

Wizzard.o: Wizzard.cpp Set.h Hand.h Deck.h Card.h Enemy.h Character.h Wizzard.h Hero.h
	g++ -c Wizzard.cpp

Troll.o: Troll.cpp Hero.h Character.h Troll.h Enemy.h Set.h Hand.h Deck.h Card.h
	g++ -c Troll.cpp

Ghost.o: Ghost.cpp Hero.h Character.h Ghost.h Enemy.h Set.h Hand.h Deck.h Card.h
	g++ -c Ghost.cpp

Dragon.o: Dragon.cpp Hero.h Character.h Dragon.h Enemy.h Set.h Hand.h Deck.h Card.h
	g++ -c Dragon.cpp

Card.o: Card.h Card.cpp
	g++ -c Card.cpp

Deck.o: Deck.h Deck.cpp Card.h
	g++ -c Deck.cpp

Hand.o: Hand.h Hand.cpp Deck.h Card.h
	g++ -c Hand.cpp

Set.o: Set.cpp Set.h Hand.h Deck.h Card.h
	g++ -c Set.cpp

Main.o: Main.cpp Deck.h Card.h Hand.h Set.h Wizzard.h Hero.h Character.h Archer.h Warrior.h Dragon.h Enemy.h Ghost.h Troll.h
	g++ -c Main.cpp

clean:
	rm -f Character.o Hero.o Enemy.o Archer.o Warrior.o Wizzard.o Troll.o Ghost.o Dragon.o Card.o Deck.o Set.o Main.o Decks_game
