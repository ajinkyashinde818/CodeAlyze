#include<stdio.h>
int main(){
  int x[10000];
  int i,count=0;
  for(i=0;i<10000;i++){
    scanf("%d",&x[i]);
    if(x[i]==0) break;
    count++;
  }
  for(i=0;i<count;i++){
    printf("Case %d: %d\n",i+1,x[i]);
  }
  return 0;
}
