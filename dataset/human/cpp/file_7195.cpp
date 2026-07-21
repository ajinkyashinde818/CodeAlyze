#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7; 
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    long long count=0;
    long long a[N];
    long long  minn=1e15; 
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    count+=a[1]; 
    for(int i=2;i<=n;i++)
    {
        minn=min(minn,abs(sum-count*2));
        count+=a[i];
    }
    cout<<minn<<endl;
    return 0;
}
