#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long r, n,en;
	cin >> n >> r;
	if (n >= 10)
		en = r;
	else
		en = r + (10 - n) * 100;
	cout << en << endl;
}
