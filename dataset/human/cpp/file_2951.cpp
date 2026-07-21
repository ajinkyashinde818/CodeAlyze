#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	bool odd = false;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num < 0)
		{
			odd = !odd;
			num *= -1;
		}
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	if (odd)
	{
		v[0] *= -1;
	}

	int64_t max = 0;
	for (int i = 0 ; i < n; ++i)
	{
		max += v[i];
	}

	cout << max;
	return 0;
}
