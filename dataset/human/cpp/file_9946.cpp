#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n;
	string s;
	cin >> n >> s;
	
	map<char, int> m;
	for (int i = 0; i < n; i++) {
		m[s[i]]++;
	}

	ll cnt = 1;
	for (auto it = m.begin();it != m.end();it++) {
		cnt = (cnt * (it->second + 1)) % MOD_CONST;
	}
	cout << cnt - 1 << endl;
}
