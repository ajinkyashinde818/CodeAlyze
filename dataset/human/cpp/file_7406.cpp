#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<long long int> a;
	long long int sum = 0;

	long long int t;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		a.push_back(t);
		sum += t;
	}


	long long int smin;
	long long int p, q;
	p = a[0];
	q = sum - p;
	smin = abs(p - q);

	long long int temp;

	if (n > 2)
	{
		for (int i = 1; i < n - 1; i++)
		{
			p += a[i];
			q = sum - p;
			temp = abs(p-q);

			if (smin > temp)
			{
				smin = temp;
			}
		}
	}

	cout << smin << endl;
}
