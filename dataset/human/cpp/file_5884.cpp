#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
int N;
ll C;
ll sushisum=0;
ll Csushisum=0;
ll ans=0;
ll ans2=0;
ll x[100005];
ll v[100005];
ll f[100005];
ll g[100005];
ll B[100005];
ll A[100005];
ll Cf[100005];
ll Cg[100005];
int main(void)
{
  cin >> N >> C;
  for (int i = 1; i <= N; ++i)
    {
      cin >> x[i] >> v[i];
    }
  for (int i = 0; i <= N+1; i++)
    {
      sushisum+=v[i];
      A[i]=sushisum-x[i];
      if(i==N+1 || i==0) A[i]=0;
      //cout << "A " << i << ' ' << sushisum << ' ' << A[i] << endl;
    }
  //cout << endl;
  for (int i = N+1; i >= 0; i--)
    {
      Csushisum+=v[i];
      if(i==N+1 || i==0)
	{
	  B[i]=0;
	}
      else
	{
	  B[i]=Csushisum-(C-x[i]);
	}
      //cout << "B " << i << ' ' << Csushisum << ' ' << B[i] << endl;
    }
  Csushisum=0;
  sushisum=0;
  //cout << endl;
  for (int i = 0; i <= N; ++i)
    {
      sushisum+=v[i];
      f[i]=sushisum-x[i];
    }
  for (int i = N+1; i >= 0; i--)
    {
      Csushisum+=v[i];
      if(i==N+1 || i==0)
	{
	  Cf[i]=Csushisum;
	}
      else
	{
	  Cf[i]=Csushisum-(C-x[i]);
	}
    }
  for (int i = 0; i <= N+1; ++i)
    {
      if(i!=0 && i!=N+1)
	{
	  g[i]=max(g[i-1],f[i]);
	}
      else
	{
	  g[i]=max(0LL,f[i]);
	}
      //cout << "f g " << i << ' ' << f[i] << ' ' << g[i] << endl;
    }
  //cout << endl;
  for (int i = N+1; i >= 0; i--)
    {
      if(i!=N+1 && i!=0)
	{
	  Cg[i]=max(Cg[i+1],Cf[i]);
	}
      else
	{
	  Cg[i]=max(0LL,Cf[i]);
	}
      //cout << "Cf Cg " << i << ' ' << Cf[i] << ' ' << Cg[i] << endl;
    }
  //cout << endl;
  for (int i = 0; i <= N; ++i)
    {
      if(i!=0)
	{
	  if((g[i-1]-(C-x[i]))<=0)
	    {
	      ans=max(ans,B[i]);
	    }
	  else
	    {
	      ans=max(ans,B[i]+g[i-1]-(C-x[i]));
	    }
	  if((Cg[i+1]-x[i])<=0)
	    {
	      ans2=max(ans2,A[i]);
	    }
	  else
	    {
	      ans2=max(ans2,A[i]+Cg[i+1]-x[i]);
	    }
	}
      else
	{
	  ans=max(ans,0LL);
	  ans2=max(ans2,0LL);
	}
      //cout << ans << ' ' << ans2 << endl;
    }
  cout << max(ans,ans2) << endl;
  return 0;
}
