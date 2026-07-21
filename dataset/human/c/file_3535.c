#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int bunpu[101] = {};//0点から100点まで101個
    for(int i = 0; i < n; i++) {
        int p_i;
        scanf("%d", &p_i);
        bunpu[p_i]++;
    }
    for(int i = 99; i >= 0; i--) {
        bunpu[i] += bunpu[i+1];
    }
    for(int i = 100; i >= 0; i--) {
        if(bunpu[i] >= i) {
            printf("%d\n", i);
            return 0;
        }
    }
}
