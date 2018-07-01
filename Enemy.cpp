#include "stdafx.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int taunt(int a)
{
	a = 4;
	return a;
}

void crush()
{
	
}

int Enemy::enemyAction()
{
	action = 0;
	srand(time(NULL));
	if (action != 3)
	{
		action = rand() % 3;
		return action;
	}
	else
	{
		action = 4;
		return action;
	}
}

Enemy::Enemy()
{
	srand(time(NULL));
	int healthMod = rand() % 4 + 1;
	maxHealth = healthMod * 10;
	health = maxHealth;
}


Enemy::~Enemy()
{
}
