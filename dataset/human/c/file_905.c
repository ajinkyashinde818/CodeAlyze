#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int table[1000];
int bisect_right(int x,int a[],int left,int right){
    int mid;
    right++;
    while (left < right) {
        mid = (left + right) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


int counter(int i) {
    if (i == 0) {
        return 0;
    }
    return bisect_right(i,table,0,39) - 1;
    
}

void solve(long long N, int *ans ){
    int cnt = 0;
    while (N % 2 == 0) {
        cnt++;
        N /= 2;
    }
    *ans += counter(cnt);
    int now = 3;
    cnt = 0;
    while ((long long)now * now <= N) {
        while (N % now == 0) {
            cnt++;
            N /= now;
        }
        *ans += counter(cnt);
        cnt = 0;
        now += 2;
    }
    if (N != 1) {
        *ans += counter(1);
    }
}



int main(void){
    long long N;
    scanf("%lld", &N);
    for (int i = 0; i < 40; i++) {
        table[i] = i * (i + 1) / 2;
    }
    int ans = 0;
    solve(N, &ans);
    printf("%d\n",ans);
    return 0;
}
