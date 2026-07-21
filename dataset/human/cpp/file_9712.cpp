#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <cmath>
#include <deque>
#include <bitset>
#define ll long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x);
#define readll(x) cin>>x;
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define MP make_pair
#define PB push_back
#define pii pair<int,int>
#define readN(N,X) for(int i=0;i<N;i++) cin>>X[i];
#define pff pair<double,double>
#define MOD 1000000007
using namespace std;
int cnt[333];
string S;
int N;
int main(){
   std::ios::sync_with_stdio(false); 
   cin>>N;
   cin>>S;
   long long res = 0;
   for (int i=0;i<N;i++)
      cnt[S[i]]++;

   res = 1;
   for (int i=0;i<=300;i++){
     res = (res * (cnt[i] + 1)) % MOD;
   }

   res = (res - 1 + MOD) % MOD;
   cout<<res<<endl;

}
