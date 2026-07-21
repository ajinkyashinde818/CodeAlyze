#include<stdio.h>

int main(){
  long int i,N,ans;
  scanf("%ld",&N);
  if(N%2==1)
    printf("0\n");
  else{
    ans=0;
    for(i=10;i<1000000000000000000;i=i*5){
      ans=ans+N/i;
    }
    printf("%ld\n",ans);
  }
  return 0;
}
