#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <sstream>
#include <complex>

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using iii = pair<int, ii>;
using viii = vector<iii>;

using ll = long long int;
using vc = vector<char>;
using vb = vector<bool>;
using ib = pair<int, bool>;
using vib = vector<ib>;

const ll MOD = 1000 * 1000 * 1000 + 7;
#define INF 1000 * 1000 * 1000
#define EMPTY -10
#define mp(a, b) make_pair(a,b)

void calcular(int lAct, vi const& letras, ll & res, ll totalAct) {
	if (lAct == letras.size()) {
		res = (res + totalAct) % MOD;
	}
	else {
		calcular(lAct + 1, letras, res, totalAct);
		calcular(lAct + 1, letras, res, (totalAct * letras[lAct]) % MOD);
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;
	string s;
	cin >> s;
	vi letras('Z' - 'A' + 1,0);

	for (int i = 0; i < s.size(); ++i) {
		++letras[s[i] - 'a'];
	}

	vi letrasP;

	for (int i = 0; i < letras.size(); ++i) {
		if (letras[i] != 0) letrasP.push_back(letras[i]);
	}

	ll res = 0;
	calcular(0, letrasP, res, 1);
	cout << res - 1 << '\n';

	return true;
}

int main() {
	while (resuelveCaso()) {}
	return 0;
}
