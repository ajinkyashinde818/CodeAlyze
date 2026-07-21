#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 100+100;
const ll mod = 1e9+7;
int b[maxn];
int main() {
    ios::sync_with_stdio(0);
    int n,r;
    cin>>n>>r;
    if(n>=10)
        cout<<r<<endl;
    else
        cout<<r+(10-n)*100<<endl;

}
