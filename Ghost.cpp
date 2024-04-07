/*
 * Ghost.cpp
 *
 */

#include "Hero.h"
#include "Ghost.h"
#include "Set.h"
#include <iostream>

const int Ghost::MAX_HP = 50;
const int Ghost::DAMAGE = 15;

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = Ghost::MAX_HP
 * 		int m_MAX_HP = Ghost::MAX_HP
 * 		int m_DAMAGE = Ghost::DAMAGE
 */
Ghost::Ghost(): Enemy(Ghost::MAX_HP, Ghost::DAMAGE){}

/**
 * Virtual function that used for fight
 *
 * Input:
 * 		@param Hero& other - other Hero we will attack
 * 		@param Set& set - The Set we will Attack with
 * */
void Ghost::fight(Hero& other, Set*& set){
	if(set == nullptr) return;
	other.fightGhost(set, *this);
}

/**
 * Virtual function that used for fight Archer
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Ghost::fightArcher(Set*& set){
	if(set == nullptr) return;
	// NO D
	this->DecreaseHP(set->getValue());
}

/**
 * Virtual function that used for fight Warrior
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Ghost::fightWarrior(Set*& set){
	if(set == nullptr) return;
	// NO C&S
	set->Disable_S_And_C();
	this->DecreaseHP(set->getValue());
}

/**
 * Virtual function that used for fight Wizzard
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Ghost::fightWizzard(Set*& set){
	if(set == nullptr) return;
	// NO H
	this->DecreaseHP(set->getValue());
}


