#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<long> s(n+1);
    for(int i=0; i<n; ++i) {
        cin>>s[i+1];
        s[i+1]+=s[i];
    }

    long res=LONG_MAX;
    for(int i=1; i<n; ++i)
        res=min(res, abs(s[n]-2*s[i]));
    cout<<res<<endl;
}
