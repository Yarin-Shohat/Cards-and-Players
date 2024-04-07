/*
 * Archer.cpp
 *
 */

#include "Archer.h"
#include "Enemy.h"
#include "Set.h"
#include <iostream>

const int Archer::MAX_HP = 50;
const int Archer::CARDS_NUM = 7;

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = Archer::MAX_HP
 * 		int m_MAX_HP = Archer::MAX_HP
 * 		int m_DAMAGE = Archer::CARDS_NUM
 */
Archer::Archer() :
		Hero(Archer::MAX_HP, Archer::CARDS_NUM) {
}

/**
 * Virtual function that used for fight
 *
 * Input:
 * 		@param Character& other - other Character we will attack
 * 		@param Set& set - The Set we will Attack with
 * */
void Archer::fight(Enemy& other, Set*& set){
	if(set != nullptr) other.fightArcher(set);
}

/**
 * Virtual function that used for fight Dragon
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * 		@param Enemy& other - The enemy that Attack
 * */
void Archer::fightDragon(Set*& set, Enemy& other){
	if(set == nullptr) return;
	// NO H
	// Get Damage to Player
	int damage;
	if(set->Has_D()){
		damage = std::max(0, other.Get_Damage_Num() - (set->getValue()));
	}
	else{
		damage = other.Get_Damage_Num();
	}
	this->DecreaseHP(damage);
}

/**
 * Virtual function that used for fight Ghost
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * 		@param Enemy& other - The enemy that Attack
 * */
void Archer::fightGhost(Set*& set, Enemy& other){
	if(set == nullptr) return;
	//	NO D
	// Gain HP for Player
	if(set->Has_H()) this->IncreaseHP(set->getValue());
	// Get Damage to Player
	int damage = other.Get_Damage_Num();
	this->DecreaseHP(damage);
}

/**
 * Virtual function that used for fight Troll
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * 		@param Enemy& other - The enemy that Attack
 * */
void Archer::fightTroll(Set*& set, Enemy& other){
	if(set == nullptr) return;
	//	NO C&S
	// Gain HP for Player
	if(set->Has_H()) this->IncreaseHP(set->getValue());
	// Get Damage to Player
	int damage;
	if(set->Has_D()){
		damage = std::max(0, other.Get_Damage_Num() - set->getValue());
	}
	else{
		damage = other.Get_Damage_Num();
	}
	this->DecreaseHP(damage);
}
