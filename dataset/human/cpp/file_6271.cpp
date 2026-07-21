#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
typedef pair<P, P> PPP;

const ll MOD = 1e9 + 7;
const ll INF = 9e18;
const double DINF = 5e14;
const double eps = 1e-10;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second

int n;

int main() {
	cin >> n;
	cout << n * 32 << endl;
	return 0;
}
