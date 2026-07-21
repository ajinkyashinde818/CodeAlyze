#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    scanf("%d",&n) ;
    int a[n] , neg = 0 ;
    long long int ans = 0 ;
    for(int i = 0 ; i < n ; ++i) scanf("%d",&a[i]) ;
    for(int i = 0 ; i < n ; ++i)
    {
        if(a[i]<0) a[i]*=-1 , ++neg ;
        ans += a[i] ;
    }
    if(neg%2)
    {
        int mn = 1e9 + 1 ;
        for(int i = 0 ; i < n ; ++i) mn = min(a[i],mn) ;
        printf("%lld\n",ans-(2*mn)*1LL) ;
    }
    else printf("%lld\n",ans) ;
  
    return 0;
}
