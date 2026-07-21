#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdio>
#include <iomanip>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>()>
#define pb push_back
#define vec vector<int>
#define vecvec vector<vector<int>>
#define vecll vector<ll>
#define vecvecll vector<vector<ll>>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
#define mp make_pair
using namespace std;
int in(){int x;scanf("%d",&x);return x;}
string stin(){string s;cin>>s;return s;}
ll lin(){ll x;scanf("%lld",&x);return x;}

int main(){
    int n=in();
    ll sum=0,mi=1000000;
    int cnt_n=0;
    rep(i,n){
        int a=in();
        sum+=abs(a);
        if(abs(mi)>abs(a))mi=abs(a);
        if(a<0)cnt_n++;
    }
    if(cnt_n%2==1)sum-=2*mi;
    cout<<sum<<endl;
}
