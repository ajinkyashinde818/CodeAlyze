#include<stdio.h>
#include<stdlib.h>
int main(){
  long long n,d[100010],min,max,mi=0,ma=0,s=0,i;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&d[i]);
    s+=labs(d[i]);
    if(d[mi]>d[i])mi=i;
    if(mi==ma||d[ma]<d[i])ma=i;
  }
  if(d[mi]>0)s-=d[mi]+d[mi];
  if(d[ma]<0)s+=d[ma]+d[ma];
  printf("%lld\n",s);
  max=d[ma];
  min=d[mi];
  for(i=0;i<n;i++){
    if(i==mi||i==ma)continue;
    if(d[i]>0){
      printf("%lld %lld\n",min,d[i]);
      min-=d[i];
    }
    else{
      printf("%lld %lld\n",max,d[i]);
      max-=d[i];
    }
  }
  printf("%lld %lld\n",max,min);
  return 0;
}
