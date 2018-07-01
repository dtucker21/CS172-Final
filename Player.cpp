#include "stdafx.h"
#include "Player.h"
#include <iostream>

using namespace std;

void Player::pickSkill1()
{
	int pick = 0;
	cout << "Pick one of the following skills:\n1) Fireball; an offensive spell with no extra effects\n2) Freeze; a defensive spell that deals minor damage and will stun the enemy\n 3) Lightning Bolt; a balanced spell that will deal moderate damage with a chance to stun the enemy" << endl;
	while (pick > 3 || pick < 1)
	{
		cout << "Your choice is: ";
		cin >> pick;
		if (pick < 3 && pick > 1)
		{
			skill1 = pick;
		}
		else
		{
			cout << "Please enter a valid skill tag (1, 2, or 3)" << endl;
		}
	}
}

void Player::pickSkill2()
{
	int pick = 0;
	cout << "Pick one of the following skills:\n1) Perfect Block; you take no damage this turn\n2) Counter; block some incoming damage but also attack in return\n3) DoubleStrike; attack twice, dealing double regular attack damage" << endl;
	while (pick < 1 || pick > 3)
	{
		cout << "Your choice is: ";
		cin >> pick;
		if (pick < 3 && pick > 1)
		{
			skill2 = pick;
		}
		else
		{
			cout << "Please enter a valid skill tag (1, 2, or 3)" << endl;
		}
	}
}

int Player::playerAction()
{
	action = 0;
	cout << "What do you do?" << endl;
	cout << "1) Attack\n";
	if (skill1 == 1)
	{//fireball
		cout << "2) Fireball\n";
	}
	else if (skill1 == 2)
	{//freeze
		cout << "2) Freeze\n";
	}
	else if (skill1 == 3)
	{//lightning
		cout << "2) Lightning Bolt\n";
	}
	if (skill2 == 1)
	{//Perfect Block
		cout << "3) Perfect Block\n";
	}
	else if (skill2 == 2)
	{//Counter Block
		cout << "3) Counter\n";
	}
	else if (skill2 == 3)
	{//Doublestrike
		cout << "3) Doublestrike\n";
	}
	cout << "4) Heal\n";
	cout << "? ";
	cin >> action;
	return action;
}

Player::Player(string name)
{
	this->name = name;
	maxHealth = 25;
	health = maxHealth;
	Player::pickSkill1();
	Player::pickSkill2();
}

Player::Player()
{
	name = "Boris";
	maxHealth = 25;
	Player::pickSkill1();
	Player::pickSkill2();
}

Player::~Player()
{
}
