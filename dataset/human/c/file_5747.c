#include <stdio.h> 
int main() {
  int n,a,max,min;
  max = (-999999999);
  scanf("%d", &n);
  scanf("%d", &min);
  for (int i = 0; i < n-1; i++){
    scanf("%d", &a);
    max = max >= a-min ? max : a-min;
    min = min <= a ? min : a;
  }
  printf("%d\n", max);
}
