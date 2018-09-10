#include<iostream>
using namespace std;
void rotation(int or_wide,int or_height,int add,int start,int counter,int temp[])
{
	int wide = or_wide - 2 * add;
	int height = or_height - 2 * add;
	if (wide <0 || height < 0)return;
    else if (wide == 1 && height == 1)temp[(or_wide*or_height-1)/2] = start;
	else 
	{

		for (int i = 0; i <  wide; i++) 
		{
			counter++;
			temp[counter] = start;
			start++;
		}
		
		for (int i = 0; i < height - 1; i++) 
		{
			counter += or_wide;
			temp[counter] = start;
			start++;
		}
		if (height - 1 != 0) 
		{
			for (int i = 0; i < wide - 1; i++)
			{
				counter--;
				temp[counter] = start;
				start++;
			}
		}
		if (wide - 1 != 0)
		{
			for (int i = 0; i < height - 2; i++)
			{
				counter -= or_wide;
				temp[counter] = start;
				start++;
			}
		}
	}
	return rotation(or_wide, or_height, add + 1, start,counter, temp);
}
void show(int wide,int height, int  temp[]) 
{
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < wide; j++) 
		{
			if (j == 0 ) 
			{
				if(temp[i * wide] < 10)	cout << " " << temp[i * wide];
				else cout << temp[i * wide];
			}
			else if (temp[i * wide + j] < 10) 
			{
				cout << "   " << temp[i * wide + j];
			}
			else 
			{
				cout << "  " << temp[i * wide + j];
			}
		}
		cout << endl;
	}
}
int main() {
	int wide, height;
	while (1)
	{
		cin >> wide >> height;
		int *temp = new int[wide * height];
		int total = wide * height;
		for (int i = 0; i < total; i++)temp[i] = 0;
		rotation(wide,height, 0, 1, -1, temp);
		show(wide, height, temp);
	}
	system("pause");
	return 0;
}