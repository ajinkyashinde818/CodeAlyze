#include <stdio.h>


int main(){

  int i,j,n,m;
  long min = 100000000000,ans = -100000000000;
  scanf("%d",&n);

  for(i = 0;i < n;i++){
      scanf("%d",&m);
      if(m - min > ans ) ans = m - min;
      if(m < min) min = m;
  }

  printf("%ld\n",ans);

  return 0;
}
