#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
typedef int keytype;

void quicksort_des(keytype a[], int first, int last)
{
    int i, j;
    keytype x, t;

    x = a[(first + last) / 2];
    i = first;  j = last;
    for ( ; ; ) {
        while (a[i] > x) i++;
        while (x > a[j]) j--;
        if (i >= j) break;
        t = a[i];  a[i] = a[j];  a[j] = t;
        i++;  j--;
    }
    if (first  < i - 1) quicksort_des(a, first , i - 1);
    if (j + 1 < last) quicksort_des(a, j + 1, last);
}

int main(){
    int k, n;
    int a[200000] = {0};

    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int dist[200000] = {0};
    for(int i = 0; i < n; ++i){
        if(i < n - 1) dist[i] = a[i+1] - a[i];
        else dist[i] = k - a[i] + a[0];
    }

    quicksort_des(dist, 0, n-1);
    int sum = 0;
    for(int i = 1; i < n; ++i){
        sum += dist[i];
    }

    printf("%d\n", sum);

    return 0;
}
