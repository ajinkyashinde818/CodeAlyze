#include <stdio.h>
#include <math.h>
#include <string.h>

int main()

{
    int i,N,X,A[200],D,h=0,g;
    scanf("%d%d%d",&N,&D,&X);
    for(i=1;i<=N;i++)
        scanf("%d",&A[i]);
    for(i=1;i<=N;i++)
    {
        for(g=1;A[i]*g+1<=D;g++)
        h++;

    }
    printf("%d\n",X+h+N);
    return 0;
}
