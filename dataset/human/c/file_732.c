#include<stdio.h>

const int MOD = 1e9+7;
int n, alp[26];

int main(void){
        scanf("%d", &n); getchar();
        for(int i=0; i<n; i++) alp[getchar()-'a']++;
        long ans = 1;
        for(int i=0; i<26; i++) ans = (ans * ++alp[i]) % MOD;
        printf("%ld\n", ans-1);
        return 0;
}
