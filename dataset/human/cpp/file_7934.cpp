#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,sum=0,y=0,m,diff,sum1=0;
    cin>>n;
    long long int a[n],x[n-1];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
        if(i!=n-1)
        {
            x[i]=sum;
        }
        sum1=sum1+abs(a[i]);
    }
    m=sum1;
    for(long long int i=0;i<n-1;i++)
    {
        y=sum-x[i];
        //cout<<x<<" "<<y<<endl;
        diff=abs(x[i]-y);
        //cout<<diff<<endl;
        if(m>diff)
            m=diff;
    }
    cout << m;
    return 0;
}
