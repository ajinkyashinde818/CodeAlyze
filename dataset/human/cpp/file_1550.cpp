#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
using ll = long long;
using namespace std;
using pii = pair<int, int>;

int N;
vector<int> A;

int main() {
	cin >> N;
	bool is_ok = false;
	int i;
	for (i = 1; i*i < 2*N; i++)
	{

	}
	int n=i-1;
	if (n*(n + 1) == 2 * N) {
		is_ok = true;
	}
	if (is_ok) {
		cout << "Yes" << endl;
		cout << n+1 << endl;
		cout << n << " ";
		for (int j = 1; j <= n; j++)
		{
			cout << j <<" ";
 		}
		cout << endl;
		vector<vector<int>> v(n+1);
		for (int i = 1; i <= n; i++)
		{
			v.at(i).push_back(i);
		}
		int num = n+1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				v.at(i).push_back(num);
				v.at(j).push_back(num);
				num++;
			}
			cout << n << " ";
			for (const auto &e : v.at(i))
			{
				cout << e << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
