/*
 ============================================================================
 Name        : Main.cpp
 Author      : 2119897987
 Copyright   : Ex4 in C Course
 Description :
 ============================================================================
 */
#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include "Deck.h"
#include "Hand.h"
#include "Set.h"
#include "Wizzard.h"
#include "Archer.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Ghost.h"
#include "Troll.h"

/*
############### Initialize deck ###############
This Function Initialize the Deck
Getting Cards untill getting '00'

	Input:
		Deck* d_deck: The deck we will add him cards
	Output:
		bool - If succeed to create Deck
 */
bool Initialize_deck(Deck* d_deck);

/*string
############### Choose Characters ###############
This Function Asking the user to Choose Characters

	Input:
		Hero*& hero: The Hero pointer ref
		Enemy*& enemy: The Enemy pointer ref
	Output:
		bool - If succeed to create Characters

 	@throws std::bad_alloc if memory allocation fails.
 */
bool Choose_Characters(Hero*& hero, Enemy*& enemy);

/*
############### Start Game ###############
This Function is the game we will play

	Input:
		Hero*& hero: The Hero
		Enemy*& enemy: The Enemy
		Deck*& d_deck: Deck
	Output:
		bool - If game end failure

 	@throws std::bad_alloc if memory allocation fails.
 */
bool Start_Game(Hero*& hero, Enemy*& enemy, Deck*& d_deck);

int main(){
	Hero* hero = nullptr;
	Enemy* enemy = nullptr;
	Deck* d_deck = nullptr;
	// Loading Deck
	try{
		d_deck = new Deck();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory Error\n";
		return -1;
	}
	try{
		// Start Game
		bool create_deck = Initialize_deck(d_deck);
		if(create_deck){
			// Choosing Characters
			bool created_characters = Choose_Characters(hero, enemy);
			if(created_characters){
				bool Game_End = Start_Game(hero, enemy, d_deck);

				if(!Game_End){
					std::cout << "Deck ran out" << std::endl;
				}
			}
		}
	}
	catch (const std::bad_alloc& e) { // Memory Problem
		std::cout << "Memory Error" << std::endl;
		if(d_deck != nullptr) delete(d_deck);
		if(hero != nullptr) delete(hero);
		if(enemy != nullptr) delete(enemy);
	    return -1;
	}

	//Exit Program
	if(d_deck != nullptr) delete(d_deck);
	if(hero != nullptr) delete(hero);
	if(enemy != nullptr) delete(enemy);
    return 0;
}

/*
############### Initialize deck ###############
This Function Initialize the Deck
Getting Cards untill getting '00'

	Input:
		Deck* d_deck: The deck we will add him cards
	Output:
		bool - If succeed to create Deck
 */
bool Initialize_deck(Deck* d_deck){
	if(d_deck == nullptr) return false;
	Deck& deck_ref = *d_deck;
	std::cout << "Initialize deck\n";
	bool getting_cards = true;
	// Getting Cards
	while(getting_cards){
		char card[3];
		std::cin >> card;
		if((card[0] == '0') && (card[1] == '0')){
			getting_cards = false;
			return true;
		}
		bool card_good = deck_ref.Add_Card(card[0], card[1]);
		if(!card_good) getting_cards = false;
	}
	return false;
}

/*
############### Choose Characters ###############
This Function Asking the user to Choose Characters

	Input:
		Hero* hero: The Hero pointer ref
		Enemy* enemy: The Enemy pointer ref
	Output:
		bool - If succeed to create Characters
 */
