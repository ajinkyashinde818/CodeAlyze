#include <bits/stdc++.h>

using namespace std;

int main() {
int n;
cin>>n;
long long a[n];
long long count=0;
for(int i=0;i<n;i++)
{cin>>a[i];
if(a[i]<0)
count++;
}
long long sum=0;
    long long min=1000000000000;
    for(int i=0;i<n;i++)
    {
        sum+=abs(a[i]);
        if(abs(a[i])<min)
        min=abs(a[i]);
        
    }
    if(count%2==0)
    cout<<sum;
    else
    cout<<sum-(2*min);
    
    
    return 0;
}
