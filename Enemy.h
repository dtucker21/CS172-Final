#pragma once
class Enemy
{
private:
	int maxHealth;
public:
	int damage;
	int health;
	int action;
	int taunt(int a);
	void crush();
	int enemyAction();
	Enemy();
	~Enemy();
};

