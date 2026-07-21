#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

long long int a[200010];

int main()
{
    int n,i;
    while(cin>>n)
    {
        long long int x,y,s=0,min1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s=s+a[i];
        }
        x=a[0];
        y=s-x;
        min1=fabs(x-y);
        for(i=1;i<=n-2;i++)
        {
            x=x+a[i];
            y=s-x;
            if(min1>fabs(x-y))
            {
                min1=fabs(x-y);
            }
        }
        cout<<min1<<endl;
    }
    return 0;
}
