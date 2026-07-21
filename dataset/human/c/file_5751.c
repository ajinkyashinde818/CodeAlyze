#include<stdio.h>
#include<math.h>

#define INF -999999999
typedef long int ll;

ll max(ll a, ll b);
ll min(ll a, ll b);

int main()
{
  int n;
  int i;
  int prof[200001];
  ll ans = 0;
  
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&prof[i]);
  }
  
  ll minv = prof[0];
  ll maxv = INF;
  for(i = 1;i < n;i++){
    maxv = max(maxv, prof[i]-minv);
    minv = min(minv, prof[i]);
  }
  
  printf("%ld\n",maxv);
  return 0;
}

ll max(ll a, ll b)
{
  if(a < b) return b;
  else return a;
}
ll min(ll a, ll b)
{
  if(a < b) return a;
  else return b;
}
