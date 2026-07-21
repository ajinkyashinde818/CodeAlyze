#include <stdio.h>

int main(){
    int n, k, passed = 0;
    scanf("%d %d", &n, &k);
    int a[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= k){
            ++passed;
        }
    }
    printf("%d\n", passed);

    return 0;
}
