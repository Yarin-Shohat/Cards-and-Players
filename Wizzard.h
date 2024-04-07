/*
 * Wizzard.h
 *
 */

#ifndef WIZZARD_H_
#define WIZZARD_H_

class Enemy;
#include "Hero.h"

class Wizzard : public Hero {
private:
	static const int MAX_HP;
	static const int CARDS_NUM;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = Wizzard::MAX_HP
	 * 		int m_MAX_HP = Wizzard::MAX_HP
	 * 		int m_DAMAGE = Wizzard::CARDS_NUM
	 */
	Wizzard();
	/**
	 * Virtual function that used for fight
	 *
	 * Input:
	 * 		@param Character& other - other Character we will attack
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fight(Enemy& other, Set*& set);
	/**
	 * Virtual function that used for fight Dragon
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightDragon(Set*& set, Enemy& other);
	/**
	 * Virtual function that used for fight Ghost
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightGhost(Set*& set, Enemy& other);
	/**
	 * Virtual function that used for fight Troll
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightTroll(Set*& set, Enemy& other);
	/**
	 * Destructor
	 * We use primitive members so no action is need
	 */
	virtual ~Wizzard(){};
};

#endif /* WIZZARD_H_ */
