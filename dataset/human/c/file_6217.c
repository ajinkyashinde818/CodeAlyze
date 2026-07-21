#include<stdio.h>
#define N 200000

int main(void)
{
  int i,j,n;
  int rt[N];
  //int maxv=0;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &rt[i]);
  }

  int maxv = rt[1]-rt[0]; //最大利益
  int minv = rt[0]; //rt[j]の最小値

  for (i=1; i<=n-1; i++) {
    if(maxv<rt[i]-minv){
      maxv = rt[i]-minv;
    }else{
      maxv = maxv;
    }
    if (minv>rt[i]) {
      minv = rt[i];
    }else{
      minv = minv;
    }
  }

/*  for (i=1; i<=n-1; i++) {
    for (j=0; j<=i-1;j++) {
      if(maxv<rt[i]-rt[j]){
        maxv = rt[i]-rt[j];
      }else{
        maxv = maxv;
      }
    }
  }*/
  printf("%d\n", maxv);
  return 0;
}
