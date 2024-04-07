/*
 * Deck.cpp
 *
 */
#include <iostream>
#include <cstdlib>
#include "Deck.h"

// ####################### Public Functions #######################

/**
 * Default Constructor
 *
 * Members:
 * 		Card** m_cards = NULL
 * 		int m_size = 0
 */
Deck::Deck() : m_cards(nullptr), m_size(0){
}

/**
 * Copy Constructor
 *
 * Members:
 * 		Card** m_cards = other.m_cards
 * 		int m_size = other.m_size
 *
 *	@throws std::bad_alloc if memory allocation fails.
 */
Deck::Deck(const Deck &other){
	// Copy Size
	this->m_size = other.m_size;
	try{
		this->m_cards = new Card*[this->m_size];
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	// Copy Cards
	int i;
	try{
		for(i = 0; i < this->m_size; i++){
			this->m_cards[i] = new Card(*(other.m_cards[i]));
		}
	}
	catch (const std::bad_alloc& e) {
		for(int j = 0; j < i; j++){
			delete this->m_cards[j];
		}
		delete[] this->m_cards;
		throw std::bad_alloc();
	}
}

/**
 * Assignment Operator
 *
 * Members:
 * 		Card** m_cards = other.m_cards
 * 		int m_size = other.m_size
 *
 *	@throws std::bad_alloc if memory allocation fails.
 */
Deck& Deck::operator=(const Deck &other){
	if(this != &other){
		// Free old Data
		if(this->m_cards != nullptr){
			for(int i = 0; i<this->m_size; i++){
				if(this->m_cards[i] != nullptr) delete this->m_cards[i];
			}
			delete[] this->m_cards;
		}
		// Assign new Data - Size
		this->m_size = other.m_size;
		try{
			this->m_cards = new Card*[this->m_size];
		}
		catch (const std::bad_alloc& e) {
			this->m_size = 0;
			throw std::bad_alloc();
		}
		// Assign new Cards
		int i;
		try{
			for(i = 0; i < this->m_size; i++){
				this->m_cards[i] = new Card(*(other.m_cards[i]));
			}
		}
		catch (const std::bad_alloc& e) {
			for(int j = 0; j < i; j++){
				delete this->m_cards[j];
			}
			delete[] this->m_cards;
			throw std::bad_alloc();
		}
	}
	return *this;
}

/**
 * Function for Add operator '+='
 * Add Cards to the Deck from other Deck
 * Cards added to the bottom of the Deck(New Cards)
 *
 * Input:
 * 		@param new_cards - Cards Pointers Array
 *
 * Output: Deck& - Deck reference to this card
 *
 *	@throws std::bad_alloc if memory allocation fails.
 * */
Deck& Deck::operator+=(Card** new_cards){
	if(new_cards == nullptr) return *this;
	// Find the size of the new cards to add
	int new_cards_size = 0;
	while(new_cards[new_cards_size] != nullptr) new_cards_size++;

	// If given 0 Cards to add - No Action
	if(new_cards_size == 0) return *this;

	// Get the new Cards Array size and create it
	int new_size = this->m_size + new_cards_size;
	Card** new_deck;
	try{
		new_deck = new Card*[new_size];
	}
	catch (const std::bad_alloc& e) {
		if(this->m_cards != nullptr){
			for(int i = 0; i<this->m_size; i++){
				if(this->m_cards[i] != nullptr) delete(this->m_cards[i]);
			}
			delete[] this->m_cards;
		}
		throw std::bad_alloc();
	}
	// Copy the old cards to the new Deck
	for(int i = 0; i < this->m_size ; i++) new_deck[i] = this->m_cards[i];
	// Add the new Cards to the new Deck
	int i;
	try{
		for(i = 0; i < new_cards_size ; i++) new_deck[i + this->m_size] = new Card(*(new_cards[i]));
	}
	catch (const std::bad_alloc& e) {
		for(int j = 0; j < i; j++){
			delete this->m_cards[j];
		}
		delete[] new_deck;
		if(this->m_cards != nullptr) delete[] this->m_cards;
		this->m_size = 0;
		throw std::bad_alloc();
	}
	// Delete the old Deck and update the new Deck
	if(this->m_cards != nullptr) delete[] this->m_cards;
	this->m_cards = new_deck;
	// Update the new Size
	this->m_size = new_size;

	return *this;
}

/**
 * Function for peek Cards from the Head of the Deck(oldest Cards)
 * Peek for the given number cards or untill the end of the Deck, the lowest between these two
 *
 * Input:
 * 		@param num_to_peek - Number of Card we will be peek
 * */
void Deck::peek(int num_to_peek) const{
	// Check for valid number to peek - Positive number
	if(num_to_peek < 0){
		std::cout << "Invalid number\n";
		return;
	}
	// Print the Deck from the Head(index 0) to the index(num_to_peek) or to the end of the Deck(the smallest)
	for(int i = 0; (i < num_to_peek) && (i < this->m_size); i++){
		std::cout << *(this->m_cards[i]) << "\n";
	}
	return;
}

/**
 * Function for Add operator '-='
 * Remove Cards from the Deck from other Deck
 *
 * Input:
 * 		@param num_to_remove - number of cards to remove from the Head of the Deck(Oldest Cards)
 *
 * Output: Deck& - Deck reference to this card
 *
 *	@throws std::bad_alloc if memory allocation fails.
 * */
Deck& Deck::operator-=(int num_to_remove){
	// Check for valid number to remove - Positive number
	if(num_to_remove < 0){
		std::cout << "Invalid number\n";
		return *this;
	}

	// If given 0 Cards to remove - No Action
	if(num_to_remove == 0) return *this;

	// Check if the number of Card to remove is smaller or equal to the Deck size - Fix if need
	if(num_to_remove > this->m_size) num_to_remove = this->m_size;

	// Delete the cards we will throw
	for(int i = 0; i < num_to_remove; i++){
		if(this->m_cards[i] != nullptr) delete(this->m_cards[i]);
	}

	// Fixed Cards Array length
	int new_size = this->m_size - num_to_remove;
	// Create new Deck and Copy the Cards
	Card** new_deck;
	try{
		new_deck = new Card*[new_size];
	}
	catch (const std::bad_alloc& e) {
		if(this->m_cards != nullptr){
			for(int i = 0; i<this->m_size; i++){
				if(this->m_cards[i] != nullptr) delete(this->m_cards[i]);
			}
			delete[] this->m_cards;
			this->m_size = 0;
		}
		throw std::bad_alloc();
	}
	for(int i = 0 ; i < new_size ; i++) new_deck[i] = this->m_cards[i + num_to_remove];
	if(this->m_cards != nullptr) delete[]this->m_cards;
	this->m_cards = new_deck;
	this->m_size = new_size;
	if(this->m_size == 0)
	{
		if(this->m_cards != nullptr) delete[]this->m_cards;
		this->m_cards = nullptr;
	}

	return *this;
}

/**
 * Function for Add operator '[i]'
 * Go to the Card in index i from the bottom of the Deck
 * 0 Represents the latest Card added, 1 The Card that added before him, and so...
 *
 * Input:
 * 		@param index - Card index from the bottom of the Deck that we want
 *
 * Output: Card* - Card Pointer to the Card index we wanted
 *
 *	@throws std::bad_alloc if memory allocation fails.
 * */
Card& Deck::operator[](int index){
	if((index < 0) || (index >= this->m_size)){
		std::cout << "Invalid index\n";
		Card* temp;
		try{
			temp = new Card('\0', '\0');
		}
		catch (const std::bad_alloc& e) {
			throw std::bad_alloc();
		}
		return *temp;
	}
	return *(this->m_cards[this->m_size - index - 1]);
}

/**
 * Function for operator '<<' - used for printing Deck
 * Print the Deck from the Bottom the the Head
 *
 * Input:
 * 		@param d_deck - Deck we will print
 * */
std::ostream& operator<<(std::ostream& output, const Deck& d_deck){
	// Print border of Deck
	output << "[";
	// First Card from the bottom
	if(d_deck.m_size > 0) output << *(d_deck.m_cards[d_deck.m_size - 1]);
	// Add the rest of the cards - From the bottom after the first card
	for(int i = 2; i <= d_deck.m_size; i++){
		output << "," << *(d_deck.m_cards[d_deck.m_size - i]);
	}
	// End of Deck
	output << "]";
	return output;
}

/**
 * Function that Initialize Deck - Request Cards untill input '00'
 *
 * Output: bool - True or False is succeed Initialize
 *
 *	@throws std::bad_alloc if memory allocation fails.
 * */
bool Deck::Add_Card(char rank, char sign){
	// Create new Cards Array
	int new_size = this->m_size + 1;
	Card** new_deck;
	try{
		new_deck = new Card*[new_size];
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	// Copy the old cards to the new Deck
	for(int i = 0; i < this->m_size ; i++) new_deck[i] = this->m_cards[i];
	// Create new Card to last place
	Card* new_card;
	try{
		new_card = new Card(rank, sign);
	}
	catch (const std::bad_alloc& e) {
		delete[] new_deck;
		throw std::bad_alloc();
	}
	new_deck[this->m_size] = new_card;
	// Delete the old Deck and update the new Deck
	if(this->m_size != 0) delete[] this->m_cards;
	this->m_cards = new_deck;
	// Update the new Size
	this->m_size = new_size;

	return true;
}

/**
 * Function for Check if the hand is Empty
 *
 * Output: bool- True of False if Empty
 * */
bool Deck::isEmpty()const{
	return (this->m_size <= 0);
}

/**
 * Function getting the size of the dexk
 *
 * Output: m_size
 * */
int Deck::getSize()const{
	return this->m_size;
}

/**
 * Function that Search Card at the Deck
 *
 * Input:
 * 		@param rank - Cards rank
 * 		@param sign - Cards sign
 *
 * Output: bool - True or False is found
 * */
bool Deck::Search_Card(char rank, char sign)const{
	for(int i = 0; i<this->m_size; i++){
		// Get sign and rank
		char c_rank = this->m_cards[i]->get_Rank();
		char c_sign = this->m_cards[i]->get_Sign();
		if((c_rank == rank) && (c_sign == sign)){ // Found!!!
			return true;
		}
	} // Didn't Found! :(
	return false;
}

/**
 * Function that Delete Card from the Deck
 *
 * Input:
 * 		@param rank - Cards rank
 * 		@param sign - Cards sign
 *
 * Output: bool - True or False is deleted
 *
 *	@throws std::bad_alloc if memory allocation fails.
 * */
bool Deck::delete_Card(char rank, char sign){
	int index_remove;
	for(index_remove = 0; index_remove<this->m_size; index_remove++){
		// Get sign and rank
		char c_rank = this->m_cards[index_remove]->get_Rank();
		char c_sign = this->m_cards[index_remove]->get_Sign();
		if((c_rank == rank) && (c_sign == sign)){ // Found!!!
			break;
		}
	} // Didn't Found! :(
	if(index_remove == this->m_size) return false;
	// Delete the Card
	if(this->m_cards[index_remove] != nullptr) delete(this->m_cards[index_remove]);
	this->m_cards[index_remove] = nullptr;
	// Create new Cards Array
	int new_size = this->m_size - 1;
	Card** new_deck;
	try{
		new_deck = new Card*[new_size];
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	// Copy the old cards to the new Deck
	int old_index = 0, new_index = 0;
	while(old_index < this->m_size){
		if(old_index != index_remove){
			new_deck[new_index] = this->m_cards[old_index];
			new_index++;
		}
		old_index++;
	}
	// Delete the old Deck and update the new Deck
	if(this->m_cards != nullptr) delete[] this->m_cards;
	this->m_cards = new_deck;
	// Update the new Size
	this->m_size = new_size;
	return true;
}

/**
 * Destructor
 * Delete all the Cards and then delete the Cards-Pointers-Array
 */
Deck::~Deck(){
	if(this->m_cards != nullptr){
		for(int i = 0; i<this->m_size; i++){
			if(this->m_cards[i] != nullptr) delete(this->m_cards[i]);
		}
		delete[] this->m_cards;
	}
}
