/*
    Mbak Rose Dong
*/
#include<bits/stdc++.h>
using namespace std;
long long int arr[200200];
bool desc(long long int a, long long int b)
{
    return abs(a) < abs(b);
}
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m,inc=1;
    cin >> n;
    int neg = 0;
    long long int rose = 0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        rose += abs(arr[i]);
        neg += (arr[i] < 0);
    }
    sort(arr+1,arr+n+1,desc);
    if(neg % 2 == 1)
    {
        rose -= 2*abs(arr[1]);
    }
    printf("%lld\n",rose);
    return 0;
}
