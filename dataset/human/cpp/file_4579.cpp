#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
int main(){
    int n,r;
    cin>>n>>r;
    if(n<10){
        cout<<r+(100*(10-n))<<endl;
    }else cout<<r<<endl;
}
