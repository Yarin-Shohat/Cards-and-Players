/*
 * Hand.cpp
 *
 */

#include <iostream>
#include "Hand.h"
#include "Card.h"

/**
 * Default Constructor
 *
 * Members:
 * 		Card** m_cards = NULL
 * 		int m_size = 0
 * 		int MAX_SIZE = 0
 */
Hand::Hand(): Deck(), MAX_SIZE(0){}

/**
 * Regular Constructor
 *
 * Members:
 * 		Card** m_cards = num Cards from Deck
 * 		int m_size = num
 *
 *	@throws std::bad_alloc if memory allocation fails.
 */
Hand::Hand(Deck* other, int num): Deck(){
	if(other == nullptr) throw std::bad_alloc();
	// Set Size
	this->m_size = num;
	this->MAX_SIZE = num;
	// Create New Arr
	try{
		this->m_cards = new Card*[num];
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	// Move Cards
	int i ;
	try{
		for(i = 0; i < num; i++){
			this->m_cards[i] = new Card(*other->m_cards[i]);
		}
	}
	catch (const std::bad_alloc& e) {
		for(int j = 0; j < i; j++){
			delete(this->m_cards[j]);
		}
		delete[] this->m_cards;
		throw std::bad_alloc();
	}
	// Delete from Deck the Cards
	other->operator-=(num);
}

/**
 * Destructor
 * Delete all the Cards and then delete the Cards-Pointers-Array
 */
Hand::~Hand() {}

/**
 * Copy Constructor
 *
 * Members:
 * 		Card** m_cards = other.m_cards
 * 		int m_size = other.m_size
 */
Hand::Hand(const Hand &other): Deck(other), MAX_SIZE(other.MAX_SIZE) {}

/**
 * Assignment Operator
 *
 * Members:
 * 		Card** m_cards = other.m_cards
 * 		int m_size = other.m_size
 */
Hand& Hand::operator=(const Hand &other) {
	if(this != &other){
		// Use Deck operator=
		Deck::operator = (other);
		this->MAX_SIZE = other.MAX_SIZE;
	}
	return *this;
}

/**
 * Function for fill the cards from the hand after attacking
 *
 * Input:
 * 		@param Deck*& deck - Deck we will take from him cards
 *
 *	@throws std::bad_alloc if memory allocation fails.
 * */
bool Hand::fill_Hand(Deck*& deck){
	if(deck == nullptr) return false;
	// Get the new Size for tha hand
	int new_size = std::min(this->MAX_SIZE, this->m_size+2);
	int cards_to_add = new_size - this->m_size;
	// Check if has cards from deck to add
	if(cards_to_add > deck->getSize()){
		return false;
	}
	// Copy cards to new Hand
	Card** new_hand;
	try{
		new_hand = new Card*[new_size];
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	for(int i = 0; i < this->m_size; i++){
		new_hand[i] = this->m_cards[i];
	}
	// Add new Cards
	int i, j;
	try{
		for(i = 0, j = this->m_size; j < new_size; j++, i++){
			new_hand[j] = new Card(*deck->m_cards[i]);
		}
	}
	catch (const std::bad_alloc& e) {
		for(int k = 0; k < j; k++){
			if(new_hand[k] != nullptr) delete(new_hand[k]);
			delete[] new_hand;
		}
		throw std::bad_alloc();
	}
	// Delete from Deck the Cards
	deck->operator-=(cards_to_add);
	// Update new Hand
	if(this->m_cards != nullptr) delete[] this->m_cards;
	this->m_cards = new_hand;
	this->m_size = new_size;
	return true;
}

/**
 * Function for operator '<<' - used for printing Hand
 * Print Hand Cards in one line with '-' between every Card
 *
 * Input:
 * 		@param d_hand - Hand we will print
 * */
std::ostream& operator<<(std::ostream& output, const Hand& d_hand){
	// Print hand Cards with space separate
	for(int i = d_hand.m_size-1; i >= 0; i--){
		output << *(d_hand.m_cards[i]) << ' ';
	}
	// End of Hand
	return output;
}
