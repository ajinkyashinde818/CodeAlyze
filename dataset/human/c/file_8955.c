#include<stdio.h>
#define N 100000

int main(void){
  int i,num,j;
  int n,ans[N];

  for(i=0;;i++){
    scanf("%d",&n);
    if(n==0)
      break;
    for(j=0;;j++){
      if(n==1){
        ans[i]=j;
        break;
      }
      if(n%2==0){
        n/=2;
      }else{
        n*=3;
        n++;
      }
    }
  }
  num=i;
  for(i=0;i<num;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}
