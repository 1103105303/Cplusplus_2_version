#include<iostream>
#include "ASMD.h"

using namespace std;

int main() {
	char input;
	asmd ALU;
	cin >> ALU;
	cout << "請輸入加減乘除" << endl;
	cin >> input;
	ALU.choicealu(input);
	cout << ALU;
	system("pause");
	return 0;
}
