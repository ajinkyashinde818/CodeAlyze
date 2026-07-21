#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)

#define vll    vector<ll>
#define vvll   vector<vector<ll>>
#define all(x) (x).begin(),(x).end()


int main()
{	
	int N;
	cin >> N;

	string S;
	cin >> S;

	map<char, int> counts;

	rep(i, S.size())
	{
		counts[S[i]]++;
	}

	ll ans = 1;

	for (auto x : counts)
	{
		ans *= (x.second + 1);
		ans %= mod;
	}

	cout << ans - 1 << endl;

	return 0;
}
