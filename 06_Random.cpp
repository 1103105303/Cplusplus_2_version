#include<iostream>
#include<time.h>
using namespace std;
void change(int *a, int *b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Bubble_sort(int length, int temp[])
{
	for (int i = 0; i < length - 1; i++) 
	{
		for (int j = 0; j < length - i - 1; j++) 
		{
			if (temp[j] > temp[j + 1])
			change(&temp[j], &temp[j + 1]);
		}
	}
}
void show(int length, int temp[]) 
{
	cout << " Array => { " << temp[0];
	for (int i = 1; i < length; i++) 
	{
		cout << ", " << temp[i];
	}
	cout << " }" << endl;
}
int main() {
	int len;
	cin >> len;
	int *temp = new int[len];
	srand(time(NULL));
	for (int i = 0; i < len; i++) 
	{
		temp[i] = (rand() % 10) + 1;
	}
	show(len, temp);
	Bubble_sort(len, temp);
	show(len, temp);
	system("pause");
	return 0;
}