bool Choose_Characters(Hero*& hero, Enemy*& enemy){
	int player_choice, enemy_choice;
	// Getting the Player
	std::cout << "Choose player character:\n";
	std::cout << "(1) Fighter (2) Sorcerer (3) Ranger\n";
	std::cin >> player_choice;
	try{
		switch(player_choice){
		case 1:
			hero = new Warrior();
			break;
		case 2:
			hero = new Wizzard();
			break;
		case 3:
			hero = new Archer();
			break;
		}
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	// Getting the enemy
	std::cout << "Choose enemy character:\n";
	std::cout << "(1) Troll (2) Ghost (3) Dragon\n";
	std::cin >> enemy_choice;
	try{
		switch(enemy_choice){
		case 1:
			enemy = new Troll();
			break;
		case 2:
			enemy = new Ghost();
			break;
		case 3:
			enemy = new Dragon();
			break;
		}
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	bool good_allocation = (enemy != nullptr) && (hero != nullptr);
	return good_allocation;
}

bool Start_Game(Hero*& hero, Enemy*& enemy, Deck*& d_deck){
	if((enemy == nullptr) || (hero == nullptr) || (d_deck == nullptr)) return false;
	bool GameRun = true;
	// If Deck no size
	if(d_deck->getSize() < hero->Get_Cards_Num()) return false;
	// Create Hand and Set
	Hand* hand;
	try{
		hand = new Hand(d_deck, hero->Get_Cards_Num());
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	Set* set_s;
	try{
		set_s = new Set();
	}
	catch (const std::bad_alloc& e) {
		if(hand != nullptr) delete(hand);
		throw std::bad_alloc();
	}
	//############################# Start the Game #####################
	std::string potential_set;
	bool first_iter = true, NEED_TO_EXIT = false;
	while(GameRun){
		// Print Hero and Enemy HP
		std::cout << "Player health: " << hero->GetHp() << std::endl;
		std::cout << "Enemy health: " << enemy->GetHp() << std::endl;
		// Print current Hand
		std::cout << "Player hand\n" << *hand << std::endl;
		// Get Set
		if(first_iter) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		first_iter = false;
		while(!set_s->isValid()){
			if(set_s != nullptr) delete(set_s);
			set_s = nullptr;
			std::cout << "Insert card set to play" << std::endl;
			std::getline(std::cin, potential_set);
			if(potential_set.compare("exit") == 0){
				NEED_TO_EXIT = true;
				break;
			}
			// Create set
			try{
				set_s = new Set(potential_set, hand);
			}
			catch (const std::bad_alloc& e) {
				// Delete Hand
				if(hand != nullptr) delete(hand);
				hand = nullptr;
				throw std::bad_alloc();
			}
			// If Set is not Valid
			if(!set_s->isValid()){
				std::cout << "Card set is not valid" << std::endl;
			}
		}
		if(NEED_TO_EXIT) break;
		//############################# Attacking #####################
		// Hero Attack Enemy
		hero->fight(*enemy, set_s);
		// Check if enemy alive
		if(enemy->GetHp() == 0){
			// Delete Set And Hand
			if(hand != nullptr) delete(hand);
			hand = nullptr;
			if(set_s != nullptr) delete(set_s);
			set_s = nullptr;
			// Print Winner
			std::cout << "Player won" << std::endl;
			return true;
		}
		// Player Healing and Enemy Attack Player
		enemy->fight(*hero, set_s);
		// Check if Player is Alive
		if(hero->GetHp() == 0){
			// Delete Set And Hand
			if(hand != nullptr) delete(hand);
			hand = nullptr;
			if(set_s != nullptr) delete(set_s);
			set_s = nullptr;
			// Print Winner
			std::cout << "Player lost" << std::endl;
			return true;
		}
		// Fix Set
		if(set_s != nullptr) delete(set_s);
		try{
			set_s = new Set();
		}
		catch (const std::bad_alloc& e) {
			// Delete Hand
			set_s = nullptr;
			if(hand != nullptr) delete(hand);
			hand = nullptr;
			throw std::bad_alloc();
		}
		// Fill Hand
		bool fill_hand = hand->fill_Hand(d_deck);
		if(!fill_hand){ // Deck ran out
			// Delete Set And Hand
			if(hand != nullptr) delete(hand);
			hand = nullptr;
			if(set_s != nullptr) delete(set_s);
			set_s = nullptr;
			return false;
		}
	}
	// Delete Hand and set
	if(set_s != nullptr) delete(set_s);
	if(hand != nullptr) delete(hand);
	return true;
}
