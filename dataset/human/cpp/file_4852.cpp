#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, r, x;
	cin >> n >> r;
	if (n >= 10)
		cout << r << endl;
	else
		cout << r + 100 * (10 - n) << endl;
	return 0;
}
