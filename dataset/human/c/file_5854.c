#include<stdio.h>

int main(){
  long n, i, x, temp, min = 20000000000, max=-20000000000;
  scanf("%ld", &n);
  scanf("%ld", &min);
  for(i=1;i<n;i++){
    scanf("%ld", &temp);
    if (max<temp-min) max=temp-min;
    if (min>temp) min=temp;
    }
  printf("%ld\n", max);
  return 0;
}
