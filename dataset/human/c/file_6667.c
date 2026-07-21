#include<stdio.h>

int main(){
  int A[200000],i,j,n,min=999999999,max=-999999999,sa;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  min=A[0];
  for(i=1;i<n;i++){
    sa=A[i]-min;
    if(max<sa)max=sa;
    if(min>A[i])min=A[i];
  }
  printf("%d\n",max);
  return 0;
}
