#include<stdio.h>

int main(void) {
int N, D, X;
scanf("%d %d %d", &N, &D, &X);
int A[N];
for (int i = 0; i < N; i++) {
 scanf("%d", &A[i]);
}

int cnt = X;
for (int i = 0; i < N; i++) {
int j = 0;
 while (j*A[i]+1 <= D) {
   cnt++;
   j++;
 }
}

printf("%d", cnt);
 return 0;
}
