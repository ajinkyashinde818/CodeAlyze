#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max 20000

//qsort(d, n, sizeof(int), up_comp);
int up_comp(const void *a, const void *b){return *(int*)a - *(int*)b;}
int down_comp(const void *a, const void *b){return *(int*)b - *(int*)a;}

int main()
{
    int k, n, i, ppmax=0;
    int a[200000];
    
    scanf("%d %d", &k, &n);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (i=0; i<n-1; i++) {
        if(a[i+1]-a[i]>ppmax){
            ppmax=a[i+1]-a[i];
        }
    }
    
    if (a[0]+(k-a[n-1])>ppmax) {
        ppmax=a[0]+(k-a[n-1]);
    }
    
    printf("%d",k-ppmax);

    return 0;
}
