#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<tgmath.h>
#include<time.h>
#define ll long long
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define miin(a,b,c) min((a), min((b), (c)))
#define maax(a,b,c) max((a), max((b), (c)))

int a, b;

int main(){
    scanf("%d%d", &a, &b);
    printf("%d\n", b + (a<10?1000-100*a:0));
}
