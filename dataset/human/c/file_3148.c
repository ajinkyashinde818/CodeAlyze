#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef int keytype;

//quicksort(<#keytype *a#>, <#int first#>, <#int last#>)

void quicksort(keytype a[], int first, int last){
    int i, j;
    keytype x, t;
    
    x = a[(first + last) / 2];
    i = first;  j = last;
    for ( ; ; ) {
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if (i >= j) break;
        t = a[i];  a[i] = a[j];  a[j] = t;
        i++;  j--;
    }
    if (first  < i - 1) quicksort(a, first , i - 1);
    if (j + 1 < last) quicksort(a, j + 1, last);
}

int gcd(int x, int y){
    if (y == 0) return x;
    else        return gcd(y, x % y);
}

int main() {
    int n,k,a[200000],sa[200000];
    int i,max=0;
    scanf("%d %d",&k,&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=0; i<n-1; i++) {
        sa[i]=a[i+1]-a[i];
    }
    sa[n-1]=k-a[n-1]+a[0];
    quicksort(sa, 0, n-1);
    printf("%d",k-sa[n-1]);
    return 0;
}
