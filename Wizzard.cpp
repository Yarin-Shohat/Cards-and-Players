/*
 * Wizzard.cpp
 *
 */
#include "Set.h"
#include <iostream>
#include "Enemy.h"
#include "Wizzard.h"

const int Wizzard::MAX_HP = 40;
const int Wizzard::CARDS_NUM = 8;

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = Wizzard::MAX_HP
 * 		int m_MAX_HP = Wizzard::MAX_HP
 * 		int m_DAMAGE = Wizzard::CARDS_NUM
 */
Wizzard::Wizzard(): Hero(Wizzard::MAX_HP, Wizzard::CARDS_NUM) {}

/**
 * Virtual function that used for fight
 *
 * Input:
 * 		@param Character& other - other Character we will attack
 * 		@param Set& set - The Set we will Attack with
 * */
void Wizzard::fight(Enemy& other, Set*& set){
	if(set == nullptr) return;
	other.fightWizzard(set);
}


/**
 * Virtual function that used for fight Dragon
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Wizzard::fightDragon(Set*& set, Enemy& other){
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

/**
 * Virtual function that used for fight Ghost
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Wizzard::fightGhost(Set*& set, Enemy& other){
	if(set == nullptr) return;
	// NO H
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

/**
 * Virtual function that used for fight Troll
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * */
void Wizzard::fightTroll(Set*& set, Enemy& other){
	if(set == nullptr) return;
	//	NO D
	// Gain HP for Player
	if(set->Has_H()) this->IncreaseHP(set->getValue());
	// Get Damage to Player
	int damage = other.Get_Damage_Num();
	this->DecreaseHP(damage);
}




