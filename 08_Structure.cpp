#include<iostream>
#include <vector>
#include<string>
using namespace std;
struct Student
{
	string name;
	string number;
	int score;
};
void save(string name, string number, int score, vector<struct Student> *temp) 
{
	struct Student Newstudent;
	Newstudent.name = name;
	Newstudent.number = number;
	Newstudent.score = score;
	temp->push_back(Newstudent);
}
void show(vector<struct Student> temp) 
{
	for (int i = 0; i < temp.size(); i++) 
	{
		cout << i << " => " << temp[i].name << " " << temp[i].number << " " << temp[i].score << endl;
	}
}

int main() {
	cout << "=== Add(0) / Delete(1) / Show(2) ===" << endl;
	int counter = 0;
	vector<struct Student> NewStudent;
	while (1) 
	{
		int choice,DC;
		string name,number;
		int score;
		cout << "Function you want : ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "input name number score" << endl;
			cin >> name >> number >> score;
			save(name, number, score, &NewStudent);
			break;
		case 1:
			if (NewStudent.size() <= 0)cout << "Empty" << endl;
			else
			{
				cout << "Which do you want to delete :";
				cin >> DC;
				NewStudent.erase(NewStudent.begin() + DC);
			}
			break;
		case 2:
			show(NewStudent);
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}