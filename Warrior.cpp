/*
 * Warrior.cpp
 *
 */

#include "Warrior.h"
#include "Enemy.h"
#include "Set.h"
#include <iostream>

const int Warrior::MAX_HP = 60;
const int Warrior::CARDS_NUM = 6;

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = Warrior::MAX_HP
 * 		int m_MAX_HP = Warrior::MAX_HP
 * 		int m_DAMAGE = Warrior::CARDS_NUM
 */
Warrior::Warrior(): Hero(Warrior::MAX_HP, Warrior::CARDS_NUM){}

/**
 * Virtual function that used for fight
 *
 * Input:
 * 		@param Character& other - other Character we will attack
 * 		@param Set& set - The Set we will Attack with
 * */
void Warrior::fight(Enemy& other, Set*& set){
	if(set == nullptr) return;
	other.fightWarrior(set);
}

/**
 * Virtual function that used for fight Dragon
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * 		@param Enemy& other - The enemy that Attack
 * */
void Warrior::fightDragon(Set*& set, Enemy& other){
	if(set == nullptr) return;
	//	NO D
	// Gain HP for Player
	if(set->Has_H()) this->IncreaseHP(set->getValue());
	// Get Damage to Player
	int damage = other.Get_Damage_Num();
	this->DecreaseHP(damage);
}

/**
 * Virtual function that used for fight Ghost
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * 		@param Enemy& other - The enemy that Attack
 * */
void Warrior::fightGhost(Set*& set, Enemy& other){
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
 * Virtual function that used for fight Troll
 *
 * Input:
 * 		@param Set& set - The Set we will Attack with
 * 		@param Enemy& other - The enemy that Attack
 * */
void Warrior::fightTroll(Set*& set, Enemy& other){
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
