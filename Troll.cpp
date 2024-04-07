/*
 * Troll.cpp
 *
 */

#include "Hero.h"
#include "Troll.h"
#include "Set.h"
#include <iostream>

const int Troll::MAX_HP = 100;
const int Troll::DAMAGE = 5;

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = Troll::MAX_HP
 * 		int m_MAX_HP = Troll::MAX_HP
 * 		int m_DAMAGE = Troll::DAMAGE
 */
Troll::Troll(): Enemy(Troll::MAX_HP, Troll::DAMAGE){}

/**
 * Virtual function that used for fight
 *
 * Input:
 * 		@param Hero& other - other Hero we will attack
 * 		@param Set& set - The Set we will Attack with
 * */
void Troll::fight(Hero& other, Set*& set){
	if(set == nullptr) return;
	other.fightTroll(set, *this);
}

/**
 * Virtual function that used for fight Archer
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Troll::fightArcher(Set*& set){
	if(set == nullptr) return;
	//	NO C&S
	set->Disable_S_And_C();
	this->DecreaseHP(set->getValue());
}

/**
 * Virtual function that used for fight Warrior
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Troll::fightWarrior(Set*& set){
	if(set == nullptr) return;
	// NO H
	this->DecreaseHP(set->getValue());
}

/**
 * Virtual function that used for fight Wizzard
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Troll::fightWizzard(Set*& set){
	if(set == nullptr) return;
	//	NO D
	this->DecreaseHP(set->getValue());
}


