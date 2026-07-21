#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>
typedef long long llint;
typedef long double ldouble;
// 小大
int compare(const void *a, const void *b){return *(llint *)a - *(llint *)b;}
typedef struct{
    llint aa;
    llint bb;
}frequent;
// 小大
int cmp( const void *p, const void *q ) {
    return ((frequent*)p)->bb - ((frequent*)q)->bb;
}


int main(void){
    llint n,k;
    scanf("%lld%lld",&n,&k);
    // llint [n];
    // for(i=0;i<n;i++){
    //     scanf("%lld",&[i]);
    // }
    if(n==k){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    // printf("\n");
    return 0;
}
