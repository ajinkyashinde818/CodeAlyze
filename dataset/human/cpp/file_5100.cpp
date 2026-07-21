#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll x,flag,i,t,ans=0,j,k,l,n;
    scanf("%lld %lld",&n,&k);
    if(n<=10)
    {
        ans=k+(10-n)*100;
    }
    else
    {
        ans=k;
    }
    printf("%lld\n",ans);
}
