/*
 * Enemy.cpp
 *
 */

#include "Enemy.h"
#include <iostream>

/**
 * Default Constructor
 *
 * Members:
 * 		int m_hp = -1
 * 		int m_MAX_HP = -1
 * 		int m_DAMAGE = -1
 */
Enemy::Enemy(): Character() {
	this->m_DAMAGE = -1;
}

/**
 * Regular Constructor
 *
 * Input:
 * 		@param hp - m_hp value
 * 		@param damage - Damage amount enemy give
 */
Enemy::Enemy(int hp, int damage): Character(hp) {
	this->m_DAMAGE = damage;
}

/**
 * Function that help to know the damage of the Enemy
 *
 * Output: int - Damage amount enemy give
 * */
int Enemy::Get_Damage_Num(){
	return this->m_DAMAGE;
}

/**
 * Function that decrease the hp of the Character - Override
 *
 * Input:
 * 		@param int hp - hp to decrease
 * */
void Enemy::DecreaseHP(int hp){
	int new_hp = this->m_hp - hp;
	if(new_hp <= 0){
		this->m_hp = 0;
	}else{
		this->m_hp = new_hp;
	}
	std::cout << "Player dealt " << hp << " points of damage\n";
}
