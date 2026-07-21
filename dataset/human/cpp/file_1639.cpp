/*
ID: arthurc4
TASK: test
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef vector<string> vs;
typedef vector<vs> vvs;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef map<string,int> msi;
typedef map<int,int> mii;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll; // note 'single' ls

typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)

#define REPb(j, d, c) \
for (int j = int(d); j >= int(c); j--)

#define pb \
push_back

#define ff \
first

#define ss \
second

// LL OR INT ???
// DELETED IFSTREAM ???
int main()
{
	//ifstream cin("input.txt");
	//ifstream cin("test.in");
	//ofstream cout("test.out");

	int n;
	cin >> n;

	int k;

	REP(i, 1, 10000)
	{
		if(i*(i-1) == 2*n)
		{
			k = i;
			break;
		}

		if(i*(i-1) > 2*n)
		{
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	vi claimed(n+1, -1);

	vector<priority_queue<int>> elements_in_sets;
	priority_queue<int> fake;
	elements_in_sets.pb(fake);

	priority_queue<int> elements_yet_to_be_used;

	REP(i, 1, n)
	{
		elements_yet_to_be_used.push(-i);
	}

	cout << k << endl;

	REP(subset, 1, k)
	{
		cout << k-1 << " "; // the size of the subset is k-1

		priority_queue<int> current_subset_elements;

		REP(previous_subsets, 1, subset-1) // borrow elements from previous subsets
		{
			cout << -elements_in_sets[previous_subsets].top() << " ";

			// current_subset_elements.push(elements_in_sets[previous_subsets].top());

			elements_in_sets[previous_subsets].pop();
		}

		REP(extra_elements, 1, (k-1)-(subset-1))
		{
			cout << -elements_yet_to_be_used.top() << " ";

			current_subset_elements.push(elements_yet_to_be_used.top());

			elements_yet_to_be_used.pop();
		}

		elements_in_sets.pb(current_subset_elements);

		cout << endl;
	}

	return 0;
}
