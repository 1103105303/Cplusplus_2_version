#ifndef ORGANISM_H
#define ORGANISM_H
#include <iostream>
#include<string>
using namespace std;
class Organism
{
public:
	//ªì©l¤Æ
	Organism(int , int);
	void SetData(int, int);
	void SetHp(int);
	void SubHp(int);
	int  GetHp();

private:
	int HP;
	int MP;
};

class Summoner : public Organism
{
public:
	Summoner(int, int, int);
	void SetDead(int);
	bool GetDead();
	void SetAtk(int);
	int RandAtk(int);
private:
	int ATK;
	bool DEAD;
};
class Monster : public Organism
{
public:
	Monster(int, int, int);
	void SetDead(int);
	bool GetDead();
	void SetAtk(int);
	int RandAtk(int);
private:
	int ATK;
	bool DEAD;
};
#endif 