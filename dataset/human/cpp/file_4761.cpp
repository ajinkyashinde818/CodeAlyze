#include <iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b;
	if (a > 10)
	{
		a = 10;
	}
	c = 100 * (10 - a) + b;
	cout << c << endl;


}
