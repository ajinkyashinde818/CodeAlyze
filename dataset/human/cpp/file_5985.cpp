#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int n;
ll c;
vector<p> x;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>c;
    for (int i = 0; i < n; i++)
    {
        ll tempx, tempv;
        cin >> tempx>>tempv;
        x.push_back(make_pair(tempx,tempv));
    }
    vector<ll> sumr, suml, sumbr, sumbl;
    sumr.push_back(0);
    suml.push_back(0);
    sumbr.push_back(0);
    sumbl.push_back(0);

    ll ans=0;
    for(int i=0;i<n;i++){
        sumr.push_back(sumr[i]+x[i].second);
        ans=max(ans,sumr[i+1]-x[i].first);
        sumbr.push_back(max(sumbr[i],sumr[i+1]-2*x[i].first));
    }
    //cout << ans << "\n";
    for(int i=0;i<n;i++){
        suml.push_back(suml[i]+x[n-1-i].second);
        ans=max(ans,suml[i+1]-(c-x[n-1-i].first));
        sumbl.push_back(max(sumbl[i],suml[i+1]-2*(c-x[n-1-i].first)));
    }
    //cout << ans << "\n";
    for(int i=1;i<n;i++){
        ans=max(ans,sumr[i]-x[i-1].first+sumbl[n-i]);
    }
    //cout << ans << "\n";
    for(int i=1;i<n;i++){
        //cout<<suml[i]-x[i-1].first+sumbr[n-i-1]<<"\n";
        ans=max(ans,suml[i]-(c-x[n-i].first)+sumbr[n-i]);
    }
    cout << ans << "\n";
}
