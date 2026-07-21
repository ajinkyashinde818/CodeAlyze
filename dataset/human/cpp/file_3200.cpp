#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int n;
ll mem[MAXN][2];
ll a[MAXN];
ll solve(int i,int f)
{

if(i == n)
{
    if(f) return -1e9;
    return 0;
}

ll &ret = mem[i][f];

if(ret != -1) return ret;
ret = 0;
ll p1  = 0 , p2 = 0;
if(f) p1 = solve(i + 1 , 0) - a[i];
else p1 = solve(i + 1 , 0) + a[i];
if(!f) p2 = solve(i + 1 , 1) - a[i];
else p2 = solve(i + 1 , 1) + a[i];
ret = max(p1,p2);
return ret;

}

int main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	memset(mem,-1,sizeof(mem));
    cout << solve(0,0) << '\n';
}
