#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(a) (a).begin(),(a).end()
#define PRINT(V) for(auto v:(V))cout<<v<<" "<<endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
const ll MOD = 1000000007;
    
int main()
{
    int N;
    cin >> N;
    vll A(N);
    bool z = false;
    rep(i, N)
    {
        cin >> A[i];
        if(!A[i]) z = true;
    }
    if(z)
    {
        ll ans = 0;
        rep(i, N)
        {
            ans += abs(A[i]);
        }
        cout << ans << endl;
    }
    else
    {
        ll ans = 0;
        ll minabs = 1LL << 60;
        ll minabsi = 0;
        ll mc = 0;
        rep(i, N)
        {
            if(abs(A[i]) < minabs)
            {
                minabs = abs(A[i]);
                minabsi = i;
            }
            if(A[i] < 0) mc++;
        }
        if(mc % 2 == 0)
        {
            rep(i, N)
            {
                ans += abs(A[i]);
            }
        }
        else
        {
            rep(i, N)
            {
                if(i == minabsi)
                {
                    ans -= abs(A[i]);
                }
                else
                {
                    ans += abs(A[i]);
                }
            }
        }
        cout << ans << endl;
    }
}
