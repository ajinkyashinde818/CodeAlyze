#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <string.h>

using namespace std;
typedef pair<long long, long long> P;


void solve()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	int minusCount = 0;
	long long absMin = 1e10;
	long long ans = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		absMin = min(absMin, abs(A[i]));
		ans += abs(A[i]);
		if (A[i] < 0)
		{
			++minusCount;
		}
	}
	if (minusCount % 2 == 0)
	{
		cout << ans << endl;
	}
	else
	{
		cout << ans - 2 * absMin << endl;
	}
}

int main()
{
	solve();
	return(0);
}
