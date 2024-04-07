/*
 * Deck Class
 * Deck.h
 */
#ifndef DECK_H_
#define DECK_H_
#include <iostream>
#include "Card.h"

/**
 * This class represent a Deck Object
 */
class Deck{
protected:
	// int size: The size of the Deck
	int m_size;
	// Card* cards: Cards Array of Cards Pointers - Represents the Deck: New cards at the end
	Card** m_cards;

public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		Card** m_cards = NULL
	 * 		int m_size = 0
	 */
	Deck();
	/**
	 * Copy Constructor
	 *
	 * Members:
	 * 		Card** m_cards = other.m_cards
	 * 		int m_size = other.m_size
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 */
	Deck(const Deck &other);
	/**
	 * Assignment Operator
	 *
	 * Members:
	 * 		Card** m_cards = other.m_cards
	 * 		int m_size = other.m_size
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 */
	Deck& operator=(const Deck &other);
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
	Deck& operator+=(Card** new_cards);
	/**
	 * Function for peek Cards from the Head of the Deck(oldest Cards)
	 * Peek for the given number cards or untill the end of the Deck, the lowest between these two
	 *
	 * Input:
	 * 		@param num_to_peek - Number of Card we will be peek
	 * */
	void peek(int num_to_peek) const;
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
	Deck& operator-=(int num_to_remove);
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
	Card& operator[](int index);
	/**
	 * Function for operator '<<' - used for printing Deck
	 * Print the Deck from the Bottom the the Head
	 *
	 * Input:
	 * 		@param d_deck - Deck we will print
	 * */
	friend std::ostream& operator<<(std::ostream& output, const Deck& d_deck);
	/**
	 * Function that Initialize Deck - Request Cards untill input '00'
	 *
	 * Input:
	 * 		@param rank - Cards rank
	 * 		@param sign - Cards sign
	 *
	 * Output: bool - True or False is succeed Initialize
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 * */
	bool Add_Card(char rank, char sign);
	/**
	 * Function for Check if the hand is Empty
	 *
	 * Output: bool- True of False if Empty
	 * */
	bool isEmpty()const;
	/**
	 * Function for Check if the hand is Empty
	 *
	 * Output: bool- True of False if Empty
	 * */
	int getSize()const;
	/**
	 * Function that Search Card at the Deck
	 *
	 * Input:
	 * 		@param rank - Cards rank
	 * 		@param sign - Cards sign
	 *
	 * Output: bool - True or False is found
	 * */
	bool Search_Card(char rank, char sign)const;
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
	bool delete_Card(char rank, char sign);

	/**
	 * Destructor
	 * Delete all the Cards and then delete the Cards-Pointers-Array
	 */
	virtual ~Deck();
	friend class Hand;
};

#endif /* DECK_H_ */
