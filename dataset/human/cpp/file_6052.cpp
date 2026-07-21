/*
 ID: bradyawn
 PROG: contest
 LANG: C++11
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef pair<ll,ll> ll2;

int n;
ll c;

ll xVal[100002];
ll v[100002];
int f[100002];
int f2[100002];

ll calc(int a, int b) //a to b
{
    if (a < b) return -1e18;
    
    ll ret = 0;
    
    ll x = c-xVal[a];
    ll y = xVal[b];
    
    
    ret += v[n]-v[a-1]; //cover x
    ret += v[b]; //cover y

    ret -= min(2*x + y, 2*y + x);
    
    if (a == b)
    {
        return v[n] - min({2*x + y, 2*y + x, xVal[n], c-xVal[1]});
    }
    
    return ret;
}

ll solve()
{
    ll ret = 0;
    
    for (int a = 0; a <= n+1; a++) //fix A
    {
        ret = max(ret, calc(a,f[a]));
        ret = max(ret, calc(a,f2[a]));
        
        //cout << a << ' ' << f[a] << '\n';
        //cout << calc(a, f[a]) << "\n\n";
    }

    return ret;
}

int main()
{
    //ifstream inf("");
    //ofstream outf("");
    //cout << setprecision(10);
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> c;
    
    for (int i = 1; i <= n; i++) cin >> xVal[i] >> v[i];
    for (int i = 1; i <= n; i++) v[i] += v[i-1];
    xVal[n+1] = c;
    xVal[0] = 0;
    
    
    ll mx = 0;
    int w = 0; //best choice for B
    for (int i = 0; i <= n+1; i++)
    {
        ll cur = v[i]-xVal[i];
        f[i] = w;
        if (cur > mx)
        {
            mx = cur;
            w = i;
        }
    }
    
    mx = 0;
    w = 0; //best choice for B
    for (int i = 0; i <= n+1; i++)
    {
        ll cur = v[i]-2*xVal[i];
        f2[i] = w;
        if (cur > mx)
        {
            mx = cur;
            w = i;
        }
    }
    
    cout << solve() << '\n';
    
    return 0;
    
}
