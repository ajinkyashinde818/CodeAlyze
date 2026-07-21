#include<bits/stdc++.h>
using namespace std;
int N; long long C;
long long x[101010];
long long v[101010];
long long dpL[101010];
long long dpR[101010];
long long solve()
{
  memset(dpL, 0, sizeof dpL);
  
  long long sum = 0;
  for(int i=1; i<=N; ++i)
  {
    sum += v[i];
    dpL[i] = max(dpL[i-1], sum-2*x[i]);  
  }
  sum = 0;
  long long ans = 0;
  for(int i=N+1; i>=1; --i)
  {
    sum += v[i];
    ans = max(ans, dpL[i-1] + sum - (C-x[i]));
  }
  return ans;
}
int main()
{
  scanf("%d%lld", &N, &C);
  for(int i=1; i<=N; ++i)
    scanf("%lld%lld", x+i, v+i);
  x[N+1] = C; v[N+1] = 0;
  long long ans = solve();
  for(int i=1; i<=N; ++i) x[i] = C - x[i];
  reverse(x+1, x+N+1);
  reverse(v+1, v+N+1);
  ans = max(ans, solve());
  printf("%lld\n", ans);
  return 0;
}
