#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include <iomanip>
#include<sstream>
#include<string.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, r;
	while (cin >> n >> r)
	{
		if (n < 10)
			r = r + 100 * (10 - n);
		cout << r << endl;
	}
}
