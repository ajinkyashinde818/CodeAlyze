#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll R,G,B,N;
    cin>>R>>G>>B>>N;
    
    //rR+bB+gG=N;
    
    ll ans=0;
    for(ll r=0;r*R<=N;r++){
        for(ll g=0;r*R+g*G<=N;g++){
            if((N-r*R-g*G)%B==0)ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
