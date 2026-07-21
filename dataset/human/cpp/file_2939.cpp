#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
vector<int> anscands;
ll N;
ll A[100005];
ll ans=0;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
  std::fill( (T*)array, (T*)(array+N), val );
}
int main(void)
{
  cin >> N;
  ll dp[100005][2];
  Fill(dp,-1);
  dp[0][0]=0;
  for (int i = 1; i <= N; ++i)
    {
      cin >> A[i];
    }
  for (int i = 1; i < N; ++i)
    {
      if(i==1)
	{
	  dp[i][0]=A[i]+A[i+1];
	  dp[i][1]=-1*A[i]+(-1*(A[i+1]));
	}
      else
	{
	  dp[i][0]=max(dp[i-1][0]+A[i+1],dp[i-1][1]+A[i+1]);
	  dp[i][1]=max(dp[i-1][0]+(-2*A[i]+(-1*A[i+1])),dp[i-1][1]+(2*A[i]+(-1*A[i+1])));
	}
    }
  cout << max(dp[N-1][0],dp[N-1][1]) << endl;
}
