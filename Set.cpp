/*
 * Set.cpp
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include "Set.h"
#include "Card.h"
#include "Hand.h"

/**
 * Default Constructor
 *
 * Members:
 * 		vector<Card>* m_set = NULL
 * 		int m_value = -1
 * 		bool m_has_D = false
 * 		bool m_has_H = false
 * 		bool m_has_C = false
 * 		bool m_has_S = false
 */
Set::Set(): m_set(nullptr) {
	m_value = -1;
	m_has_D = false;
	m_has_H = false;
	m_has_C = false;
	m_has_S = false;
}

/**
 * Copy Constructor
 *
 * Members:
 * 		Values will be Like other
 *
 *	@throws std::bad_alloc if memory allocation fails.
 */
Set::Set(const Set &other) {
	m_value = other.m_value;
	m_has_D = other.m_has_D;
	m_has_H = other.m_has_H;
	m_has_C = other.m_has_C;
	m_has_S = other.m_has_S;
	// Check Good Allocation for set
	try{
		this->m_set = new std::vector<Card*>;
	}
	catch (const std::bad_alloc& e) {
		throw std::bad_alloc();
	}
	// Check good allocation for cards
	try{
		for(const auto& card: *(other.m_set)){
			(this->m_set)->push_back(new Card(*card));
		}
	}
	catch (const std::bad_alloc& e) {
		if(this->m_set != nullptr){
			for(auto& card: *(this->m_set)){
				if(card!=nullptr) delete(card);
			}
			this->m_set->clear();
			delete this->m_set;
		}
		throw std::bad_alloc();
	}
}

/**
 * Initial Constructor - Check that every Card Has in hand
 *
 * Members:
 * 		Value will be from cards string
 *
 *	@throws std::bad_alloc if memory allocation fails.
 */
Set::Set(const std::string cards, Hand*& d_hand): Set() {
	if(d_hand == nullptr) throw std::bad_alloc();
	// Split the given string to String Vector
	std::vector<std::string> cards_vector = this->splitString(cards, ' ');

	bool valid_set = false, single_rank = true;
	// Check the set is valid
	bool has_A = false, double_A = false, given_rank = false;
	int temp_value = 0, count_A = 0;
	char set_rank = ' ';
	for(const auto& card_str: cards_vector){
		// Check Card is from the hand
		bool has_card = d_hand->Search_Card(card_str[0], card_str[1]);
		if(!has_card){
			valid_set = false;
			break;
		}
		// Get the rank and check valid set
		char rank = card_str[0];
		switch(rank){
			case 'A':
				// Can be single 'A' to Set or Double A As Set
				count_A++;
				if(!has_A){
					has_A = true;
					valid_set = true;
				}
				else{
					double_A = true;
				}
				if(double_A && set_rank != 'A' && given_rank) valid_set = false;
				if(count_A > 2) valid_set = false;
				break;
			case '2': // Series of Cards between 2-5
			case '3':
			case '4':
			case '5':
				if(!given_rank){
					// First rank given
					given_rank = true;
					set_rank = rank;
					int rank_value = rank-'0';
					temp_value += rank_value;
					valid_set = true;
				}
				else{
					// Rank inserted already
					if(set_rank == rank){
						int rank_value = rank-'0';
						temp_value += rank_value;
					}
					else{ // Double Ranks
						valid_set = false;
						single_rank = false;
						break;
					}
				}
				if(double_A) valid_set = false;
				break;
			case '6': // Above that - Can be single Card
			case '7':
			case '8':
			case '9':
			case 'T':
			case 'J':
			case 'Q':
			case 'K':
				if(!given_rank){
					// First rank given
					valid_set = true;
					given_rank = true;
					single_rank = true;
					set_rank = rank;
				}
				else{
					// Second Card - Invalid Set
					valid_set = false;
					single_rank = false;
				}
				if(double_A) valid_set = false;
				break;
		}
		// Check for value less-equal 10 or invalid rank mix
		if((temp_value > 10) || !single_rank){
			valid_set = false;
			break;
		}
	}

	// Insert the Cards After knowing the Set is valid
	if(valid_set){
		this->m_value = 0;
		// Create array vector
		try{
			this->m_set = new std::vector<Card*>;
		}
		catch (const std::bad_alloc& e) {
			throw std::bad_alloc();
		}
		// Add the Cards
		for(const auto& card_str: cards_vector){
			// Get sign and rank
			char rank = card_str[0], sign = card_str[1];
			// Create new Card
			Card* new_card;
			try{
				new_card = new Card(rank, sign);
			}
			catch (const std::bad_alloc& e) {
				// Delete previous Cards
				for(auto& card: *(this->m_set)){
					if(card!=nullptr) delete(card);
				}
				this->m_set->clear();
				delete this->m_set;
				throw std::bad_alloc();
			}
			// Insert the Card
			if(card_str.size() == 2) this->m_set->push_back(new_card);
			else delete(new_card);
			// Add the value
			this->m_value += new_card->get_Value();
			// Delete the Card from Hand
			bool card_deleted = d_hand->delete_Card(rank, sign);
			if(!card_deleted){
				// Delete previous Cards
				for(auto& card: *(this->m_set)){
					if(card!=nullptr) delete(card);
				}
				this->m_set->clear();
				delete this->m_set;
				throw std::bad_alloc();
			}
			// Change the flags about our signs
			switch(sign){
			case 'C':
				this->m_has_C = true;
				break;
			case 'S':
				this->m_has_S = true;
				break;
			case 'H':
				this->m_has_H = true;
				break;
			case 'D':
				this->m_has_D = true;
				break;
			}
		}
		if(m_has_S && m_has_C){
			this->m_value = this->m_value*2;
		}
	}
	cards_vector.clear();
}

