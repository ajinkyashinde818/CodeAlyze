#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>


using namespace std;


int main()

{
	long long x, y,z;
	cin >> x >> y;
	if (x >= 10)
	{
		cout << y << endl;
	}
	else
	{
		z = 100 * (10 - x);
		z += y;
		cout << z << endl;
	}




}
