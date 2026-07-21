#include<stdio.h>

int main() {
	int X, S;
	scanf("%d%d", &X, &S);
	int i,j,k,a;
	for (i = 0; i <= X; i++) {
		for (j = 0; j <= X; j++) {
          k=S-i-j;
          if(0<=k&&X>=k){
            a++;
          }
		}
	}
	printf("%d", a);
	return 0;
}
