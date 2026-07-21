#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;
long long  a[200500];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        long long int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        long long int d=0;
        int t=0;
        ans+=a[0];
        d=abs(2*ans-sum);
        for(int i=1;i<n-1;i++)
        {
            ans+=a[i];
            if(abs(2*ans-sum)<d)
            {
                t=i;
                d=abs(2*ans-sum);
            }
        }
        cout<<d<<endl;
    }
    return 0;
}
