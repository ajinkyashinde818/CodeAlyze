#include<stdio.h>
int main(){
  long long int decide=0,i,v,r,w,dif,b,a,x,y,mod=1000000007,ans,dif2,fac[1000010],finv[1000010],inv[1000010];
  scanf("%lld %lld\n",&x,&y);
  if(x>y){
    dif=x-y;
    v=dif;
    a=x-2*dif,b=y-dif;
    if(a>=0 && a==b && a%3==0){
      dif2=a/3;
    }
    else{
      printf("0\n");
      decide=1;
    }
  }
  else{
    dif=y-x;
    v=dif;
    a=x-dif,b=y-2*dif;
    if(a>=0 && a==b && a%3==0){
      dif2=a/3;
    }
    else{
      printf("0\n");
      decide=1;
    }
  }
    v=v+2*dif2;
    r=dif2;
    fac[0]=1,fac[1]=1;
    finv[0]=1,finv[1]=1;
    inv[1]=1;
    for(i=2;i<=666666;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
    }
    ans=fac[v]*(finv[r]*finv[v-r]%mod)%mod;
  if(decide==0){
    printf("%lld\n",ans);
  }
  return 0;
}
