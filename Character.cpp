/*
 * Character.cpp
 *
 */

#include "Character.h"
#include <iostream>

	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_MAX_HP = -1
	 * 		int m_hp = -1
	 */
Character::Character() {
	this->m_hp = -1;
	this->m_MAX_HP = -1;
}

/**
 * Regular Constructor
 *
 * Input:
 * 		@param hp - m_hp and MAX_HP value
 */
Character::Character(int hp) {
	this->m_hp = hp;
	this->m_MAX_HP = hp;
}

/**
 * Function that help to know the hp of the Character
 *
 * Output: int - m_hp of the Character
 * */
int Character::GetHp()const{
	return this->m_hp;
}

/**
 * Function that decrease the hp of the Character
 *
 * Input:
 * 		@param int hp - hp to decrease
 * */
void Character::DecreaseHP(int hp){
	int new_hp = this->m_hp - hp;
	if(new_hp <= 0){
		this->m_hp = 0;
	}else{
		this->m_hp = new_hp;
	}
}

/**
 * Function that increase the hp of the Character
 *
 * Input:
 * 		@param int hp - hp to increase
 * */
void Character::IncreaseHP(int hp){
	int new_hp = this->m_hp + hp;
	if(new_hp >= this->m_MAX_HP){
		this->m_hp = this->m_MAX_HP;
	}else{
		this->m_hp = new_hp;
	}
}
