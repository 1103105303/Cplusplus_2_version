#include<math.h>
#include<iostream>
#include <queue> 
#include<string>
#include "ASMD.h"
using namespace std;

ostream &operator<<(ostream & output, const asmd &result )
{
	if (result.neg == true)
		cout << "-";
	else
		cout << "+";
	for (int i = result.answer.size() - 1;i >= 0;i--)
		output << result.answer[i];
	output << endl;
	return output;
}
istream &operator>>(istream &cinput, asmd &input) 
{
	cout << "輸入數字1" << endl;
	cinput >> input.input1;
	cout << "輸入數字2" << endl;
	cinput >> input.input2;
	input.char2int(input.input1, input.a);
	input.char2int(input.input2, input.b);
	return cinput;
}
//-------------------------------------------------
void asmd::choicealu(char choice) 
{
	switch (choice)
	{
	// +
	case '+':
		addnumber();
		break;
	// -
	case '-':
		answer = subnumber(a, b, neg);
		break;
	// *
	case '*':
		mulnumber();
		break;
	// /
	case '/':
		dividenumber(a, b);
		break;
	default:
		answer.push_back(0);
		break;
	}
}
//-------------------------------------------------
void asmd:: char2int(string temp, deque<int> &a)
{
	char integer;
	for (int i = 0;i < temp.size();i++)
	{
		integer = temp[i];
		a.push_front(atoi(&integer));
	}
}

void asmd :: empty(deque<int> &a)
{
	int max = a.size() - 1;
	for (int i = max;i > -1;i--)
	{
		if (a[i] == 0)a.pop_back();
		else break;
	}
}

void asmd::negativeadjust(deque<int> &a)
{
	for (int i = 0;i < a.size();i++)
	{
		while (a[i] < 0)
		{
			a[i] += 10;
			a[i + 1] -= 1;
		}
	}
	empty(a);
}
void asmd::carryadjust(deque<int> &a)
{
	int temp;
	int remainder;
	int carry;
	for (int i = 0;i < a.size();i++)
	{
		if (i == a.size() - 1)          //最高位數 需要push新的進位
		{
			carry = i;
			remainder = a[carry] % 10;  //餘數
			temp = a[carry] / 10;       //商，進位
			while (temp != 0)
			{
				a[carry] = remainder;
				a.push_back(temp);
				carry++;
				remainder = a[carry] % 10;  //餘數
				temp = a[carry] / 10;       //商，進位
			}
		}
		else                             //一般進位
		{
			remainder = a[i] % 10;  //餘數
			temp = a[i] / 10;       //商，進位
			a[i] = remainder;
			a[i + 1] += temp;
		}
	}
}
//------------------------------------------------------
void asmd::addnumber()
{
	int min_size, big;
	int sub = a.size() - b.size();
	sub = abs(sub);
	min_size = a.size() > b.size() ? b.size() : a.size();
	big = a.size() > b.size() ? 1 : 2;

	for (int i = 0;i < min_size + sub;i++)
	{
		if (i < min_size)
			answer.push_back(a[i] + b[i]);
		else
		{
			if (big == 1)
				answer.push_back(a[i]);
			else
				answer.push_back(b[i]);
		}
	}
	carryadjust(answer);
}

deque<int> asmd::subnumber(deque<int> a, deque<int> b, bool &neg)
{
	deque<int> c;
	empty(a);
	int min_size;
	int sub = a.size() - b.size();
	sub = abs(sub);
	min_size = a.size() > b.size() ? b.size() : a.size();

	//正負號
	if (a.size() == b.size())
	{
		for (int i = a.size() - 1;i >= 0;i--)
		{
			if (a[i] > b[i])
			{
				neg = false;
				break;
			}
			else if (b[i] > a[i])
			{
				neg = true;
				break;
			}
		}
	}
	else
		neg = a.size() > b.size() ? false : true;
	for (int i = 0;i < min_size + sub;i++)
	{
		if (neg == false)
		{
			if (i < min_size)
				c.push_back(a[i] - b[i]);
			else
				c.push_back(a[i]);
		}
		else
		{
			if (i < min_size)
				c.push_back(b[i] - a[i]);
			else
				c.push_back(b[i]);
		}
	}

	negativeadjust(c);
	return c;
}

void asmd::mulnumber()
{
	deque<int> big, small;
	if (a.size() > b.size())
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}
	answer = big;
	//lowwer
	for (int i = 0;i < answer.size();i++)
	{
		answer[i] *= small[0];
	}
	//start
	for (int j = 1;j < small.size();j++)
	{
		answer.push_back(0);
		carryadjust(answer);
		for (int i = 0;i < big.size();i++)
		{
			answer[i + j] += small[j] * big[i];
		}
	}
	carryadjust(answer);
}

void asmd::dividenumber(deque<int> dividend, deque<int> divisor)
{
	bool neg = false;
	int count = 0;
	int dividend_size = dividend.size();
	int divisor_size = divisor.size();
	deque<int> temp;
	if (dividend.size() < divisor.size())
	{
		answer.push_back(0);
	}
	else
	{
		//divisor 補零
		for (int i = 0;i < dividend_size - divisor_size;i++)
		{
			divisor.push_front(0);
		}
		//除法，重複減法次數
		for (int i = 0;i < dividend_size - divisor_size + 1;i++)
		{
			while (neg == false)
			{
				temp = subnumber(dividend, divisor, neg);
				if (neg == false)
				{
					count++;
					dividend = temp;
				}
			}
			answer.push_front(count);
			neg = false;
			count = 0;
			divisor.pop_front();
		}
	}
	empty(answer);
}

//------------------------------------------------------
