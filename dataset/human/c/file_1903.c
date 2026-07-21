#include<stdio.h>

int main(void){
  int n, a[21], b[21], c[20], sum=0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < n-1; i++){
    scanf("%d", &c[i]);
  }
  // for(int i = 0; i < n; i++)
  //   printf("DEB a[%d]:%d b[%d]:%d c[%d]:%d \n", i, a[i], i, b[i], i, c[i]);
  // printf("DEB sum:%d\n", sum);
  sum += b[a[0]-1];
  // printf("DEB sum: %d b[%d]:%d\n", sum, a[0]-1, b[a[0]-1]);
  for(int i = 1; i < n; i++){
    sum += b[a[i]-1];
    // printf("DEB sum: %d b[%d]:%d\n", sum, a[i], b[a[i]-1]);
    if(a[i-1]+1 == a[i]){
      sum += c[a[i-1]-1];
      // printf("DEB sum: %d c[%d]:%d\n", sum, a[i-1]-1, c[a[i-1]-1]);
    }
  }
  printf("%d", sum);
  return 0;
}
