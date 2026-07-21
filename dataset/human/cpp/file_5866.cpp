#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
   ll N, C, x[100000], v[100000];
   scanf("%lld%lld", &N, &C);
   for(ll i = 0; i < N; i++) scanf("%lld%lld", &x[i], &v[i]);
   ll smax[2][2][100000];
   for(ll i = 0; i < N; i++) smax[0][0][i]=smax[0][1][i]=smax[1][0][i]=smax[1][1][i]=0;
   ll cal = v[0];
   smax[0][0][0] = max((ll) 0, cal - x[0]);
   smax[0][1][0] = max((ll) 0, cal - 2*x[0]);
   for(ll i = 1; i < N; i++){
      cal += v[i];
      smax[0][0][i] = max(smax[0][0][i-1], cal - x[i]);
      smax[0][1][i] = max(smax[0][1][i-1], cal - 2*x[i]);
   }
   cal = v[N-1];
   smax[1][0][N-1] = max((ll) 0, cal - (C - x[N-1]));
   smax[1][1][N-1] = max((ll) 0, cal - 2 * (C - x[N-1]));
   for(ll i = N-2; i >= 0; i--){
      cal += v[i];
      smax[1][0][i] = max(smax[1][0][i+1], cal - (C - x[i]));
      smax[1][1][i] = max(smax[1][1][i+1], cal - 2 * (C - x[i]));
   }
   ll ans = max(smax[0][0][N-1], smax[1][0][0]);
   for(ll i = 0; i < N-1; i++){
      ans = max(ans, max(smax[0][0][i]+smax[1][1][i+1], smax[0][1][i]+smax[1][0][i+1]));
   }
   printf("%lld\n",ans);
}
