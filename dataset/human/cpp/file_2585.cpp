#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    long long a[100005],b[100005],n;
    cin>>n;
    long long sum=0;
    int cis=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]<0)
            cis++;
        b[i]=abs(a[i]);
        sum+=b[i];
    }
    sort(b,b+n);
    if(cis%2==0)
        cout<<sum<<endl;
    else
        cout<<sum-b[0]-b[0]<<endl;
    return 0;
}
