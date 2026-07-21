#include<stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return (-1);
    else if (*a > *b)
        return (1);
    return (0);
}

int main () {
int f[1001];
int F[1001];
int N,i,V,d,count;
N=1001;
f[0]=2;
f[1]=3;
for( i = 2; i < 1001; i++){
        f[ i] = f[ i-1] + f[ i-2];
        f[ i] = f[ i] % N;
        }
for( ; ~scanf("%d %d",&V,&d); ){
        count = 1;
        for( i = 0; i < V; i++ )
                F[ i] = f[ i ];
        qsort( F, V, sizeof(int), (int(*)(const void*, const void*))int_cmp);
        for(i = 1; i < V; i++)
                if( F[ i] - F[ i - 1] > d - 1)
                        count++;
        printf( "%d\n" , count);
        }
}
