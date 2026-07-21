#include<cstdio>
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long int>a;
	vector<long long int>x;
	

	long long int total = 0;
	for (int i = 0; i < n; i++) {
		long int ai;
		cin >> ai;
		a.push_back(ai);
		total += ai;
		x.push_back(total);
	}

	long long int min = 100000000000001;

	for (int i = 0; i < n-1; i++) {
		if (abs(total - 2*x[i]) < min) {
			min = abs(total - 2*x[i]);
		}
	}
	cout << min << endl;

	return 0;
}
