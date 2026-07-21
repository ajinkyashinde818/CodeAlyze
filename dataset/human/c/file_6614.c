#include <stdio.h>

int main(void)
{
  int n, i, R[200000];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &R[i]);
  }

  int minv = R[0], maxv = R[1] - minv;

  for(i = 1; i < n; i++){

    if(maxv < R[i] - minv){
      maxv = R[i] - minv;
    }
    else if(R[i] < minv){
      minv = R[i];
    }
  }
    printf("%d\n", maxv);
}
