#include <stdio.h>
long long int gcd(long long int a, long long int b){return (a % b) ? gcd(b, a % b): b;}
long long int lcm(long long int a, long long int b){return a*b/gcd(a, b);}

int main(void){
    long long int a[100000];
    long long int n, m;
    scanf("%lld%lld", &n, &m);

    int i, j, k;
    
    for(i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }

    int cnt, cnt_t;
    //2で割り切れる回数の計算
    int t = a[0];
    cnt = 0;
    while(t % 2 == 0){
        t /= 2;
        cnt++;
    }
    for(i = 1; i < n; i++){
        cnt_t = 0;
        t = a[i];
        while(t % 2 == 0){
            t /= 2;
            cnt_t++;
        }
        if(cnt != cnt_t){
            printf("0\n");
            return 0;
        }
    }

    long long int tmp, x;
    tmp = a[0]/2;
    for(i = 1; i < n; i++){
        tmp = lcm(tmp, a[i]/2);
    }

    x = tmp;
    long long int ans = (m + x)/2/x;
    
    printf("%lld\n", ans);
    return 0;
}
