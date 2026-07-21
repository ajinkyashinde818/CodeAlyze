#include <stdio.h>
#define MOD 1000000007
#define MAX (int)10e6+1

int main(){
  int n,t=0,
      i;
  long long res=1;
  char c[MAX];
  
  scanf("%d",&n);
  scanf("%s",&c);
  
  for(i=0;i<2*n;i++){
    if((i%2==0 && c[i]=='B') || (i%2==1 && c[i]=='W')){
      if(2*n-i == t){
        printf("0\n");
        return 0;
      }
      t++;
    }else{
      if(t==0){
        printf("0\n");
        return 0;
      }
      res *= t;
      res %= MOD;
      t--;
    }
  }
//  printf("%lld\n",res);
  
  for(i=1;i<=n;i++){
    res *= i;
    res %= MOD;
  }
  
  printf("%lld\n",res);
  return 0;
}
