#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    long long int a,b,i,z=0,c=1,j,n,t;
    cin>>a>>b;
    if(a<10)
    {
        j=100*(10-a);
        printf("%lld\n",j+b);
    }
    else printf("%lld\n",b);
}
