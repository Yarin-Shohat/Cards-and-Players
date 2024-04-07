/*
 * Dragon.h
 *
 */

#ifndef DRAGON_H_
#define DRAGON_H_

#include "Enemy.h"

class Dragon: public Enemy {
private:
	static const int MAX_HP;
	static const int DAMAGE;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = Dragon::MAX_HP
	 * 		int m_MAX_HP = Dragon::MAX_HP
	 * 		int m_DAMAGE = Dragon::DAMAGE
	 */
	Dragon();
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
	virtual ~Dragon(){};
};

#endif /* DRAGON_H_ */
