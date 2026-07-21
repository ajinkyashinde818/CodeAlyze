#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<tgmath.h>
#include<stdbool.h>
#include<sys/queue.h>
#include<time.h>
#define ll long long
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

int prime[1001001];
bool is_prime[1001001];
int sieve(int n){
    int p = 0;
    for(int i=0; i<=n; i++)is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2*i; j<=n; j+=i)is_prime[j] = false;
        }
    }
    return p;
}
ll n, ans = 0;
main(){
    scanf("%lld", &n);
    int x = sieve(1000000);
    for(int i=0; i<x; i++){
        int j = prime[i];
        while(n%prime[i] == 0){
            if(n%j==0){
                n/=j;
                ans++;
                j*=prime[i];
            }else {
                while(n%prime[i] == 0) n/=prime[i];
            }
        }
    }
    if(n>1)ans++;
    printf("%lld\n", ans);
    return 0;
}
