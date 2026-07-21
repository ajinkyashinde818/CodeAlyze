#include<stdio.h>
int main(){
  int n=0,i=0,j=0;
  int R[200000];
  int max=0,min=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  max=-1000000000;
  min=R[0];
  for(j=1;j<n;j++){
      if(max<R[j]-min)max=R[j]-min;
      if(min>R[j])min=R[j];
  }
  printf("%d\n",max);
  return 0;
}
