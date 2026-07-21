#include<stdio.h>

int main() {
  int n,R[200000],minv,maxv,j;
   while(1) {
  scanf("%d",&n);
    if(2 <= n || n <= 200000) break;
   }
  for(j = 0;j < n;j++) {
    scanf("%d",&R[j]);
    if(1 > R[j] || R[j] > 1000*1000*1000) j=j-1;
  }
  maxv = R[1]-R[0];
  minv = R[0];
  
  for(j=1;j<=n-1;j++) {
    if(maxv > R[j]-minv) maxv = maxv;
    else maxv = R[j]-minv;
    if(minv < R[j]) minv =minv;
    else minv = R[j];
  }
  printf("%d\n",maxv);
  return 0;
}
