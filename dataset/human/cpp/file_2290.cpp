#include <iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int h[25][2];

int main()
{
	int n;
	cin >> n;
	long long int a;
	long long int L = 1000000000;
	long long int sum = 0;
	int ct = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		sum += abs(a);
		if (a <= 0)ct++;
		if (abs(a)<L)L = abs(a);
	}
	if(ct%2==1)cout << sum - 2 * L << endl;
	else cout << sum << endl;
}
