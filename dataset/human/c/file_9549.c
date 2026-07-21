#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
typedef int keytype;

void quicksort(keytype a[], int first, int last)
{
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

int is_prime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n, d, x;
    int a[100];

    scanf("%d %d %d", &n, &d, &x);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j * a[i] + 1 <= d; ++j){
            cnt++;
        }
    }

    int ans = cnt + x;

    printf("%d\n", ans);

    return 0;
}
