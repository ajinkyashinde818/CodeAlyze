#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int keytype;

//quicksort(<#keytype *a#>, <#int first#>, <#int last#>)

void quicksort(keytype a[], long long int first, long long int last){
    long long int i, j;
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

int main() {
    int n,r;
    scanf("%d %d",&n,&r);
    if (n>=10){
        printf("%d\n",r);
    }else{
        r=r+(100*(10-n));
        printf("%d\n",r);
    }
    
    return 0;
}
