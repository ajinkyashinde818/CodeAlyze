#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>
#include <bitset>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_set>

using namespace std;

#define ef emplace_front
#define eb emplace_back
#define mp make_pair
#define MOD 1000000007

typedef long double f80;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef unordered_set<int> usi;
typedef set<int> si;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,r;
	cin>>n>>r;
	if (n>=10){
		cout<<r;
	}else{
		cout<<r+100*(10-n);
	}
}
