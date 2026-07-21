#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define rep(i, n) for(int i=0; i<(n); ++i)
#define max  200001
#define mod 1000000007

//qsort(str, n, sizeof(int), up_comp);
int up_comp(const void *a, const void *b){return *(int*)a - *(int*)b;}
int down_comp(const void *a, const void *b){return *(int*)b - *(int*)a;}
int int_sort( const void * a , const void * b ) {return strcmp(( char * )a , ( char * )b );}
int count_digit(int a){int i=0;while(a!=0){a=a/10;i++;}return i;}
int euclid( int a, int b ){int temp;if(a<b){temp=a;a=b;b=temp;}if(b<1)return -1;if(a%b==0) return b;return euclid(b,a%b);}

int main(void){
    
    int n, d[max][2];
    int cnt=0;
    
    scanf("%d", &n);
    rep(i, n){
        scanf("%d%d", &d[i][0], &d[i][1]);
        if (d[i][0]==d[i][1]) {
            cnt++;
            if (cnt>=3) {
                printf("Yes");
                return 0;
            }
        } else {
            cnt=0;
        }
    }
    
    printf("No");
    
    return 0;
}
