#include <stdio.h>

long n, a[200000];

long get_abs(long x, long y) {
    long tmp;
    
    tmp = x - y;
    if (tmp < 0) tmp *= -1;
    return tmp;
}

int main(void) {
    long i, sum = 0;
    long x, y, abs, min;
    
    scanf("%ld", &n);
    
    for (i = 0; i < n; ++i) {
        scanf("%ld", &a[i]);
        sum += a[i];
    }
    
    x = 0;
    y = sum;
    x += a[0];
    y -= a[0];
    abs = get_abs(x, y);
    min = abs;
    
    for (i = 1; i < n - 1; ++i) {
        x += a[i];
        y -= a[i];
        abs = get_abs(x, y);
        
        if (abs < min) {
            min = abs;
        }
    }
    
    printf("%ld\n", min);
    return 0;
}
