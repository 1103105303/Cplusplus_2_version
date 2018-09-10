#include<iostream>
using namespace std;
typedef struct node 
{
	int value;
	node * next;
	node * befroe;
};
node * head = NULL;
node * tail = NULL;
void firstnode(int value) 
{
	node * temp = new node;
	temp->value = value;
	temp->befroe = NULL;
	temp->next = NULL;
	head = temp;
	tail = temp;
}
void addnode(int value) 
{
	node * temp = new node;
	temp->befroe = tail;
	tail->next = temp;
	temp->value = value;
	temp->befroe = tail;
	temp->next = NULL;
	tail = temp;
}
void insert(int index, int input)
{
	node * temp = new node;
	node * find;
	find = head;
	if (index > sizeof(temp))cout << "Error" << endl;
	else 
	{
		for (int i = 0; i < index; i++)
		find = find->next;

		if (find == tail) 
		{
			tail = temp;
			temp->next = NULL;
		}
		else 
		{
			temp->next = find->next;
			temp->next->befroe = temp;
		}
		find->next = temp;
		temp->befroe = find;
		temp->value = input;
	}
}
void removenode(int value) 
{
	node * temp;
	temp = head;
	bool find = false, nothing = false;
	if (temp->value == value) 
	{
		temp->next->befroe = NULL;
		head = temp->next;
		free(temp);
		find = true;
	}
	while (nothing == find)
	{
		if (temp->value == value) 
		{
			if (temp == tail) 
			{
				temp->befroe->next = NULL;
				tail = temp->befroe;
			}
			else
			{
				temp->befroe->next = temp->next;
				temp->next->befroe = temp->befroe;
			}
			find = true;
			free(temp);
		}
		else if (temp == tail)
		{
			nothing = true;
		}
		else
		{
			temp = temp->next;
		}
	}

	if (find == false) cout << "Your input is error" << endl;
	else cout << "remove the node : " << value << endl;
}
void display() 
{
	node * temp;
	temp = head;
	while (temp != tail) 
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << tail->value << endl;
}
int main() {
	int choice, input, index;
	bool first = true;
	cout << " === Add(0) / Insert(1) / Delete(2) / Show(3) ===" << endl;
	while (1) 
	{
		cout << "Please enter the mode   : ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Please enter the number : ";
			cin >> input;
			if (first == true)
			{
				first = false;
				firstnode(input);
			}
			else addnode(input);
			break;
		case 1: 
			cout << "Please enter the index  : ";
			cin >> index;
			cout << "Please enter the number : ";
			cin >> input;
			insert(index, input);
			break;
		case 2:
			cout << "Please enter the value : ";
			cin >> input;
			removenode(input);
			break;
		case 3:
			display();
			break;
		default:
			cout << "Error Input" << endl;
			break;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}