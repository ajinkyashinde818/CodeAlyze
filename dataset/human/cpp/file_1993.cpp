#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

ll minll(ll a, ll b){
    if(a >= b)  return b;
    else    return a;
}

ll maxll(ll a, ll b){
    if(a >= b)  return a;
    else    return b;
}

ll n;
const int SIZE = 2e5+10;
ll a[SIZE];
ll cou;

int main(){
    cin >> n;
    ll min_num = LL_INF;
    ll ans = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) ++cou;
        ans += abs(a[i]);
        min_num = min(abs(a[i]),min_num);
    }
    if(cou % 2 != 0){
        ans -= 2*min_num;
    }

    cout << ans << endl;
}
