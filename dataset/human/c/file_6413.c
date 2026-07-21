#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
  int *data;
  int maxv,minv,j,n;

  scanf("%d",&n);
  data=(int *)malloc(sizeof(int)*n);
  for(j=0;j<n;j++){
    scanf("%d",&data[j]);
  }
  maxv=-1*pow(10,9);
  minv=data[0];

  for(j=1;j<n;j++){
    if(maxv<data[j]-minv){
      maxv=data[j]-minv;
    }
    if(minv>data[j]){
      minv=data[j];
    }
  }

  printf("%d\n",maxv);

  return 0;
}
