/*
 * Hero.cpp
 *
 */

#include "Hero.h"
#include <iostream>

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = -1
 * 		int m_MAX_HP = -1
 * 		int m_CARDS_NUM = -1
 */
Hero::Hero(): Character(){
	this->m_CARDS_NUM = -1;
}

/**
 * Regular Constructor
 *
 * Input:
 * 		@param hp - m_hp value
 * 		@param cards - Number of cards in hand
 */
Hero::Hero(int hp, int cards): Character(hp){
	this->m_CARDS_NUM = cards;
}

/**
 * Function that help to know how many cards hero has in hand
 *
 * Output: int - CARDS_NUM the Hero
 * */
int Hero::Get_Cards_Num(){
	return this->m_CARDS_NUM;
}

/**
 * Function that decrease the hp of the Character - Override
 *
 * Input:
 * 		@param int hp - hp to decrease
 * */
void Hero::DecreaseHP(int hp){
	int new_hp = this->m_hp - hp;
	if(new_hp <= 0){
		this->m_hp = 0;
	}else{
		this->m_hp = new_hp;
	}
	std::cout << "Player took " << hp << " points of damage\n";
}


/**
 * Function that increase the hp of the Character - Override
 *
 * Input:
 * 		@param int hp - hp to increase
 * */
void Hero::IncreaseHP(int hp){
	int old_hp = this->m_hp;
	int new_hp = this->m_hp + hp;
	this->m_hp = std::min(this->m_MAX_HP, new_hp);
	int gained_hp = this->m_hp - old_hp;
	if(gained_hp > 0) std::cout << "Player healed " << gained_hp << " points of damage\n";
}
