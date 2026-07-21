#include<stdio.h>
int main(){
  int a,i,j=1;
  int ans[100000];
  while(1){
    scanf("%d",&a);
    if(a==0){
      break;
    }
    ans[j]=a;
    j++;
  }
  for(i=1;i<j;i++){
    printf("Case %d: %d\n",i,ans[i]);
  }
  return(0);
}
