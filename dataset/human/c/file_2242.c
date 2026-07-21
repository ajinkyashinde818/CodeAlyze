#include <stdio.h>
#define mn(a,b,c) ((a>b)?((b>c)?c:b):((a>c)?c:a))
short A[1005][1005],V[1005][1005],H[1005][1005];int M;
int main() {while (scanf("%d",&M)!=EOF && M) {int i,j,a=0;char T;for (i=0;i<M;i++) for (scanf("%*c"),j=0;j<M;j++) scanf("%c",&T),A[i][j]=H[i][j]=V[i][j]=(bool)(T=='.');
    for (i=1;i<M;i++) for (j=1;j<M;j++) H[i][j]+=(H[i][j]?H[i][j-1]:0),V[i][j]+=(V[i][j]?V[i-1][j]:0),A[i][j]=mn(A[i-1][j-1]+1,H[i][j],V[i][j]),a=((a<A[i][j])?A[i][j]:a);
    if (!a) for (i=0;i<M;i++) if (H[0][i] || H[i][0]) a=1;printf("%d\n",a);} return 0;}
