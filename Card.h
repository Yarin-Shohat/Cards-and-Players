/*
 * Card Class
 * Card.h
 */
#ifndef CARD_H_
#define CARD_H_
#include <iostream>

/**
 * This class represent a Card Object
 */
class Card{
private:
	// Card rank: A, 2-9, T, J, Q, K
	char m_rank;
	// Card sign: C - clover, S - Leaf, H - Heart, D - Diamond
	char m_sign;
	// Card Value: 1, 2-9, 10, 11, 12, 13
	int m_value;

	/**
	 * Private Function that check if rank is valid rank
	 *
	 * Input:
	 * 		@param rank - rank of card
	 *
	 * Output:
	 * 		boolean - True if the rank is valid, Else False
	 * */
	bool check_rank_is_valid(char rank) const;
	/**
	 * Private Function that check if rank is valid rank
	 *
	 * Input:
	 * 		@param rank - rank of card
	 *
	 * Output:
	 * 		boolean - True if the sign is valid, Else False
	 * */
	bool check_sign_is_valid(char sign) const;
	/**
	 * Private Function return value for sign for comparing functions
	 *
	 * Output: int - int value for signs
	 * */
	int get_sign_value() const;
	/**
	 * Function that change the value of card
	 *
	 * Input:
	 * 		@param rank - char represents m_rank of card
	 *
	 * 		m_value(sign): 1(A), 2-9(2-9), 10(J), 15(Q), 20(K)
	 */
	void set_value(char rank);

public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		char m_rank = '\0'
	 * 		char m_sign = '\0'
	 * 		int m_value = 0
	 */
	Card();
	/**
	 * Regular Constructor
	 *
	 * Input:
	 * 		@param rank - char represents m_rank of card
	 * 		@param sign - char represents m_sign of card
	 *
	 * 		m_value(sign): 1(A), 2-9(2-9), 10(J), 15(Q), 20(K)
	 */
	Card(char rank, char sign);
	/**
	 * Copy Constructor - members will be like other
	 *
	 * Input:
	 * 		@param otherCard - other object of Card, values will be copy from that object
	 * */
	Card(const Card& otherCard);
	/**
	 * Function for Assignment operator '=' - used to assign Card to be other Card
	 * Copy the Values of other Card to this Card the return this Card
	 *
	 * Input:
	 * 		@param other - other object of Card, values will be copy from that object
	 * */
	Card& operator=(const Card& other);
	/**
	 * Function for Compare operator '=='
	 * Check if two Cards are equals
	 *
	 * Input:
	 * 		@param other - other object of Card
	 *
	 * Output: bool - True if equal, Else False
	 * */
	bool operator==(const Card& other) const;
	/**
	 * Function for Compare operator '!='
	 * Check if two Cards are not equals
	 *
	 * Input:
	 * 		@param other - other object of Card
	 *
	 * Output: bool - True if not equal, Else False
	 * */
	bool operator!=(const Card& other) const;
	/**
	 * Function for Compare operator '<='
	 * Check if this Card is less/equal then other
	 *
	 * Input:
	 * 		@param other - other object of Card
	 *
	 * Output: bool - True if less/equal, Else False
	 * */
	bool operator<=(const Card& other) const;
	/**
	 * Function for Compare operator '>='
	 * Check if this Card is greater/equal then other
	 *
	 * Input:
	 * 		@param other - other object of Card
	 *
	 * Output: bool - True if greater/equal, Else False
	 * */
	bool operator>=(const Card& other) const;
	/**
	 * Function for Compare operator '<'
	 * Check if this Card is less then other
	 *
	 * Input:
	 * 		@param other - other object of Card
	 *
	 * Output: bool - True if smaller, Else False
	 * */
	bool operator<(const Card& other) const;
	/**
	 * Function for Compare operator '<'
	 * Check if this Card is greater then other
	 *
	 * Input:
	 * 		@param other - other object of Card
	 *
	 * Output: bool - True if greater, Else False
	 * */
	bool operator>(const Card& other) const;
	/**
	 * Function for operator << - used for printing Card
	 *
	 * Input:
	 * 		@param c_card - card we will print
	 * */
	friend std::ostream& operator<<(std::ostream& output, const Card& c_card);
	/**
	 * Function that check if this card is empty card
	 *
	 * Output: bool - True if its empty card, Else False
	 * */
	bool is_empty_card() const;
	/**
	 * Function that change the card members
	 *
	 * Input:
	 * 		@param rank - char represents m_rank of card
	 * 		@param sign - char represents m_sign of card
	 *
	 * 		m_value(sign): 1(A), 2-9(2-9), 10(J), 15(Q), 20(K)
	 */
	void change_card(char rank, char sign);
	/**
	 * Function return the value of card
	 *
	 * Output: int - Cards value
	 * */
	int get_Value()const;
	/**
	 * Function return the Rank of card
	 *
	 * Output: char - Cards Rank
	 * */
	char get_Rank()const;
	/**
	 * Function return the Sign of card
	 *
	 * Output: char - Cards Sign
	 * */
	char get_Sign()const;
	 /**
	  * Destructor
	  * We use primitive members so no action is need
	  */
	~Card();
};

#endif /* CARD_H_ */
