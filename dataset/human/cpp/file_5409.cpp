#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int mod = 1e9+7;
const int maxn = 2e5+5;
int main() {
	ll n,m;
	cin>>n>>m;
	if(n<10) cout<<(10-n)*100+m<<endl;
	else cout<<m<<endl;
    return 0;
}
