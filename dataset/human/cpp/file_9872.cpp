#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int main()
{
	const int mod = (int)pow(10, 9) + 7;

	int N;
	string S;
	cin >> N >> S;
	vector<int> c(26, 1);
	for (int i = 0; i < N; ++i)
	{
		++c[S[i] - 'a'];
	}
	long long int ret = 1;
	for (int i = 0; i < 26; ++i)
	{
		ret *= c[i];
		ret %= mod;
	}
	cout << (ret - 1) % mod << endl;

	return 0;
}
