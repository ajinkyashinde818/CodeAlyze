#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    long long  a[200005];
    while(cin>>n)
    {
        long long  sum=0,lsum=0,rsum,Min=10000000000;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        for(int i=0; i<n-1; i++)
        {
            lsum+=a[i];
            rsum=sum-lsum;
            if(Min>abs(lsum-rsum))
                Min=abs(lsum-rsum);
        }
        cout<<Min<<endl;
    }

    return 0;
}
