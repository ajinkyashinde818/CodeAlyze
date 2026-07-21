#include<stdio.h>
#define ll long long

ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}

int main(){
  ll n,m,i,a[100005];
  scanf("%lld %lld",&n,&m);
  for(i=0;i<n;i++){
    scanf("%lld", &a[i]);
    a[i] /= 2;
  }
  ll l=a[0];
  for(i=0;i<n;i++) l *= a[i]/gcd(l,a[i]); // l = (lとa[i]の最小公倍数) => (最終的な l) = (全ての最小公倍数)
  for(i=0; i<n; i++){
    if(l/a[i]%2==0){
      printf("0\n");
      return 0;
    }
  }
  printf("%lld\n",(m/l+1)/2);//奇数である公倍数の数 *テクニック: (x+1)/2は繰り上がり
  return 0;
}
