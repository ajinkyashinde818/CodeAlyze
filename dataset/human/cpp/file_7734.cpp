#include <iostream>
#include <cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define NIL -1
const int MOD = 1e9+7;
const int INF = 1 << 29;
const ll INFTY=1000000000000000000LL;
ll n,a[MAX_N];
int main(){
    cin>>n;rep(i,n)cin>>a[i];
    ll sum=0;
    rep(i,n)sum+=a[i];
    ll left[n];
    left[1]=a[0];
    for(int i=1;i<n;i++){
        left[i+1]=left[i]+a[i];
    }
    ll min=INFTY;
    for(int i=1;i<n;i++){
        ll dif=abs(sum-left[i]-left[i]);
        if(min>dif)min=dif;
    }
    cout<<min<<endl;
}
