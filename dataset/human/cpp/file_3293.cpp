#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long  n,m=0,k=0,i,x=1E10,sum=0,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y;
        if(y<0)
            m++;
        sum+=abs(y);

        x=min(abs(y),x);
    }
        if(m%2==0)
            cout<<sum<<endl;
        else
            cout<<sum-x*2<<endl;
    return 0;
}
