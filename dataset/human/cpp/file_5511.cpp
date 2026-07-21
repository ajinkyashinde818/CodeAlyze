#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

long long n, r;
int main()
{
	cin >> n >> r;
	if (n >= 10) cout << r;
	else cout << r + 100 * (10 - n);
}
