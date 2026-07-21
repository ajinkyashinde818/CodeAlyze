#include <bits/stdc++.h>
using namespace std;

int main(){
    int R, G, B, N;
    scanf("%d%d%d%d", &R, &G, &B, &N);
    long long ans = 0;
    for(int r = 0; r < N / R + 1; r++){
        for(int g = 0; g < N / G + 1; g++){
            int b = N - r * R - g * G;
            if(b >= 0 && b % B == 0)ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
