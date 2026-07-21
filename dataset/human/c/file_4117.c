#include <stdio.h>

int gcd(int a, int b){
    if (b > a){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r = a % b;
    while(r > 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int k_divisor(int A, int K){
    int count = 0;
    int ans = 0;
    for (int i = A; i > 0; i--){
        if(A % i == 0){
            count += 1;
        }
        if(count == K){
            ans = i;
            break;
        }
    }
    return ans;
}

int main(void){
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);
    int g = gcd(A, B);
    int ans = k_divisor(g, K);
    printf("%d\n", ans);
    return 0; 
}
