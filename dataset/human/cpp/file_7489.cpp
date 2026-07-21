#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    long long int a[200000],mi=100000000000,n,sum1=0,sum2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum1+=a[i];
    }
    for(int i=n-1;i>0;i--)
    {
        sum1-=a[i];
        sum2+=a[i];
        if(abs(sum1-sum2)<mi)
        {
            mi=abs(sum1-sum2);
        }
    }
    cout<<mi<<endl;

}
