#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <list>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define crep(i) for(char i='a';i<='z';i++)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define ALL(x) (x).begin(),(x).end()
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
using namespace std;
using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    ll sumation=0;
    for(int i=0; i<N; i++){
        cin >> a[i];
        sumation+=a[i];
    }
    ll sum1=a[0], sum2=sumation-sum1;
    ll ans=llabs(sum1-sum2);
    for(int i=1; i<N-1; i++){
        sum1+=a[i];
        sum2-=a[i];
        ll tmp=llabs(sum1-sum2);
        ans=min(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}
