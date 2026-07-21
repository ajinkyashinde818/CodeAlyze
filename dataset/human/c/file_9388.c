#include <stdio.h>

int main(void)
{
        int N,D,i,A[100],X,j,s=0;

        scanf("%d%d%d",&N,&D,&X);

        for (i=0;i<N;i++)
                scanf("%d",&A[i]);

        for (i=0;i<N;i++){
                for (j=1;j<=D;j=j+A[i])
                        s++;
        }

        printf("%d\n",s+X);

        return 0;
}
