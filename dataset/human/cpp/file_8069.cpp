#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
const int INF = 0x7f7f7f7f;
typedef long long ll;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    ll sum=0,tem=0;
    ll minn=INF;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        tem+=a[i];
        ll rem=sum-tem;
        if(abs(rem-tem)<minn)
        {
            minn=abs(rem-tem);
        }
    }
    cout << minn << endl;
    return 0;
}
