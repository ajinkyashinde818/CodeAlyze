#include <stdio.h>
#include <stdlib.h>

int main(){
  int r[200000],n,maxv,minv,i;

  scanf("%d",&n);
  if(n<2||200000< n) exit(8); 

  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  
  maxv=r[1]-r[0];
  minv=r[0];
  
  for(i=1;i<n;i++){
    if(maxv<r[i]-minv) maxv=r[i]-minv;
    if(minv>r[i]) minv=r[i];
  }

  printf("%d\n",maxv);

  return 0;
}
