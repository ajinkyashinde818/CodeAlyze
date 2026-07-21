#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[100010];
long long ans;

int main()
{
    int n,i,t=1e9,num=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0) num++;
        if(t>abs(a[i])) t=abs(a[i]);
        ans+=abs(a[i]);
    }
    if(num%2!=0) ans-=2*t;
    cout << ans << endl;
    return 0;
}
