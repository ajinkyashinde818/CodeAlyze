#include<stdio.h>
int main(){
  int i,a,b,k;
  scanf("%d %d %d",&a,&b,&k);
  for(i=(a>b)?a:b;i>0;i--){
    if(a%i==0 && b%i==0){
      k--;
      if(k==0)
        break;
    }
  }
  printf("%d\n",i);
  return 0;
}
