#include<iostream>
using namespace std;

float square(float input) 
{
	return input * input;
}
int main() {
	float input;
	cin >> input;
	cout << square(input) << endl;
	system("pause");
	return 0;
}