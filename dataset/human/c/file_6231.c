#include <stdio.h>
int main(void){
  int n,r[200000];
  int i,j;
  int min;
  int MAX;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&r[i]);
  min=r[0];
  MAX=r[1]-min;
  for(j=1;j<n;j++){
    if(MAX<r[j]-min) MAX=r[j]-min;
    if(min>r[j]) min=r[j];
  }
  printf("%d\n",MAX);
  return(0);
}
