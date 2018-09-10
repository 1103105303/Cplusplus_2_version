#include<iostream>
#include<vector>
using namespace std;
template<class T> 
T Get(vector<T> input)
{
	T  sum, product, square_of_sum;
	sum = 0;
	product = 1;
	square_of_sum = 0;

	for (int i = 0;i < input.size(); i++)
	{
		sum += input[i];
		product *= input[i];
		square_of_sum += input[i] * input[i];
	}
	cout << "Sum : " << sum << endl;
	cout << "Product : " << product << endl;
	cout << "Square of Sum : " << square_of_sum << endl;
	return 0;
}
int main() {
	int input;
	vector<int> ivector;
	float input2;
	vector<float> ivector2;
	cout << "輸入 0 結束" << endl;
	cin >> input;
	while (input != 0) 
	{
		ivector.push_back(input);
		cin >> input;
	}
	Get(ivector);

	cout << "輸入 0 結束" << endl;
	cin >> input2;
	while (input2 != 0)
	{
		ivector2.push_back(input2);
		cin >> input2;
	}
	Get(ivector2);
	system("pause");
	return 0;
}

