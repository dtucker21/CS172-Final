#pragma once
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Manager
{
public:
	Player playerName;
	Enemy foe;
	Manager();
	~Manager();
};

