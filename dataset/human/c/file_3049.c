#include<stdio.h>

int main() {
  int i,k,n;
  int a[1000000];
  scanf("%d %d",&k,&n);
  for(i = 0;i < n;i++) {
    scanf("%d",&a[i]);
  }
  a[n] = a[0] + k;
  i = 0;
  int max = a[1] - a[0];
  for(i = 0;i < n;i++) {
    if(max < a[i+1]-a[i]) {
      max = a[i+1] - a[i];
    }
  }
  printf("%d\n",k-max);

}
