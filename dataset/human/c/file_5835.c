#include <stdio.h>
#define N 200000
long jud_big(long,long);
long jud_small(long,long);
int main(){
  int i,j,n;
  long minv,maxv,R[N];
  
    scanf("%d",&n);
  for(j=0;j<n;j++)scanf("%ld",&R[j]);
  
maxv = R[1]-R[0];
  minv = R[0];
  for(i=1;i<n;i++){
      maxv = jud_big(maxv,R[i]-minv);
      minv=jud_small(minv,R[i]);
    }
  printf("%ld\n",maxv);
  return 0;
}

long jud_big(long a, long b){
  if(a >= b)return a;
  else return b;
}

long jud_small(long a,long b){
  if(a>=b)return b;
  else return a;
}
