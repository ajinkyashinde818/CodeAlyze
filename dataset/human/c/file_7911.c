#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define lld long long int

long long int gcd(long long int a, long long int b){
    long long int c;
    if(a<b){
        c = a;
        a = b;
        b = c;
    }
    while(a%b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n;
    lld m;
    scanf("%d %lld", &n, &m);
    lld a[n];
    rep(i, 0, n){
        scanf("%lld", &a[i]);
        a[i] /= 2;
    }
    lld x=1, y;
    int cnt = 0, f = 0;
    int buf = a[0];
    while(buf%2 == 0){
        buf /= 2;
        cnt++;
    }
    rep(i, 1, n){
        buf = a[i];
        int c = 0;
        while(buf%2 == 0){
            buf /= 2;
            c++;
        }
        if(cnt != c){
            f = 1;
        }
    }
    rep(i, 0, n){
        y = x*a[i];
        x = y / gcd(x, a[i]);
    }
    if(f){
        printf("0");
    }else{
        printf("%lld", (m/x + 1)/2);
    }

    return 0;
}
