#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    long long n,i,s,r,min1,min2;
    cin>>n;
    int a[n];
    for(i=0,s=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    s=s-a[0];r=a[0];
    min1=llabs(s-r);
    for(i=1;i<n-1;i++)
        {
           r=r+a[i];s=s-a[i];
           min2=llabs(s-r);
           if(min1>min2) min1=min2;
        }
    cout<<min1;
    return 0;
}
