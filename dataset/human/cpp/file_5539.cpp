#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cctype>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ll long long

int main()
{
    int n, r;
    cin >> n >> r;

	int result = r;
	if (n < 10)
	{
		result = r + 100 * (10 - n);
	}

	cout << result << endl;
    return 0;
}
