#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int n; cin >> n;
	vector<int> as(n); for (auto& a : as) { cin >> a; }
	vector<int> bs(n); for (auto& b : bs) { cin >> b; }


	unordered_map<int, int> amap;
	vector<int> acs(200001);
	FOR_LT(i, 0, n) {
		int a = as[i];
		if (amap.find(a) == amap.end()) {
			amap.insert({ a, i });
		}
		acs[a]++;
	}
	vector<int> bcs(200001);
	for (auto& b : bs) {
		bcs[b]++;
	}

	multimap<int, int> cmap;
	FOR_LE(i, 1, 200000) {
		if (n < acs[i] + bcs[i]) {
			cout << "No" << endl;
			return 0;
		}
		if (acs[i] != 0) {
			cmap.insert({ acs[i] + bcs[i], i });
		}
	}
	cout << "Yes" << endl;

	set<int> ps;
	FOR_LT(i, 0, n) {
		ps.insert(i);
	}

	vector<int> ans(n);
	auto cit = cmap.rbegin();
	while (cit != cmap.rend()) {
		int a = cit->second;
		//cout << celem.first << " " << celem.second << endl;
		//cout << p << " " << a << " " << acs[a] << endl;
		int an = acs[a];
		int ansp = amap[a] + an;
		FOR_LT(i, 0, bcs[a]) {
			auto it = ps.lower_bound(ansp);
			if (it == ps.end()) {
				it = ps.begin();
			}
			ansp = *it;
			ps.erase(it);
			ans[ansp] = a;
		}
		bcs[a] = 0;
		cit++;
	}

	int ansp = 0;
	FOR_LE(i, 1, 200000) {
		if (bcs[i] != 0) {
			FOR_LT(j, 0, bcs[i]) {
				auto it = ps.lower_bound(ansp);
				ansp = *it;
				ps.erase(it);
				ans[ansp] = i;
			}
		}
	}

	FOR_LT(i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
	

	return 0;
}
