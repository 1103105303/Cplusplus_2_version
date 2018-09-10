#ifndef ASMD_H
#define ASMD_H
#include<iostream>
#include <queue> 
#include<string>
using namespace std;
class asmd 
{
	friend ostream &operator<<(ostream &, const asmd &);
	friend istream &operator>>(istream &, asmd &);
public:

	void empty(deque<int>&);
	void char2int(string, deque<int> &);
	void negativeadjust(deque<int> &);
	void carryadjust(deque<int> &);

	void addnumber();
	void mulnumber();
	deque<int> subnumber(deque<int>, deque<int>,bool &);
	void dividenumber(deque<int>, deque<int>);

	void choicealu(char);

private:
	deque<int> a, b, answer;
	string input1, input2;
	bool neg;
};
#endif