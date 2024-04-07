/*
 * Enemy.h
 *
 */

#ifndef ENEMY_H_
#define ENEMY_H_

class Set;
class Hero;
#include "Character.h"

class Enemy: public Character {
protected:
	// int m_DAMAGE = Damage amount enemy give
	int m_DAMAGE;
public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = -1
	 * 		int m_MAX_HP = -1
	 * 		int m_DAMAGE = -1
	 */
	Enemy();
	/**
	 * Regular Constructor
	 *
	 * Input:
	 * 		@param hp - m_hp value
	 * 		@param damage - Damage amount enemy give
	 */
	Enemy(int hp, int damage);
	/**
	 * Destructor
	 * We use primitive members so no action is need
	 */
	virtual ~Enemy(){};
	/**
	 * Function that help to know the damage of the Enemy
	 *
	 * Output: int - Damage amount enemy give
	 * */
	int Get_Damage_Num();
	/**
	 * Pure Virtual function that used for fight
	 *
	 * Input:
	 * 		@param Hero& other - other Hero we will attack
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fight(Hero& other, Set*& set) = 0;
	/**
	 * Pure Virtual function that used for fight Archer
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightArcher(Set*& set) = 0;
	/**
	 * Pure Virtual function that used for fight Warrior
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightWarrior(Set*& set) = 0;
	/**
	 * Pure Virtual function that used for fight Wizzard
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fightWizzard(Set*& set) = 0;
	/**
	 * Function that decrease the hp of the Character - Override
	 *
	 * Input:
	 * 		@param int hp - hp to decrease
	 * */
	virtual void DecreaseHP(int hp);
};

#endif /* ENEMY_H_ */
