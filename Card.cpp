/*
 * Card.cpp
 *
 */
#include <iostream>
#include "Card.h"

// ####################### Private Functions #######################
/**
 * Private Function that check if rank is valid rank
 *
 * Input:
 * 		@param rank - rank of card
 *
 * Output:
 * 		boolean - True if the rank is valid, Else False
 * */
bool Card::check_rank_is_valid(char rank) const{
	return ((rank >= '2') && (rank <= '9')) || (rank == 'T') || (rank == 'J') || (rank == 'Q') || (rank == 'K') || (rank == 'A');
}
/**
 * Private Function that check if sign is valid rank
 *
 * Input:
 * 		@param sign - sign of card
 *
 * Output:
 * 		boolean - True if the sign is valid, Else False
 * */
bool Card::check_sign_is_valid(char sign) const{
	return (sign == 'C') || (sign == 'S') || (sign == 'H') || (sign == 'D');
}
/**
 * Private Function return value for sign for comparing functions
 *
 * Output: int - int value for signs
 * */
int Card::get_sign_value() const{
	switch(this->m_sign){
	case 'C':
		return 4;
	case 'S':
		return 3;
	case 'H':
		return 2;
	case 'D':
		return 1;
	}
	return 0;
}

void Card::set_value(char rank){
	switch(rank){
		case 'A':
			this->m_value = 1;
			break;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			this->m_value = rank - '0';
			break;
		case 'T':
		case 'J':
			this->m_value = 10;
			break;
		case 'Q':
			this->m_value = 15;
			break;
		case 'K':
			this->m_value = 20;
			break;
	}
}

// ####################### Public Functions #######################

/**
 * Default Constructor
 *
 * Members:
 * 		char m_rank = '\0'
 * 		char m_sign = '\0'
 * 		int m_value = 0
 */
Card::Card(): m_rank('\0'),  m_sign('\0'), m_value(0){

}

/**
 * Regular Constructor
 *
 * Input:
 * 		@param rank - char represents m_rank of card
 * 		@param sign - char represents m_sign of card
 *
 * 		m_value(sign): 1(A), 2-9(2-9), 10(J), 15(Q), 20(K)
 */
Card::Card(char rank, char sign){
	// Check for null input
	bool input_not_null = (rank != '\0') && (sign != '\0');
	if(input_not_null){
		// Check for valid rank and sign
		bool rank_is_valid = check_rank_is_valid(rank);
		bool sign_is_valid = check_sign_is_valid(sign);
		// Get the value of card
		if(rank_is_valid && sign_is_valid){
			this->m_rank = rank;
			this->m_sign = sign;
			this->set_value(rank);
		}
	}
	else{
		// If input is null or not valid, use null values(was H file)
		this->m_value = 0;
	}
}

/**
 * Copy Constructor - members will be like other
 *
 * Input:
 * 		@param otherCard - other object of Card, values will be copy from that object
 * */
Card::Card(const Card& otherCard){
	this->m_rank = otherCard.m_rank;
	this->m_sign = otherCard.m_sign;
	this->m_value = otherCard.m_value;
}

/**
 * Function for Assignment operator '=' - used to assign Card to be other Card
 * Copy the Values of other Card to this Card the return this Card
 *
 * Input:
 * 		@param other - other object of Card, values will be copy from that object
 * */
Card& Card::operator=(const Card& other){
	if(this != &other){
		this->m_rank = other.m_rank;
		this->m_sign = other.m_sign;
		this->m_value = other.m_value;
	}
	return *this;
}

/**
 * Function for Compare operator '=='
 * Check if two Cards are equals
 *
 * Input:
 * 		@param other - other object of Card
 *
 * Output: bool - True if equal, Else False
 * */
bool Card::operator==(const Card& other) const{
	if(this == &other) return true;
	if((this->m_rank == other.m_rank) && (this->m_sign == other.m_sign) && (this->m_value == other.m_value)) return true;
	return false;
}

/**
 * Function for Compare operator '!='
 * Check if two Cards are not equals
 *
 * Input:
 * 		@param other - other object of Card
 *
 * Output: bool - True if not equal, Else False
 * */
