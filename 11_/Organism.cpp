#include<iostream>
#include<string>
#include<time.h>
#include"Organism.h"
using namespace std;

Organism::Organism(int hp = 0, int mp = 0) 
{
	SetData(hp, mp);
}

Summoner::Summoner(int hp = 0, int mp = 0, int atk = 0) :
	Organism(hp, mp), ATK(atk)
{
	SetDead(false);
	SetAtk(atk);
}

Monster::Monster(int hp = 0, int mp = 0, int atk = 0) :
	Organism(hp, mp), ATK(atk)
{
	SetDead(false);
	SetAtk(atk);
}
//---------------------------------------------------------
void Organism::SetData(int hp,int mp) 
{
	HP = hp;
	MP = mp;
}
void Organism::SetHp(int hp) 
{
	HP = hp;
}
void Organism::SubHp(int sub) 
{
	HP -= sub;
}
int Organism::GetHp() 
{
	return this->HP;
}
//----------------------------------------------------------
bool Summoner::GetDead() 
{
	return DEAD;
}
void Summoner::SetDead(int hp) 
{
	if (hp < 0)
	{
		DEAD = true;
		this->SetHp(0);
	}
	else
		DEAD = false;
}
void Summoner::SetAtk(int atk) 
{
	ATK = atk;
}
int Summoner::RandAtk(int atk) 
{
	int randatk;
	randatk = rand() % atk + 1;
	this->SubHp(randatk);
	this->SetDead(this->GetHp());
	return randatk;
}
//----------------------------------------------------------
bool Monster::GetDead()
{
	return DEAD;
}
void Monster::SetDead(int hp)
{
	if (hp < 0)
	{
		DEAD = true;
		this->SetHp(0);
	}
	else
		DEAD = false;
}
void Monster::SetAtk(int atk)
{
	ATK = atk;
}
int Monster::RandAtk(int atk)
{
	int randatk;
	randatk = rand() % atk + 1;
	this->SubHp(randatk);
	this->SetDead(this->GetHp());
	return randatk;
}
