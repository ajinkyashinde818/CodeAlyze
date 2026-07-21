#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int n,r; cin>>n>>r;
    if(n>=10){
        cout<<r<<endl;
    }else{
        cout<<r+100*(10-n)<<endl;
    }
    
}
