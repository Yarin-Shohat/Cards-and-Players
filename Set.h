/*
 * Set.h
 *
 */

#ifndef SET_H_
#define SET_H_

#include <vector>
#include <string>
#include "Hand.h"

class Set {
private:
	// m_set = Cards Array - The Set
	std::vector<Card*>* m_set;
	// m_value = Value of the set
	int m_value;
	// m_has_D = if the set has that sign
	bool m_has_D;
	// m_has_H = if the set has that sign
	bool m_has_H;
	// m_has_C = if the set has that sign
	bool m_has_C;
	// m_has_S = if the set has that sign
	bool m_has_S;

	// Private function for split String that get in Constructor
	std::vector<std::string> splitString(const std::string& s, char delimiter);
public:
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
	Set();
	/**
	 * Copy Constructor
	 *
	 * Members:
	 * 		Values will be Like other
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 */
	Set(const Set& other);
	/**
	 * Initial Constructor - Check that every Card Has in hand
	 *
	 * Members:
	 * 		Value will be from cards string
	 *
	 *	@throws std::bad_alloc if memory allocation fails.
	 */
	Set(const std::string cards, Hand*& d_hand);
	/**
	 * Assignment Operator
	 *
	 * Members:
	 * 		Values will be Like other
	 */
	Set& operator=(const Set& other);
	/**
	 * Function return if the set is valid
	 *
	 * Output: bool - True or False is Set is Valid
	 * */
	bool isValid()const;
	/**
	 * Function return the value of the set
	 *
	 * Output: int - set total value
	 * */
	int getValue()const;
	/**
	 * Function return m_has_D value
	 *
	 * Output: bool - m_has_D value
	 * */
	bool Has_D()const;
	/**
	 * Function return m_has_H value
	 *
	 * Output: bool - m_has_H value
	 * */
	bool Has_H()const;
	/**
	 * Function return m_has_C value
	 *
	 * Output: bool - m_has_C value
	 * */
	bool Has_C()const;
	/**
	 * Function return m_has_S value
	 *
	 * Output: bool - m_has_S value
	 * */
	bool Has_S()const;
	/**
	 * Function Disable S and C Special Power if Was operated
	 *
	 * */
	void Disable_S_And_C();
	/**
	 * Destructor
	 * Delete all the Cards and then delete the Cards-Pointers-Vector
	 */
	~Set();
	/**
	 * Function That Print the Set with '-' Seperate
	 *
	 * */
	void Print()const;
};

#endif /* SET_H_ */
