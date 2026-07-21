#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;
typedef long long ll ;

ll a[200010] ;

int main()
{
    ll n ;
    scanf("%lld",&n) ;
    ll sum=0 ;
    for (int i=0 ; i<n ; i++)
    {
        scanf("%lld",&a[i]) ;
        sum+=a[i] ;
    }
    ll csum=0 ;
    ll ans=1000000000000 ;
    for (int i=0 ; i<n-1 ; i++)
    {
        csum+=a[i] ;
        sum-=a[i] ;
        ll def=abs(csum-sum) ;
        ans=min(ans,def) ;
    }
    printf("%lld\n",ans) ;
    return 0;
}
