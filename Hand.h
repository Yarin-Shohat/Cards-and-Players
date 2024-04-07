/*
 * Hand.h
 *
 */

#ifndef HAND_H_
#define HAND_H_

#include "Deck.h"

class Hand: public Deck {
private:
	// Max Size of hand
	int MAX_SIZE;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		Card** m_cards = NULL
	 * 		int m_size = 0
	 * 		int MAX_SIZE = 0
	 */
	Hand();
	/**
	 * Regular Constructor
	 *
	 * Members:
	 * 		Card** m_cards = num Cards from Deck
	 * 		int m_size = num
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 */
	Hand(Deck* other, int num);
	/**
	 * Destructor
	 * Delete all the Cards and then delete the Cards-Pointers-Array
	 */
	virtual ~Hand();
	/**
	 * Copy Constructor
	 *
	 * Members:
	 * 		Card** m_cards = other.m_cards
	 * 		int m_size = other.m_size
	 */
	Hand(const Hand &other);
	/**
	 * Assignment Operator
	 *
	 * Members:
	 * 		Card** m_cards = other.m_cards
	 * 		int m_size = other.m_size
	 */
	Hand& operator=(const Hand &other);
	/**
	 * Function for fill the cards from the hand after attacking
	 *
	 * Input:
	 * 		@param Deck*& deck - Deck we will take from him cards
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 * */
	bool fill_Hand(Deck*& deck);
	/**
	 * Function for operator '<<' - used for printing Hand
	 * Print Hand Cards in one line with '-' between every Card
	 *
	 * Input:
	 * 		@param d_hand - Hand we will print
	 * */
	friend std::ostream& operator<<(std::ostream& output, const Hand& d_hand);
};

#endif /* HAND_H_ */
