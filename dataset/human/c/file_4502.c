#include<stdio.h>

int main(void){
  int s,i,j,N,a[100],b[100],count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
     scanf("%d ",&a[i]); scanf("%d",&b[i]);
  }
  for(j=2;j<N;j++){
    if(a[j-2]==b[j-2]&&a[j-1]==b[j-1]&&a[j]==b[j])
      count=1;
  }
  if(count)
    printf("Yes\n");
  else
    printf("No\n");
  
  return 0;

}
