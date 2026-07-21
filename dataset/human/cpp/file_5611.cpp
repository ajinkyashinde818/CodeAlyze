//MohK
//22/02/2020 ..... 2,5.
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll a,b;
    cin>>a>>b;
    if(a>=10)cout<<b<<endl;
    else {
        ll c=100*(10-a);
        ll d=b+c;
        cout<<d<<endl;
    }

    return 0;
}
