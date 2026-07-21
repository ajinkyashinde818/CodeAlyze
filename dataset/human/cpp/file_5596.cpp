//Moh_K_Imar .......
//22/08/2020  ... 12,42 .
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll a,b;
    cin>>a>>b;
    if(a>=10)cout<<b<<endl;
    else if(a<10){
        cout<<b+(100*(10-a));
    }


    return 0;
}
