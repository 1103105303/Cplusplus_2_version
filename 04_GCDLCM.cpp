#include<iostream>
using namespace std;
int GCD(int input1, int input2)
{
	if (input1 == 0) return input2;
	else if (input2 == 0) return input1;
	else if (input1 > input2) return GCD(input1%input2, input2);
	else return GCD(input1, input2%input1);
}

int LCD(int input1, int input2) 
{
	int temp = GCD(input1, input2);
	if (temp == 1) return input1 * input2;
	else return LCD(input1 / temp, input2 / temp) * temp;
}

int main() {
	int input1, input2;
	while (1)
	{
		cin >> input1 >> input2;
		cout <<"GCD : "<< GCD(input1, input2) << endl;
		cout <<"LCD : "<<LCD(input1,input2) << endl;
	}
	return 0;
}