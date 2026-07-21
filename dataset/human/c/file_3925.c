#include<stdio.h>
int main(){
  int a,b,k,i,count=0;
  scanf("%d%d%d",&a,&b,&k);
  for(i=a;i>=1;i--){
    if(a%i==0 && b%i==0)
      count++;
    if(count==k){
      printf("%d\n",i);
      break;
    }
  }
  return 0;
}
