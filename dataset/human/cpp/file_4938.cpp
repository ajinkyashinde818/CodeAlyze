#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
using ll = long long;
using plong = pair<ll,ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll N,R;
    cin>>N>>R;
    ll res;
    if(N>=10){
        res=R;
    }else{
        res=R+100*(10-N);
    }
    cout<<res<<endl;

}
