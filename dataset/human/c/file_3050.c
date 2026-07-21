#include <stdio.h>
#include <malloc.h>
#include <string.h>

int compare_int(const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}

int main(void) {
  int k, n, i, j, tmp;

  scanf(" %d %d", &k, &n);

  int a[n];
  for(i=0; i < n; i++)
    scanf("%d", &a[i]);
  /*
   for(i=0; i < n; i++){
   for(j=i + 1; j < n; ++j){
   if(a[i] > a[j]){
   tmp=a[i];
   a[i]=a[j];
   a[j]=tmp;
   }
   }
   }*/
  qsort(a, n, sizeof(int), compare_int);

//    for(i=0; i < n; i++)
//     printf("%d ", a[i]);
//    printf("\n");
  int le=k - a[n - 1] + a[0];
  for(i=0; i < n - 1; i++){
    if(le < a[i + 1] - a[i]) le=a[i + 1] - a[i];
  }
  printf("%d", k-le);
  return 0;
}
