#include<iostream>
#include<string>
using namespace std;

class fraction 
{
public:
	friend ostream &operator<<(ostream &, fraction &);
	friend istream &operator>>(istream &, fraction &);
	
	void Numerators_denominators();
	operator int();
	operator double();
	operator float();

private:
	int input1, input2, input3;
	int Numerator, denominaor;
};

fraction::operator int() 
{
	return this->Numerator / this->denominaor;
}

fraction::operator float()
{
	return (static_cast<float>(this->Numerator) / static_cast<float>(this->denominaor));
}

fraction::operator double()
{
	return (static_cast<double>(this->Numerator) / static_cast<double>(this->denominaor));
}
void fraction::Numerators_denominators()
{
	int input1 = this->input1;
	int input2 = this->input2;
	int input3 = this->input3;
	if (input3 == -1) //痷だ计┪安だ计 
	{
		this->input3 = 0;
	}
	else              //盿だ计
	{
		input1 = input1 < 0 ? input1 * input3 - input2 : input1 * input3 + input2;
		input2 = input3;
		this->input3 = 0;	
	}
	this->Numerator = input1;
	this->denominaor = input2;
};


istream &operator>>(istream & input, fraction & number)
{
	char test;
	number.input3 = -1;
	cout << "input format is (-)1, 2, 3 or (-)1, 2" << endl;
	input >> number.input1;
	input.ignore(2);
	input >> number.input2;
	input.get(test);    //   "/n" = 10
	if (test == 10) 
	{
		return input;
	}
	else
	{
		input.ignore();
		input >> number.input3;
		return input;
	}
}
ostream &operator<<(ostream & output, fraction & number) 
{
	output << "int = " << int(number) << endl;
	output << "float = " << float(number) << endl;
	output << "double = " << double(number) << endl;
	return output;
}


int main() {
	fraction test ;
	cin >> test;
	test.Numerators_denominators();
	cout << test;
	system("pause");
	return 0;
}