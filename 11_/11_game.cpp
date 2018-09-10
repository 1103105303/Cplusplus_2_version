#include<iostream>
#include<windows.h>
#include<string>
#include<time.h>
#include"Organism.h"

using namespace std;


int main() {
	srand((int)time(NULL));

	int counter = 1;
	int hp = 20, mp = 5, atk = 3;
	int Mhp = 10, Mmp = 5, Matk = 4;
	cout << "Create Summoner (" << hp << ", " << mp << ", " << atk << ")" << endl;
	cout << "Create Monster   (" << Mhp << ", " << Mmp << ", " << Matk << ")" << endl;

	Summoner summoner(hp, mp, atk);
	Monster monster(Mhp, Mmp, Matk);

	while (summoner.GetDead() != true && monster.GetDead() != true) 
	{

		cout << "#" << counter << endl;
		cout << "Summoner hurt Monster " << summoner.RandAtk(Matk) << "HP" << endl;
		cout << "Monster  hurt Summoner " << monster.RandAtk(atk) << "HP" << endl;
		cout << "Summoner HP is " << summoner.GetHp() << endl;
		cout << "Monster HP is " << monster.GetHp() << endl;
		counter++;
	}
	system("pause");
	return 0;
}


