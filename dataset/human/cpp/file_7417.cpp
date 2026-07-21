#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
typedef long long LL;
LL a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        LL x;
        scanf("%lld", &x);
        a[i]=a[i-1]+x;
    }
    LL m=-1;
    for(int i=1;i<n;i++)
    {
        LL x=a[n]-a[i];
        LL y=abs(x-a[i]);
        if(m==-1||m>y) m=y;
    }
    cout<<m<<endl;
    return 0;
}
