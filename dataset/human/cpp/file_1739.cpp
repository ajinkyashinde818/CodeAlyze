#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    long x=1;
    for(; x*(x+1)<2*n; ++x);
    if (x*(x+1)!=2*n) {
        cout<<"No"<<endl;
        return 0;
    }

    auto y=x+1;
    vector<vector<int>> a(y, vector<int>(x));
    for(int r1=0, c1=0, r2=1, c2=0, i=1; i<=n; ++i) {
        a[r1][c1]=a[r2][c2]=i;
        c1++;
        if (c1==x) { r1++; c1=r1; }
        r2++;
        if (r2==y) { r2=r1+1; c2=c1; }
    }
    cout<<"Yes"<<endl;
    cout<<y<<endl;
    for(auto& v: a) {
        cout<<v.size();
        for(auto& e: v) cout<<' '<<e;
        cout<<endl;
    }
}
