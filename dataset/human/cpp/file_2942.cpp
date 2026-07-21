#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
using namespace std;
using ll = long long;
const int mod = 1000000007;


int main(){
    ll N;
    cin>>N;
    vector<ll> A(N);
    ll minus=0;
    ll res=0;
    ll _min=(ll)2e9;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0){
            minus++;
        }
        res+=abs(A[i]);
        _min = min(_min,abs(A[i]));
    }
    if(minus%2==0){
        cout<<res<<endl;
        return 0;
    }

    
    cout<<res-2*_min<<endl;

}
