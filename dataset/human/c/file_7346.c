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

const ll INF = 1ll<<60;
int a, b, q;
ll s[100100], t[100100], x;

bool isOK(int index, ll key, ll arr[]) {
    if (arr[index] >= key) return true;
    else return false;
}
int binary_search(ll key, ll arr[], int size) {
    int ng = -1;
    int ok = size;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key, arr)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    scanf("%d%d%d", &a, &b, &q);
    for(int i=1; i<=a; i++)scanf("%lld", &s[i]);
    for(int i=1; i<=b; i++)scanf("%lld", &t[i]);
    s[0] = -INF;s[a+1] = INF;t[0] = -INF; t[b+1] = INF;
    while(q--){
        scanf("%lld", &x);
        int i = binary_search(x, s, a+2);
        int j = binary_search(x, t, b+2);
        ll sum = min(min(max(s[i]-x, t[j]-x), max(x-s[i-1], x-t[j-1])), min(min(s[i]-x, x-t[j-1])+s[i]-t[j-1], min(t[j]-x, x-s[i-1])+t[j]-s[i-1]));
        printf("%lld\n", sum);
    }
    return 0;
}
