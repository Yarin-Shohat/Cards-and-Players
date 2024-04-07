/*
 * Dragon.cpp
 *
 */

#include "Hero.h"
#include "Dragon.h"
#include "Set.h"
#include <iostream>

const int Dragon::MAX_HP = 75;
const int Dragon::DAMAGE = 10;

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = Dragon::MAX_HP
 * 		int m_MAX_HP = Dragon::MAX_HP
 * 		int m_DAMAGE = Dragon::DAMAGE
 */
Dragon::Dragon(): Enemy(Dragon::MAX_HP, Dragon::DAMAGE){}

/**
 * Virtual function that used for fight
 *
 * Input:
 * 		@param Hero& other - other Hero we will attack
 * 		@param Set& set - The Set we will Attack with
 * */
void Dragon::fight(Hero& other, Set*& set){
	if(set == nullptr) return;
	other.fightDragon(set, *this);
}

/**
 * Virtual function that used for fight Archer
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Dragon::fightArcher(Set*& set){
	if(set == nullptr) return;
	// NO H
	this->DecreaseHP(set->getValue());
}

/**
 * Virtual function that used for fight Warrior
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Dragon::fightWarrior(Set*& set){
	if(set == nullptr) return;
	// NO D
	this->DecreaseHP(set->getValue());
}

/**
 * Virtual function that used for fight Wizzard
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Dragon::fightWizzard(Set*& set){
	if(set == nullptr) return;
	// NO C&S
	set->Disable_S_And_C();
	this->DecreaseHP(set->getValue());
}


