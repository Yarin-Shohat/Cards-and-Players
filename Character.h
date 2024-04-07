/*
 * Character.h
 *
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character {
protected:
	// int MAX_HP = Character Max Heart-Points
	int m_MAX_HP;
	// int m_hp = Character Heart-Points
	int m_hp;

public:
	/**
	 * Default Constructor
	 *
	 * Members:
	 * 		int m_MAX_HP = -1
	 * 		int m_hp = -1
	 */
	Character();
	/**
	 * Regular Constructor
	 *
	 * Input:
	 * 		@param hp - m_hp and MAX_HP value
	 */
	Character(int hp);
	/**
	 * Destructor
	 * We use primitive members so no action is need
	 */
	virtual ~Character(){};
	/**
	 * Function that help to know the hp of the Character
	 *
	 * Output: int - m_hp of the Character
	 * */
	int GetHp()const;
	/**
	 * Function that decrease the hp of the Character
	 *
	 * Input:
	 * 		@param int hp - hp to decrease
	 * */
	virtual void DecreaseHP(int hp);
	/**
	 * Function that increase the hp of the Character
	 *
	 * Input:
	 * 		@param int hp - hp to increase
	 * */
	virtual void IncreaseHP(int hp);
};

#endif /* CHARACTER_H_ */
