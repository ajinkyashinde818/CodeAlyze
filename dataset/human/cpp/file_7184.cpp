#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long s,x,t;
    cin>>n;
    int * a=new int[n];
    long long * b=new long long[n];
    s=0;
    x=0;
    t=99999999999999999999999999999;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        x+=a[i];
        b[i]=(long long)abs(s-2*x);
        if(t>b[i])
            t=b[i];
    }
    cout<<t<<endl;
    delete  a;
    delete  b;
    return 0;
}
