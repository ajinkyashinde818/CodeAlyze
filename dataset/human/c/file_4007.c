#include<stdio.h>

int main(void){
  int a, b, k;
  int count, temp;
  
  scanf("%d%d%d", &a, &b, &k);
  
  for(temp=a,count=0; count<k; temp--){
    if((a%temp==0) && (b%temp==0)){
      count++;
    }
  }
  
  printf("%d\n", temp+1);
  
  return 0;
}
