#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define revrep(i,begin,end) for(int i=begin; i>end; i--)
#define lld long long int

int main(){
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    rep(i, 0, n){
        if(i < k){
            printf("%d ", s);
        }else{
            if(s != 1000000000){
             printf("%d ", s+1);
            }else{
                printf("999999999 ");
            }
        }
    }

    return 0;
}
