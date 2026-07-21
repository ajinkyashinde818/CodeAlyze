#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	std::vector<ll> A(N);
	int mcount = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i] < 0)
		{
			mcount += 1;
		}
	}

	ll ans = 0;
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += abs(A[i]);
	}

	ll min_ = 1e15;
	if (mcount % 2 == 0)
	{
		ans = sum;
	}
	else{
		for (int i = 0; i < N; i++)
		{
			min_ = min(min_,abs(A[i]));
		}
		ans = sum - 2*min_;
	}
	cout << ans << endl;

	return 0;
}
