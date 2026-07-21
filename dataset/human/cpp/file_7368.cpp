#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<long long> a(N);
	vector<long long> sum(N, 0);
	cin >> a[0];
	sum[0] = a[0];
	for(int i=1; i<N; i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}

	vector<long long> table(N-1, 0);
	for(int i=0; i<N-1; i++)
	{
		long long x = sum[i];
		long long y = sum.back() - x;
		table[i] = abs(x - y);
	}

	long long ret = *min_element(table.begin(), table.end());
	cout << ret << endl;

	return 0;
}
