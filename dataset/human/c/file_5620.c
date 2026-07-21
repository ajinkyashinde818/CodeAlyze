#include <stdio.h>

int main(){

  long long int x,r,tmp,count,ans;

  scanf("%lld",&x);

  if(x<=6){
    ans=1;
  }else if(x>6 && x<=11){
    ans=2;
  }else{
    tmp=x/11;
    r=x%11;
    if(r==0){
      count=0;
    }else if(r<=6){
      count=1;
    }else{
      count=2;
    }
    ans=tmp*2+count;
  }
  printf("%lld\n",ans);
  return 0;
}
