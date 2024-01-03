#include "Vector.h"
using namespace Vector;

int main()
{
	vector<string> v1(20);
	cout << "Size of v1: " << v1.size() << endl;

	
	vector<string> v2;
	v2.push_back("a");
	v2.push_back("b");
	v2.push_back("c");
	v2.push_back("d");
	v2.push_back("e");
	v2.push_back("f");
	v2.push_back("g");
	v2.push_back("h");
	v2.push_back("i");
	cout << v2 << endl;
	
	vector<string> v3 = v2;
	vector<string> v4;
	v4 = v2;
	v2[0] = "Test2";
	v3[0] = "Test3";
	v4[0] = "Test4";
	cout << "Independent copies: " << v2[0] << " " << v3[0] << " " << v4[0] << endl;

	vector<string> v5(3);
	string s;
	cout << "Input 3 strings: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> s;
		v5.at(i) = s;
	}
	v5.push_back("Hello");
	v5.resize(100);
	cout << v5 << endl;

	vector<int> v6;
	try
	{
		for (int i = 0; i < 5; i++) v6.push_back(i);
		for (int i = 0; i <= v6.size(); i++)
		{
			cout << "v[" << i << "] == " << v6.at(i) << endl;
		}
	}
	catch (out_of_range_)
	{
		cout << "Caught out of range exception" << endl;
	}
	cout << v6 << endl;

	vector<double> v7;
	v7.push_back(3.14);
	const vector<double> v8 = v7;
	double d1 = v8[0];
	double d2 = v7[0];
	v7[0] = 9.9;
	cout << v7 << endl << v8 << endl;
}