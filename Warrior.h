/*
 * Warrior.h
 *
 */

#ifndef WARRIOR_H_
#define WARRIOR_H_

class Enemy;
#include "Hero.h"

class Warrior: public Hero {
private:
	static const int MAX_HP;
	static const int CARDS_NUM;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = Warrior::MAX_HP
	 * 		int m_MAX_HP = Warrior::MAX_HP
	 * 		int m_DAMAGE = Warrior::CARDS_NUM
	 */
	Warrior();
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
	virtual ~Warrior(){};
};

#endif /* WARRIOR_H_ */
