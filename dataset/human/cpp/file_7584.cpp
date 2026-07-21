#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int inf = int (1e9) + int (1e5);
const ll infl = ll (2e18) + ll (1e10);
const ui M=1E9+7;
const double eps = 1e-9;

int main()
{
    std::ios_base::sync_with_stdio (false);
   // freopen ("in.txt", "r", stdin); /// indica que se lee desde stdin

    int n;
    cin >> n;
    ll a[n];
    vector<ll> s(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (i>0)
            s[i] = s[i-1] + a[i];
        else
            s[0]=a[0];
    }
    ll n2=s[n-1]/2;
    ll m=infl;
    int imin=0;
    for (int i=0;i<n-1;i++){
        if (abs(s[i]-n2)<m){
            m=abs(s[i]-n2);
            imin=i;
        }
    }
    cout << abs(s[imin] - (s[n-1]-s[imin]));

    return 0;
}
