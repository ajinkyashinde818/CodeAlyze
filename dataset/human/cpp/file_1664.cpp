// October.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "string"
#include "map"
#include "stack"
#include "bitset"
#include "deque"
#include "queue"
#include "cmath"
#include "fstream"
#include "list"
#include "unordered_set"
#include "functional"
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
#define all(a) a.begin(), a.end()
const int N = 100050;
vector<int> ans[N];

int findk(int n) {
	int k = 1;
	while ((k*(k - 1)) / 2 < n)
		k++;
	if ((k*(k - 1)) / 2 == n)
		return k;
	else
		return -1;
}

signed main()
{
	ios::sync_with_stdio(0);
	int n; cin >> n; 
	int k = findk(n);
	if (k == -1)
		return cout << "No\n", 0;
	cout << "Yes\n" << k << '\n';
	int stop = 1;
	for (int i = 1; i <= k; i++) {
		int j = i + 1;
		while (j <= k) {
			ans[i].push_back(stop);
			ans[j].push_back(stop);
			j++;
			stop++;
		}
	}
	for (int i = 1; i <= k; i++) {
		cout << ans[i].size() << ' ';
		for (auto a : ans[i])
			cout << a << ' ';
		cout << '\n';
	}
	return 0;
}