bool Card::operator!=(const Card& other) const{
	bool is_equal = (*this == other);
	return !is_equal;
}

/**
 * Function for Compare operator '<='
 * Check if this Card is less/equal then other
 *
 * Input:
 * 		@param other - other object of Card
 *
 * Output: bool - True if less/equal, Else False
 * */
bool Card::operator<=(const Card& other) const{
	// If we compare the same objects
	if(*this == other) return true;
	// Check if this.value == other.value
	if(this->m_value == other.m_value){
		// If Cards has the same rank - the sign is determine
		if(this->m_rank == other.m_rank){
			return this->get_sign_value() <= other.get_sign_value();
		}
		// Cards are 10 and Prince Card - Check that
		// this is J and other is 10 - this is greater
		if((this->m_rank == 'J') && (other.m_rank=='T')) return false;
		// this is 10 and other is J - other is greater
		if((other.m_rank == 'J') && (this->m_rank=='T')) return true;
	}
	return this->m_value < other.m_value;
}

/**
 * Function for Compare operator '>='
 * Check if this Card is greater/equal then other
 *
 * Input:
 * 		@param other - other object of Card
 *
 * Output: bool - True if greater/equal, Else False
 * */
bool Card::operator>=(const Card& other) const{
	// If we compare the same objects
	if(*this == other) return true;
	// Check if this.value == other.value
	if(this->m_value == other.m_value){
		// If Cards has the same rank - the sign is determine
		if(this->m_rank == other.m_rank){
			return this->get_sign_value() >= other.get_sign_value();
		}
		// Cards are 10 and Prince Card - Check that
		// this is J and other is 10 - this is greater
		if((this->m_rank == 'J') && (other.m_rank=='T')) return true;
		// this is 10 and other is J - other is greater
		if((other.m_rank == 'J') && (this->m_rank=='T')) return false;
	}
	return this->m_value > other.m_value;
}

/**
 * Function for Compare operator '<'
 * Check if this Card is less then other
 *
 * Input:
 * 		@param other - other object of Card
 *
 * Output: bool - True if smaller, Else False
 * */
bool Card::operator<(const Card& other) const{
	bool equal_greater = (*this >= other);
	return !equal_greater;
}

/**
 * Function for Compare operator '<'
 * Check if this Card is greater then other
 *
 * Input:
 * 		@param other - other object of Card
 *
 * Output: bool - True if greater, Else False
 * */
bool Card::operator>(const Card& other) const{
	bool less_equal = (*this <= other);
	return !less_equal;
}

/**
 * Function for operator '<<' - used for printing Card
 *
 * Input:
 * 		@param c_card - card we will print
 * */
std::ostream& operator<<(std::ostream& output, const Card& c_card){
	output << c_card.m_rank << c_card.m_sign;
	return output;
}

/**
 * Function that check if this card is empty card
 *
 * Output: bool - True if its empty card, Else False
 * */
bool Card::is_empty_card() const{
	if(this->m_value == 0) return true;
	return false;
}

/**
 * Function that change the card members
 *
 * Input:
 * 		@param rank - char represents m_rank of card
 * 		@param sign - char represents m_sign of card
 *
 * 		m_value(sign): 1(A), 2-9(2-9), 10(J), 15(Q), 20(K)
 */
void Card::change_card(char rank, char sign){
	this->m_rank = rank;
	this->m_sign = sign;
	this->set_value(rank);
}

/**
 * Function return the value of card
 *
 * Output: int - Cards value
 * */
int Card::get_Value()const{
	return this->m_value;
}

/**
 * Function return the Rank of card
 *
 * Output: char - Cards Rank
 * */
char Card::get_Rank()const{
	return this->m_rank;
}

/**
 * Function return the Sign of card
 *
 * Output: char - Cards Sign
 * */
char Card::get_Sign()const{
	return this->m_sign;
}

 /**
  * Destructor
  * We use primitive members so no action is need
  */
Card::~Card(){
	// We use primitive members
}

