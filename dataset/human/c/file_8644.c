#include<stdio.h>
int main(){
  int n,a[100001],i,k=0;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  for(i=0; i<n+1; i++){
    k=a[k]-1;
    if(k==1){
      printf("%d\n",i+1);
      return 0;
    }
  }

  printf("-1\n");
  return 0;
}
