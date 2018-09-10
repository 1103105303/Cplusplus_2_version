#include<iostream>
using namespace std;
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		cout << "Move disk " << n << " from " << a << " to " << c << endl;
	else
	{
		hanoi(n - 1, a, c, b);   //除了最後一個，其他A->B
		cout << "Move disk " << n << " from " << a << " to " << c << endl;//最後一個A->C
		hanoi(n - 1, b, a, c);   //剩下的B->C
	}
}
int main()
{
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	system("pause");
	return 0;
}