/*
 * Archer.h
 *
 */

#ifndef ARCHER_H_
#define ARCHER_H_

class Enemy;
#include "Hero.h"

class Archer: public Hero {
private:
	static const int MAX_HP;
	static const int CARDS_NUM;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = Archer::MAX_HP
	 * 		int m_MAX_HP = Archer::MAX_HP
	 * 		int m_DAMAGE = Archer::CARDS_NUM
	 */
	Archer();
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
	 * 		@param Enemy& other - The enemy that Attack
	 * */
	virtual void fightDragon(Set*& set, Enemy& other);
	/**
	 * Virtual function that used for fight Ghost
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * 		@param Enemy& other - The enemy that Attack
	 * */
	virtual void fightGhost(Set*& set, Enemy& other);
	/**
	 * Virtual function that used for fight Troll
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * 		@param Enemy& other - The enemy that Attack
	 * */
	virtual void fightTroll(Set*& set, Enemy& other);
	/**
	 * Destructor
	 * We use primitive members so no action is need
	 */
	virtual ~Archer(){};
};

#endif /* ARCHER_H_ */
