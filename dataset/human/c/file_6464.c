#include <stdio.h>
#include <time.h>

int main ()
{
    int initial,j,max,minv;
    scanf("%d",&initial);
    int *p;
    p = (int *)malloc(initial*sizeof(int));
    for(j = 0;j < initial;j++)
    {
        scanf("%d",&p[j]);
    }
    minv = p[0];
    max = p[1] - p[0];
    for(j = 1;j < initial;j++)
    {
        if(max < (p[j] - minv))
            max = p[j] - minv;
        if(minv>p[j])
            minv = p[j];
    }
    printf("%d\n",max);
    free(p);
    return 0;
}
