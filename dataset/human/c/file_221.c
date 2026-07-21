#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
int main(){
  long long n,x=1e9,y=1e9,i,a,s=0,c=0;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a);
    if(a<0){
      x=MIN(x,-a);
      s-=a;
      c++;
    }
    else{
      y=MIN(y, a);
      s+=a;
    }
  }
  if(c%2)s-=2*MIN(y,x);
  printf("%lld\n",s);
  return 0;
}
