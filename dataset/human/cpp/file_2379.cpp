#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    ll total = 0;
    bool zeroExist = false;
    int count = 0;
    int minNum = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            zeroExist = true;

        if(a[i]<0)
            count++;
        total += abs(a[i]);
        minNum = min(minNum,abs(a[i]));
    }

    if(zeroExist || count%2==0)
        cout << total << "\n";
    else
        cout << (total - 2*minNum) << "\n";

    return 0;
}
