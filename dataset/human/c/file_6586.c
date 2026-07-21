#include <stdio.h>

static const int N = 200000;

int main(){
  int n,i,j, R[N];
  int maxv,minv;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&R[i]);

    minv = R[0];
    maxv = R[1]-R[0];

    for(i=1;i<n;i++){
      if(R[i]-minv>maxv) maxv = R[i]-minv;
      if(R[i]<minv) minv = R[i];
    }


  printf("%d\n",maxv);

  return 0;
}
