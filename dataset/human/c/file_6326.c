#include <stdio.h>
int main(){
  int minv,maxv,n,i,R[1000001];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  minv = R[0];
  maxv = R[1]-R[0];
  
  for(i=1;i<n;i++){
    if(maxv >=  R[i]-minv) maxv = maxv;
    else maxv =  R[i]-minv;
    if(minv <=  R[i]) minv = minv;
    else minv =  R[i];
  }
 
  printf("%d\n",maxv);

  return 0;
}
