#include<stdio.h>
int main(){
  int n[10000],i,j;

  for(i=0;i<10000;i++){
    scanf("%d",&n[i]);
    if(n[i] == 0) break;
  }
  for(j=0;j<i;j++){
    printf("Case %d: %d\n",j+1,n[j]);
  }
  return 0;
}
