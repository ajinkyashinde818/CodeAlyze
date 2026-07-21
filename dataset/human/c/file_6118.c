#include <stdio.h>

#define N 200000
#define M 1000000000

int main(){
  int n,i,minv,maxv,R[N];
  
  while(1){
    scanf("%d",&n);
    if(2 <= n && n <= N) break;
  }
  for(i = 0;i < n;i++){
    scanf("%d",&R[i]);
    if(R[i] < 1 || M < R[i]) i = i - 1;
  }
  minv = R[0];
  maxv = (-1)*M;
  for(i = 1;i < n;i++){
    if(maxv < R[i]-minv) maxv = R[i]-minv;
    if(minv > R[i]) minv = R[i];
  }
  printf("%d\n",maxv);

  return 0;
}
