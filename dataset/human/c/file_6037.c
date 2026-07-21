#include<stdio.h>
#define N 200000
int main(){
  int n,i,j,R_t[N];
  int minv,maxv;
  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&R_t[i]);

  minv=R_t[0];//??????
  maxv=R_t[1]-R_t[0];//????????????

  for(j=1;j<n;j++){
    if(maxv<R_t[j]-minv)maxv=R_t[j]-minv;
    if(minv>R_t[j])minv=R_t[j];

  }
  printf("%d\n",maxv);

  return 0;
}
