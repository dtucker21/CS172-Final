// Final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Manager.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void resolve(Player* p, Enemy* e, int PA, int EA);

int main()
{
	string name;
	cout << "Your name is: ";
	cin >> name;
	Player* p = NULL;
	Enemy* e = NULL;
	p = new Player(name);
	e = new Enemy();
	cout << p->name << ", enter the arena. Succeed, and you will find many riches that await you." << endl;
	cout << "You walk into the arena. The sun shines brightly, and the crowd roars with anticipation." << endl;
	cout << "Combat begins" << endl;
	while (p->health > 0 && e->health > 0)
	{
		int PA = 0;
		int EA = 0;
		PA = p->playerAction();
		EA = e->enemyAction();
		resolve(p, e, PA, EA);
	}
    return 0;
}

void resolve(Player *p, Enemy *e, int PA, int EA)
{
	if (PA == 1)
	{//player basic attack
		if (EA == 1)
		{//enemy basic attack
			cout << "You deal 3 damage to the enemy. The enemy deals 3 damage to you." << endl;
			p->health -= 3;
			e->health -= 3;
		}
		else if (EA == 2)
		{//enemy block
			cout << "The enemy blocks your attack. You deal 1 damage to the enemy." << endl;
			e->health -= 1;
		}
		else if (EA == 3)
		{//enemy taunt
			cout << "The enemy yells 'Yer dead if I getcha with this!'. You deal 3 damage to the enemy." << endl;
			e->health -= 3;
		}
		else if (EA == 4)
		{//enemy crush
			cout << "The enemy attacks violently, dealing 6 damage. You deal 3 damage to the enemy." << endl;
			p->health -= 6;
			e->health -= 3;
		}
	}
	else if (PA == 2)
	{//player skill1
		if (p->skill1 == 1)
		{//Fireball
			if (EA == 1)
			{//enemy basic attack
				cout << "You launch a ball of flames at your opponent, dealing 5 damage. The enemy attacks, dealing 3 damage to you." << endl;
				p->health -= 3;
				e->health -= 5;
			}
			else if (EA == 2)
			{//enemy block
				cout << "The enemy attempts to block the fire with his shield, taking 5 damage." << endl;
				e->health -= 5;
			}
			else if (EA == 3)
			{//enemy taunt
				cout << "The enemy yells 'Yer dead if I getcha with this!'. Your fireball deals 5 damage to the enemy." << endl;
				e->health -= 5;
			}
			else if (EA == 4)
			{//enemy crush
				cout << "The enemy attacks violently, dealing 6 damage. Your fireball deals 5 damage to the enemy." << endl;
				p->health -= 6;
				e->health -= 5;
			}
		}
		else if (p->skill1 == 2)
		{//Freeze
			cout << "You freeze the enemy in place, dealing 2 damage." << endl;
			e->health -= 2;
		}
		else if (p->skill1 == 3)
		{//Lightning Bolt
			if (EA == 1)
			{//enemy basic attack
				int i = rand() % 2;
				if (i == 0 || i == 1)
				{//no stun
					cout << "You strike your enemy with lightning, dealing 3 damage. Your enemy attacks you, dealing 3 damage." << endl;
					p->health -= 3;
					e->health -= 3;
				}
				else if (i == 2)
				{//stun
					cout << "The electricity stops your enemy in his tracks. He takes 3 damage." << endl;
					e->health -= 3;
				}
			}
			else if (EA == 2)
			{//enemy block
				int i = rand() % 2;
				if (i == 0 || i == 1)
				{//no stun
					cout << "The enemy's metal shield only conducts the electricity, dealing 5 damage." << endl;
					e->health -= 5;
				}
				else if (i == 2)
				{//stun
					cout << "The electricity stops your enemy in his tracks. He takes 3 damage." << endl;
					e->health -= 3;
				}
			}
			else if (EA == 3)
			{//enemy taunt
				int i = rand() % 2;
				if (i == 0 || i == 1)
				{//no stun
					cout << "The enemy yells 'Yer dead if I getcha with this!'. You strike your enemy with lighting, dealing 3 damage." << endl;
					e->health -= 3;
				}
				else if (i == 2)
				{//stun
					cout << "The electricity stops your enemy in his tracks. He takes 3 damage." << endl;
					e->health -= 3;
				}
			}
			else if (EA == 4)
			{//enemy crush
				int i = rand() % 2;
				if (i == 0 || i == 1)
				{//no stun
					cout << "The enemy attacks violently, dealing 6 damage. You strike the enemy with lightning, dealing 3 damage." << endl;
					e->health -= 3;
					p->health -= 6;
				}
				else if (i == 2)
				{//stun
					cout << "The electricity stops your enemy in his tracks. He takes 3 damage." << endl;
					e->health -= 3;
				}
			}
		}
		else
		{
			cout << "Error: invalid skill ID" << endl;
		}
	}
	else if (PA == 3)
	{//player skill2
		if (p->skill2 == 1)
		{//Perfect Block
			if (EA == 1)
			{//enemy basic attack
				cout << "You block all incoming damage." << endl;
			}
			else if (EA == 2)
			{//enemy block
				cout << "You and the enemy both raise your shields, how uneventful." << endl;
			}
			else if (EA == 3)
			{//enemy taunt
				cout << "You raise your shield. The enemy yells something, but your shield is so strong it even protects you from angry words." << endl;
			}
			else if (EA == 4)
			{//enemy crush
				cout << "You block the enemy's power attack, it feels like stopping a house with your arm." << endl;
			}
		}
		else if (p->skill2 == 2)
		{//Counter
			if (EA == 1)
			{//enemy basic attack
				cout << "The enemy attacks your ready shield, dealing 1 damage. You attack in return, dealing 2 damage." << endl;
				e->health -= 2;
				p->health -= 1;
			}
			else if (EA == 2)
			{//enemy block
				cout << "You attack the enemy's raised shield from behind your own. You deal 1 damage." << endl;
				e->health -= 1;
			}
			else if (EA == 3)
			{//enemy taunt
				cout << "The enemy starts screaming, so you attack from the safety behind your shield. He takes 2 damage." << endl;
				e->health -= 2;
			}
			else if (EA == 4)
			{//enemy crush
				cout << "You mostly block the incoming power attack, taking 2 damage. You retaliate, dealing 2 damage." << endl;
				e->health -= 2;
				p->health -= 2;
			}
		}
		else if (p->skill2 == 3)
		{//Doublestrike
			if (EA == 1)
			{//enemy basic attack
				cout << "The enemy attacks, dealing 3 damage. You attack twice, dealing 6 damage." << endl;
				e->health -= 6;
				p->health -= 3;
			}
			else if (EA == 2)
			{//enemy block
				cout << "The enemy tries to block both attacks, taking 3 damage." << endl;
				e->health -= 3;
			}
			else if (EA == 3)
			{//enemy taunt
				cout << "The enemy yells something about how cool he is. You hit him twice, dealing 6 damage." << endl;
				e->health -= 6;
			}
			else if (EA == 4)
			{//enemy crush
				cout << "The enemy hits you with a mighty blow, dealing 6 damage. You attack twice in return, dealing 6 damage." << endl;
				e->health -= 6;
				p->health -= 6;
			}
		}
		else
		{
			cout << "Error: invalid skill ID" << endl;
		}
	}
	else if (PA == 4)
	{//player heals
		if (EA == 1)
		{//enemy basic attack
			cout << "You are attacked by the enemy, taking 3 damage. You cast healing magic upon yourself, recovering 4 health." << endl;
			p->health += 1;
		}
		else if (EA == 2)
		{//enemy block
			cout << "Your enemy raises his guard. You heal yourself for 4 health." << endl;
			p->health += 4;
		}
		else if (EA == 3)
		{//enemy taunt
			cout << "The enemy yells something at you, but you are preoccupied with healing yourself for 4 health." << endl;
			p->health += 4;
		}
		else if (EA == 4)
		{//enemy crush
			cout << "You are hit with a staggering attack from the enemy, but you heal some of the damage. You lose 2 health." << endl;
			p->health -= 2;
		}
	}
	if (p->health > 0 && e->health > 0)
	{
		cout << "You have " << p->health << " health remaining, and the enemy has " << e->health << " health remaining." << endl;
	}
	else if (p->health <= 0 && e->health > 0)
	{
		cout << "You lose the battle, and your life. You are just another corpse in the sands of the arena." << endl;
		cout << "GAME OVER" << endl;
	}
	else if (p->health > 0 && e->health <= 0)
	{
		cout << "Your enemy falls before you. You have survived another day in the arena." << endl;
		cout << "YOU WIN" << endl;
	}
	else
	{
		cout << "You and your adversary strike each other down. There is no winner today." << endl;
		cout << "GAME OVER" << endl;
	}
}