#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K=1000000007;
ll gcd(ll a, ll b){
    ll c, d, e;
    while(b>0){
        d=a%b;
        e=a/b;
        c=b;
        b=d;
        a=c;
    }
    return a;
}

int main (){
    ll N;
    cin>>N;
    vector<ll> Vec(N);
    int Mainasu=0;
    ll Saishou=1000000000;
    ll Sum=0;
    for(ll i=0; i<N; i++){
        cin>>Vec.at(i);
        if(Vec.at(i)<0){
            Mainasu ++;
        }
        ll ABS=abs(Vec.at(i));
      	Sum += ABS;
        Saishou=min(Saishou, ABS);
    }
  	//無駄な分岐
    if(Saishou==0){
        cout<<Sum;
    }
    else if(Mainasu%2==0){
        cout<<Sum;
    }
    else{
        cout<<Sum-2*Saishou;
    }
    
}
