#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MOD 998244353

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef long long int64;

int main(void){

    int N;
    scanf("%d",&N);
    
    char S[N];

    
    scanf("%s",S);
    

    int K;

    scanf("%d",&K);
    
    
    char s=S[K-1];

    for(int i = 0; i < N; i++)
    {
        if(S[i]!=s){
            S[i]='*';
        }
    }

    for(int i = 0; i < N; i++)
    {
        printf("%c",S[i]);
        
    }

    
    
    
    return 0;
}
