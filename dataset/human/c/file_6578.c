#include<stdio.h>
#define N 200000
int main(){
  int n,i,j,maxv,minv;
  int data[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  maxv=data[1]-data[0];
  minv=data[0];
  for(j=1;j<n;j++){
    if(maxv<data[j]-minv){
      maxv= data[j]-minv;
    }
    if(minv>data[j]){
      minv=data[j];
    }
  }
  printf("%d\n",maxv);
  return 0;
}