/**
 * Assignment Operator
 *
 * Members:
 * 		Values will be Like other
 */
Set& Set::operator=(const Set& other){
	if(this == &other){
		return *this;
	}
	// Regular members
	m_value = other.m_value;
	m_has_D = other.m_has_D;
	m_has_H = other.m_has_H;
	m_has_C = other.m_has_C;
	m_has_S = other.m_has_S;

	for(auto& card: *(this->m_set)){
		delete(card);
	}
	this->m_set->clear();

	try{
		for(const auto& card: *(other.m_set)){
			(this->m_set)->push_back(new Card(*card));
		}
	}
	catch (const std::bad_alloc& e) {
		if(this->m_set != nullptr){
			// Delete previous Cards
			for(auto& card: *(this->m_set)){
				if(card!=nullptr) delete(card);
			}
			this->m_set->clear();
			delete this->m_set;
		}
		this->m_value = -1;
		return *this;
	}
	return *this;
}

/**
 * Function return if the set is valid
 *
 * Output: bool - True or False is Set is Valid
 * */
bool Set::isValid() const {
	return m_value > 0;
}

/**
 * Function return the value of the set
 *
 * Output: int - set total value
 * */
int Set::getValue() const {
	return m_value;
}

/**
 * Function return m_has_D value
 *
 * Output: bool - m_has_D value
 * */
bool Set::Has_D() const {
	return m_has_D;
}

/**
 * Function return m_has_H value
 *
 * Output: bool - m_has_H value
 * */
bool Set::Has_H() const {
	return m_has_H;
}

/**
 * Function return m_has_C value
 *
 * Output: bool - m_has_C value
 * */
bool Set::Has_C() const {
	return m_has_C;
}

/**
 * Function return m_has_S value
 *
 * Output: bool - m_has_S value
 * */
bool Set::Has_S() const {
	return m_has_S;
}

/**
 * Destructor
 * Delete all the Cards and then delete the Cards-Pointers-Vector
 */
Set::~Set() {
	if(this->m_set != nullptr){
		for(auto& card: *(this->m_set)){
			if(card!=nullptr) delete(card);
		}
		this->m_set->clear();
		delete this->m_set;
	}
}

/**
 * Function Disable S and C Special Power if Was operated
 *
 * */
void Set::Disable_S_And_C(){
	if(m_has_S && m_has_C){
		this->m_value = this->m_value/2;
		this->m_has_C = false;
		this->m_has_S = false;
	}
}

/**
 * Function That Print the Set with '-' Seperate
 *
 * */
void Set::Print() const {
    for (auto it = m_set->begin(); it != m_set->end(); ++it) {
        std::cout << **it; // Print Card
        if (std::next(it) != m_set->end()) {
            std::cout << " - "; // Print Seperate
        }
    }
    std::cout << std::endl;
}


// ####################### Private Functions #######################
// Private function for split String that get in Constructor
std::vector<std::string> Set::splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

