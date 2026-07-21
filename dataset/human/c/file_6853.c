#include <stdio.h>
int main() {int N,i,j,a,b,A[105][105],mx;for (scanf("%d",&N),i=0;i<N;i++) for (j=0;j<N;scanf("%d",&A[i][j++]));mx=A[0][0];
	for (i=1;i<N;A[i][0]+=A[i-1][0],A[0][i]+=A[0][i-1],i++);for (i=1;i<N;i++) for (j=1;j<N;A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1],j++);
	for (i=-1;i<N;i++) for (j=-1;j<N;j++) for (a=i+1;a<N;a++) for (b=j+1;b<N;b++) {int k=A[a][b]+((i>-1 && j>-1)?A[i][j]:0)-((i>-1)?A[i][b]:0)-((j>-1)?A[a][j]:0);if (mx<k) mx=k;} printf("%d\n",mx);return 0;}
