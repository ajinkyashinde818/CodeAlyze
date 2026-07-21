#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
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
int n, a[200000];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n ;
    ll sum=0;
    ll sumsub[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        sumsub[i]=sum;
    }
    ll ans=INF;
    for(int i=0;i<n-1;i++){
        ans=min(ans,abs(2*sumsub[i]-sum));
    }
    cout<<ans<<"\n";
    /* sort(a,a+n);
    ll suma=a[n-1];
    ll sumb=0;
    for(int i=n-2;i>=0;i--){
        if(suma>=sumb){
            sumb+=a[i];
        }
        else{
            suma+=a[i];
        }
    }
    cout << abs(suma-sumb)<< "\n";
    */
}
