#include<stdio.h>
#include<math.h>
int main(){
  int n,r[200000],i,j,max,min;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  max=-1000000000;
  min=r[0];
  for(i=1;i<n;i++){
    max=max>r[i]-min ? max:r[i]-min;
    min=min<r[i] ? min:r[i];
  }
  printf("%d\n",max);
  return(0);
}
