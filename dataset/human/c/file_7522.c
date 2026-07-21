#include<stdio.h>
#define NUM 15000
int main(void){
  int a[NUM],i=0;
  for(i=0;i<NUM;i++){
    scanf("%d",&a[i]);
    if(a[i]==0){
      break;
    }
  }
     for(i=0;i<NUM;i++){
    if(a[i]==0){
      break;
    }
    printf("Case %d: %d\n",i+1,a[i]);
  }
  return 0;
}
