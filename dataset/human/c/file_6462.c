#include <stdio.h>
#include <stdlib.h>
#define N 200000
#define M 10*10*10*10*10*10*10*10*10
int max(int x,int y);
int min(int x,int y);
int main(){
  int i,j,n;
  int R[N];
  int minv;
  int maxv;
  scanf("%d",&n);
  if(n < 2 || n > N) exit(1);
  for(i=0;i<=n-1;i++){
    scanf("%d",&R[i]);
    if(R[i] < 1 || R[i] > M) exit(2);
  }
  minv = R[0];
  maxv = R[1]-R[0];
  for(j=1;j<=n-1;j++){
    maxv = max(maxv,R[j]-minv);
    minv = min(minv,R[j]);
  }
  printf("%d\n",maxv);
  return 0;
}

int max(int x,int y){
  if(x>y) return x;
  else return y;
}

int min(int x,int y){
  if(x<y) return x;
  else return y;
}
