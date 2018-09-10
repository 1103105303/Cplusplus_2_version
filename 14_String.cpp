#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

string Int2String(int &input)
{
	string s;
	stringstream ss(s);
	ss << input;

	return ss.str();
}
vector<string> Function1 ()
{
	string input;
	cin >> input;
	vector<string> temp;
	for (int i = 0;i < input.size();i++) 
	{
		switch (input[i])
		{
		case '0':
			temp.push_back("Zero");
			break;
		case '1':
			temp.push_back("One");
			break;
		case '2':
			temp.push_back("Two");
			break;
		case '3':
			temp.push_back("Three");
			break;
		case '4':
			temp.push_back("Four");
			break;
		case '5':
			temp.push_back("Five");
			break;
		case '6':
			temp.push_back("Six");
			break;
		case '7':
			temp.push_back("Seven");
			break;
		case '8':
			temp.push_back("Eight");
			break;
		case '9':
			temp.push_back("Nine");
			break;
		}
	}
	return temp;
}

vector<string> Function2 ()
{
	string input;
	int sep;
	cin >> input >> sep;
	int max = input.size();
	string save;
	vector<string> temp;
	for (int i = 0;i < input.size();i += sep)
	{
		for (int j = i;j < i + sep;j++)
		{
			save = input[j];
			if (j >= max)break;
			else temp.push_back(save);
		}
		temp.push_back(" ");
	}
	return temp;
}

vector<string> Function3 ()
{
	string input;
	cin.get();
	getline(cin, input);
	vector<string> temp;
	int count = 0;
	string save;
	for (int i = 0;i < input.size();i++)
	{
		if (input[i] == ' ' || input[i] == '\0') 
		{
			save = '[' + Int2String(count) + ']';
			temp.push_back(save);
			temp.push_back(" ");
			count = 0;
		}
		else 
		{
			count++;
			save = input[i];
			temp.push_back(save);
		}
	}
	save = '[' + Int2String(count) + ']';
	temp.push_back(save);
	return temp;
}


void printstring(vector<string> input) 
{
	for (int i = 0;i < input.size();i++) 
	{
		cout << input[i];
	}
	cout << endl;
}
int main() {
	int choice;
	while (1) 
	{
		cout << "請輸入 1、數字轉英文 2、字串分割 3、句子處理" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "請輸入數字" << endl;
			printstring(Function1());
			break;
		case 2:
			cout << "請輸入字串與分割數量" << endl;
			printstring(Function2());
			break;
		case 3:
			cout << "請輸入句子" << endl;
			printstring(Function3());
			break;
		}
	}
	system("pause");
	return 0;
}