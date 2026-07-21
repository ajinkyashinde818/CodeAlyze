#include <stdio.h>
#define INI -1000000000

int main()
{
  int i,n,k,maxv=INI,minv;

  scanf("%d%d",&n,&minv);

  for(i=1;i<n;i++){
    scanf("%d",&k);
    if(maxv<k-minv) maxv=k-minv; 
    if(k<minv) minv=k;
  }
  printf("%d\n",maxv);

  return 0;
}
