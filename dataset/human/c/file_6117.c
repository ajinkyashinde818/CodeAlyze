#include<stdio.h>
#define N 200000

int main(){
  int n,nn[N],maxv,minv,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&nn[i]);
  }

  maxv = nn[1]-nn[0];
  minv = nn[0];
  
  for(j=1;j<n;j++){
    if(maxv<nn[j]-minv){
      maxv=nn[j]-minv;
    }
    if(minv>nn[j]){
      minv=nn[j];
    }
  }
  
  printf("%d\n",maxv);
  return 0;
}
