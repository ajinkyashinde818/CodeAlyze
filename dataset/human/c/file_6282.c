#include <stdio.h>
int main(){
  int i,j,n,maxv=0,minj=0;
  scanf("%d",&n);
    int R[n];
  for(j=0;j<n;j++)
    {
      scanf("%d",&R[j]);
    }
  maxv=R[1]-R[0];
  minj=R[0];
  for(i=1;i<n;i++)
    {
      if(maxv<R[i]-minj) maxv=R[i]-minj;
      if(minj>R[i])minj=R[i];
    }
printf("%d\n",maxv);
return 0;
}
