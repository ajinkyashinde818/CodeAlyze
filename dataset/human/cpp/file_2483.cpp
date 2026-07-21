#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(vector<ll> vec)
{
    ll pos_sum = 0;
    int cnt = 0;
    ll positive_min = INT_MAX;
    ll negtive_max = INT_MIN;
    ll neg_sum = 0;
    for(ll x:vec)
    {
        if(x<0)
            cnt++, neg_sum += x, negtive_max = max(negtive_max, x);
        else
            positive_min = min(positive_min,x), pos_sum += x;
    }
    if(cnt % 2 == 0)
    {
        return pos_sum - neg_sum;
    }
    return max(pos_sum - neg_sum - positive_min*2, pos_sum - neg_sum + negtive_max * 2);
}
int main()
{
    int n;
    cin>>n;
    vector<ll> dat(n);
    for(int i=0;i<n;++i)cin>>dat[i];
    cout<<solve(dat);
}
