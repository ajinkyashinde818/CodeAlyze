#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_MAX 200000

int cmpfunc( const void * n1, const void * n2 )
{
    if (*(int *)n1 < *(int *)n2){
        return 1;
    }
    else if (*(int *)n1 > *(int *)n2){
        return -1;
    }
    else {
        return 0;
    }
}


int main()
{
    int k, n;
    int a[N_MAX], a_dis[N_MAX];
    scanf("%d%d",&k,&n);
    for ( int i=0; i<n; i++ ) scanf("%d",&a[i]);
    
    a_dis[0] = a[0] - a[n-1] + k;
    for ( int i=1; i<n; i++ ) a_dis[i] = a[i] - a[i-1];
    
    qsort( a_dis, n, sizeof(a_dis[0]), cmpfunc );
    
    int total = 0;
    for ( int i=1; i<n; i++ ){
        total += a_dis[i];
    }
    printf("%d\n", total);
}
