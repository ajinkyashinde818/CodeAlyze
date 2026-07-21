#include <stdio.h>
#define MOD (int)(1e9+7)
typedef long long ll;

int re(ll a){
  int m=MOD-2;
  ll res=1;
  while(m){
    if(m%2){
      res = res*a%MOD;
    }
    m /= 2;
    a = a*a%MOD;
  }
  return res;
}

int main(){
  int x,y;
  long long ans=1;
  
  scanf("%d%d",&x,&y);  
  if(x>y){int t=y;y=x;x=t;}
  if(2*x<y||(2*x-y)%3){printf("0\n");return 0;}
  
  int t = (2*x-y)/3;
  int sum = 2*t+(y-x);
  for(int i=0;i<t;i++){
    ans = ans*(sum-i)%MOD;
    ans = ans*re((ll)i+1)%MOD;
  }
  printf("%lld\n",ans);
  return 0;
}
