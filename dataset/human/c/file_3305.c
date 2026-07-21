#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int compare_int(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main(void)
{
  int i, j;
  int ii[200000];
  int ilen[100];
  int min, max=0;
  int K, N;
  int cnt, maxcnt;


  scanf("%d %d\n", &K,&N);
//  printf("k %d  n %d\n",K,N);
  for (i = 0; i < N; i++){
    scanf("%d\n", &ii[i]);
  }
	max =ii[0]-0 + K - ii[N-1];
//    printf("max %d\n",max);

  for (i = 0; i < N-1; i++){
    if(ii[i+1]-ii[i] > max){
      max = ii[i+1]-ii[i];
    }
//    printf("i %d  ii %d max %d\n",i,ii[i],max);
  }
    printf("%d\n",K-max);

  return 0;
}
