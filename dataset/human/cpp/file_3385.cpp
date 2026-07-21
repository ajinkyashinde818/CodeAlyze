#include <iostream>
#include <algorithm>
using namespace std;

int a[100010];

int main()
{
    int n; cin>>n;
    long res=0;
    int c=0, mina=2e9;
    for(int i=0; i<n; ++i) {
        cin>>a[i];
        res+=abs(a[i]);
        c+=a[i]<0;
        mina=min(mina, abs(a[i]));
    }
    if (c%2) res-=2*mina;
    cout<<res<<endl;
}
