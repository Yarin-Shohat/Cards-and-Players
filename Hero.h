/*
 * Hero.h
 *
 */

#ifndef HERO_H_
#define HERO_H_

class Set;
class Enemy;
#include "Character.h"

class Hero: public Character {
protected:
	// int CARDS_NUM = Character Max Cards Number
	int m_CARDS_NUM;

public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_hp = -1
	 * 		int m_MAX_HP = -1
	 * 		int m_CARDS_NUM = -1
	 */
	Hero();
	/**
	 * Regular Constructor
	 *
	 * Input:
	 * 		@param hp - m_hp value
	 * 		@param cards - Number of cards in hand
	 */
	Hero(int hp, int cards);
	/**
	 * Destructor
	 * We use primitive members so no action is need
	 */
	virtual ~Hero(){};
	/**
	 * Function that help to know how many cards hero has in hand
	 *
	 * Output: int - CARDS_NUM the Hero
	 * */
	int Get_Cards_Num();
	/**
	 * Pure Virtual function that used for fight
	 *
	 * Input:
	 * 		@param Enemy& other - other Enemy we will attack
	 * 		@param Set& set - The Set we will Attack with
	 * */
	virtual void fight(Enemy& other, Set*& set) = 0;
	/**
	 * Pure Virtual function that used for fight Dragon
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * 		@param Enemy& other - The enemy that Attack
	 * */
	virtual void fightDragon(Set*& set, Enemy& other) = 0;
	/**
	 * Pure Virtual function that used for fight Ghost
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * 		@param Enemy& other - The enemy that Attack
	 * */
	virtual void fightGhost(Set*& set, Enemy& other) = 0;
	/**
	 * Pure Virtual function that used for fight Troll
	 *
	 * Input:
	 * 		@param Set& set - The Set we will Attack with
	 * 		@param Enemy& other - The enemy that Attack
	 * */
	virtual void fightTroll(Set*& set, Enemy& other) = 0;
	/**
	 * Function that decrease the hp of the Character - Override
	 *
	 * Input:
	 * 		@param int hp - hp to decrease
	 * */
	virtual void DecreaseHP(int hp);
	/**
	 * Function that increase the hp of the Character - Override
	 *
	 * Input:
	 * 		@param int hp - hp to increase
	 * */
	virtual void IncreaseHP(int hp);
};

#endif /* HERO_H_ */
