#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, string> pls;

ll a[200010],ans[200010];

int main()
{
	ll N; 
	cin >> N;

	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
	}

	ll nusuke = sum,arai = 0,res = (ll)1e10;
	for (int i = 0; i < N-1; i++) {
		arai += a[i];
		nusuke -= a[i];
		ans[i] = abs(arai-nusuke);
	}
	sort(ans,ans+N-1);

	res = ans[0];

	cout << res << endl;
	return 0;
}
