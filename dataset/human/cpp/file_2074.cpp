#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	long long int N, a[100000] = {},mini=1000000001,count = 0,sum=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum += abs(a[i]);
		if (a[i] < 0)count++;
		mini = min(mini, abs(a[i]));
	}
	if (count % 2)cout << sum - 2 * mini;
	else cout << sum;
	return 0;
}
