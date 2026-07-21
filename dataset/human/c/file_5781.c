#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, i, j, k;
  int *R;
  int max, min;

  scanf("%d", &n);
  R = malloc(n*sizeof(int));
  for(i = 0; i < n; i++) {
    scanf("%d", &R[i]);
  }
  max = R[1]-R[0];
  min = R[0];

  for(i = 0; i < n-1; i++) {
    if(R[i] < min || i == 0) {
      min = R[i];
      for(j = i+1; j < n; j++) {
	if(R[j]-R[i] > max) {
	  max = R[j]-R[i];
	}
      }
    }
  }
  printf("%d\n", max);

  return 0;
}
