#include<iostream>
using namespace std;
void try_catch() 
{
	int input;
	int count = 1;
	cin >> input;
	cout << input << "! : ";
	try
	{
		if (input > 12 || input < 0)
		{
			throw input;
		}
		else 
		{
			if (input < 1) 
			{
				cout << 1 << endl;
			} 
			else
			{
				while (input != 1) 
				{
					count *= input;
					input--;
				}
			}
		}
		cout << count << endl;
	}
	catch (int error) 
	{
		cout << "==ERROR==" << endl;
	}
}
int main() {
	while (1) 
	{
		try_catch();
	}
	system("pause");
	return 0;
}