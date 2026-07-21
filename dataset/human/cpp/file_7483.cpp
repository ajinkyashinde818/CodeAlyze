#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> ar(n);
    long long sum=0,x=0,mn=1000000000000000000LL;
    for(int i=0;i<n;i++)
    {
        cin >> ar[i];
        sum+=ar[i];
    }
    for(int i=0;i<n-1;i++)
    {
        x+=ar[i];
        mn = min(mn, abs(sum-2*x));
    }
    cout << mn << endl;

}
