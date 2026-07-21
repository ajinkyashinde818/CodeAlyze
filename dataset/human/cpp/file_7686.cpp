#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define in(x) cin >> x
#define out(str) cout << str << endl

#define mod 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N;
long long sum=0,sum2=0,mini;

int main(){
    cin>>N;
    int a[N];
    rep(i,N){
        cin>>a[i];
        sum+=a[i];
    }
    mini=abs(sum-2*a[0]);
    rep(i,N-1){
        sum2+=a[i];
        mini=min(mini,abs(sum-2*sum2));
    }
    out(mini);
    return 0;
}
