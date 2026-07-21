#include<stdio.h>
#include <stdlib.h>

int main(void) {
  int N;
  scanf("%d", &N);
  
	int *a, *b;
	a = (int *)malloc(N * sizeof(int));
	b = (int *)malloc(N * sizeof(int));


  int i, j;
  for(i=0; i<N; i++) {
		b[i] = 0;
    scanf("%d", &a[i+1]);
  }

	int current = 1;
	int next;
	int flag = 1;
	int count = 0;
	
	while(flag){
		b[current]++;
		count++;
		next = a[current];
		if(next == 2){
			flag = 0;
		}
		if(b[current] > 1){
			printf("-1\n");
			free(a);
			return 0;
		}
		current = next;
	}
	printf("%d\n", count);
	free(a);
	free(b);
	return 0;
}
