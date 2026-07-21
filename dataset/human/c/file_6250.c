#include <stdio.h>
#include <stdlib.h>
#define N_MAX 200000
#define RT_MAX 1000000000

int main(){
  int i,j,n,R[N_MAX],max=-RT_MAX,mi,d,db;
  scanf("%d",&n);
  if(n>N_MAX || n<2)exit(8);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
    if(R[i]>RT_MAX || R[i]<1)exit(8);
  }
  mi=R[0];
  for(j=1;j<n;j++){
    d=R[j]-mi;
    if(d>max)max=d;
    if(R[j]<mi)mi=R[j];
  }
  printf("%d\n",max);
  return 0;
}
