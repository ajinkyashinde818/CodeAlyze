#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define max 20

//qsort(str, n, sizeof(int), up_comp);
int up_comp(const void *a, const void *b){return *(int*)a - *(int*)b;}
int down_comp(const void *a, const void *b){return *(int*)b - *(int*)a;}
int count_digit(int a){int i=0;while (a!=0) {a=a/10;i++;}return i;}

int main()
{
    int n, a[max], b[max], c[max], sum=0, i;
    
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (i=0; i<n; i++) {
        scanf("%d", &b[i]);
        sum+=b[i];
    }
    for (i=0; i<n-1; i++) {
        scanf("%d", &c[i]);
    }
    
    for (i=0; i<n-1; i++) {
        if (a[i+1]-a[i]==1) {
            sum+=c[a[i]-1];
        }
    }
    
    printf("%d", sum);
    
    return 0;
}
