/*
 * Troll.h
 *
 */

#ifndef TROLL_H_
#define TROLL_H_

#include "Enemy.h"

class Troll: public Enemy {
private:
	static const int MAX_HP;
	static const int DAMAGE;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = Troll::MAX_HP
	 * 		int m_MAX_HP = Troll::MAX_HP
	 * 		int m_DAMAGE = Troll::DAMAGE
	 */
	Troll();
	/**
	 * Virtual function that used for fight
	 *
	 * Input:
	 * 		@param Hero& other - other Hero we will attack
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fight(Hero& other, Set*& set);
	/**
	 * Virtual function that used for fight Archer
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightArcher(Set*& set);
	/**
	 * Virtual function that used for fight Warrior
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightWarrior(Set*& set);
	/**
	 * Virtual function that used for fight Wizzard
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightWizzard(Set*& set);
	/**
	 * Destructor
	 * We use primitive members so no action is need
	 */
	virtual ~Troll(){};
};

#endif /* TROLL_H_ */
