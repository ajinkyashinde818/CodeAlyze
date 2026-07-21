#include<stdio.h>
int main(){
int n,i=1,j,a[100002];
  scanf("%d",&n);
  for(j=1;j<=n;j++)scanf("%d",&a[j]);
  for(j=1;j<=n;j++){
    i=a[i];
    if(i==2){
    printf("%d",j);
      return 0;
    }  
  
  }
  printf("-1");
  return 0;

}
