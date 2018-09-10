#include<iostream>
using namespace std;
typedef struct node
{
	int value;
	struct node *next;
};
node * head = NULL;
node * tail = NULL;
void firstnode(int value) 
{
	node * temp = new node;
	temp->value = value;
	temp->next = NULL;
	head = temp;
	tail = temp;
}
void create(int value)
{
	node * temp =new node;
	tail->next = temp;
	temp->value = value;
	temp->next = NULL;
	tail = temp;
}
void display() 
{
	node * temp = new node;
	temp = head;
	while (temp->next != NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << temp->value <<endl;
}
int main() {
	int input;
	bool first = true;
	cout << "Please enter the number : ";
	cin >> input;
	while (input != -1) 
	{
		if(first == false) create(input);
		else
		{
			first = false;
			firstnode(input);
		}
		cout << "Please enter the number : ";
		cin >> input;
	}
	if(first == false) display();
	else cout << "empty" << endl;

	system("pause");
	return 0;
}