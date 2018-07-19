#pragma once
#include <string>
using namespace std;

class Player
{
private:
	int maxHealth;
public:
	string name;
	int skill1;
	int skill2;
	int health;
	int damage;
	void pickSkill1();
	void pickSkill2();
	int playerAction();
	int action;
	Player(string name);
	Player();
	~Player();
};

