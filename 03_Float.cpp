#include<iostream>
using namespace std;
float FLOAT(float input1, float input2) 
{
	int temp,temp2;
	temp = (int)(input1 / input2 / 0.1);
	temp2 =(int)(input1 / input2);
	temp2 *= 10;
	temp2 = temp - temp2; // 取最後一位
	temp = (temp + temp2) * 0.1; // 四捨五入
	return (float)(temp * input2);
}


int main() {
	float input1, input2;
	while (1)
	{
		cin >> input1 >> input2;
		cout << FLOAT(input1, input2)<<endl;
	}
	system("pause");
	return 0;
}