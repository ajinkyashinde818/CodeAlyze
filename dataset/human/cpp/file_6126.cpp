#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
using namespace std;

class D
{
public:
	int n;
	long long c;
	vector<long long> x;
	vector<long long> v;
	vector<long long> w;

	void input ()
	{
		cin >> n >> c;
		x.resize(n+1);
		v.resize(n+1);
		w.resize(n+1);

		x[0] = 0;
		v[0] = 0;
		for (int i=1; i<=n; ++i)
		{
			cin >> x[i];
			cin >> v[i];
			v[i] += v[i-1];
		}
		x.push_back(c);
		for (int i=0; i<=n; ++i)
		{
			w[i] = v[n] - v[i];
		}
	}

	long long solve ()
	{
		for (int a = 1; a <= n; ++a)
		{
			v[a] = max(v[a-1], v[a] - x[a]);
			w[n-a] = max(w[n+1-a], w[n-a] - (c - x[n+1-a]));
		}
		long long max_value = 0;
		for (int a = 0; a <= n; ++a)
		{
			max_value = max(max_value, v[a] + w[a] - x[a]);
			max_value = max(max_value, v[a] + w[a] - (c - x[a+1]));
		}

		return max_value;
	}
};

int main ()
{
	D d;
	d.input();

	cout << d.solve() << endl;
	return 0;
}
