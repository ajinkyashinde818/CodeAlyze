#include<stdio.h>

int main(){
  int n,i,j,min,max,R[200000];
  
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%d",&R[j]);
  }

  min=R[0];
  max=R[1]-R[0];

  for(i=1;i<n;i++){
    if(max<(R[i]-min)) max=R[i]-min;
    if(min>R[i]) min=R[i];
  }

  printf("%d\n",max);

  return 0;
}
