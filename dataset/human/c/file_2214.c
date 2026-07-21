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

char s[1111111] = {}, c;
int q, a, b, i = 500000, j, nyan = 0;

int main(){
    scanf("%s", s + i);
    for(j = i;s[j] != NULL;j++);j--;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &a);
        if(a == 1){
            nyan ^= 1;
        }else {
            scanf("%d %c",&b, &c);
            if(b == 1){
                if(nyan == 0){
                    i--;
                    s[i] = c;
                }else {
                    j++;
                    s[j] = c;
                }
            }else {
                if(nyan == 0){
                    j++;
                    s[j] = c;
                }else {
                    i--;
                    s[i] = c;
                }
            }
        }
    }
    if(nyan == 0){
        for(int k=i;k<=j;k++)putchar(s[k]);
    }else{
        for(int k=j;k>=i;k--)putchar(s[k]);
    }
    return 0;
}
