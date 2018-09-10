#include<iostream>
#include<string>
#include <queue> 
#include<vector>
using namespace std;
void printstring(deque<char> output)
{
	for (int i = 0;i < output.size();i++) 
	{
		cout << output[i];
	}
	cout << endl;
}
void addstring(deque<char> ch1, deque<char> ch2)
{
	cout << " a = ";
	printstring(ch1);
	cout << " b = ";
	printstring(ch2);
	for (int i = 0;i < ch2.size();i++) 
	{
		ch1.push_back(ch2[i]);
	}
	cout << " a + b = ";
	printstring(ch1);
}
void substring(deque<char> ch1, deque<char> ch2)
{
	deque<char> ch3;
	int same = 0;
	int size1 = ch1.size();
	int size2 = ch2.size();
	for (int i = 0;i < size1;i++)
	{
		if (ch1[i] != ch2[same])
		{
			for (int j = i - same;j <= i;j++)
			{
				ch3.push_back(ch1[j]);
			}
			same = 0;
		}
		//相等
		else if (same < size2 - 1)
		{
			same++;
		}
		else
		{
			same = 0;
		}
	}
	//尾數處理
	for (int i = size1 - same;i < size1;i++) 
	{
		ch3.push_back(ch1[i]);
	}
	cout << " a - b = ";
	printstring(ch3);
}
void printQ(vector<int> input)
{
	int count = input.size();
	int size;
	vector<int> output;

	//堆疊轉佇列
	for (int i = 0;i < count;i++)
	{
		size = input.size() - 1;
		output.push_back(input[size]);
		input.pop_back();
	}
	cout << "Pop : " << endl;
	for (int i = 0;i < count ;i++)
	{
		size = output.size() - 1;
		cout << "  Step " << i << " : " << output[size] << endl;
		output.pop_back();
	}
	cout << endl << "EMPTY." << endl;
}
void printS(vector<int> input)
{
	int count = input.size();
	int size;
	cout << "Pop : " << endl;
	for (int i = 0;i < count;i++)
	{
		size = input.size() - 1;
		cout << "  Step " << i << " : " << input[size] << endl;
		input.pop_back();
	}
	cout << endl << "EMPTY." << endl;
}
//堆疊(Stack)與佇列(Queue)
void FStack_Queue() 
{
	int number,inget,choice;
	cout << "Stack(1) or Queue(2)" << endl;
	cin >> choice;
	cout << "How many number you want to push ? ";
	cin >> number;
	vector<int> input;
	inget = number - 1;
	cout << "Push : " << endl;
	for (int i = 0;i < number;i++) 
	{
		cout << "  Step " << i << " : " << inget << endl;
		input.push_back(inget);
		inget--;
	}

	choice == 1 ? printS(input) : printQ(input);
}
//deque 可pushback pushfront，popback popfront 較方便，也較占空間
void add_sub_string() 
{
	string instring;
	cout << "輸入a字串" << endl;
	cin >> instring;
	deque<char> ch1(instring.begin(), instring.end());
	cout << "輸入b字串" << endl;
	cin >> instring;
	deque<char> ch2(instring.begin(), instring.end());
	addstring(ch1, ch2);
	substring(ch1, ch2);
}
int main() {
	while (1) 
	{
		//FStack_Queue();
		add_sub_string();
	}
	system("pause");
	return 0;
}


