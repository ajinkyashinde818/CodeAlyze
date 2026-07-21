#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define rep(i, n) for(int i=0; i<(n); ++i)
#define max  100000

//qsort(str, n, sizeof(int), up_comp);
int up_comp(const void *a, const void *b){return *(int*)a - *(int*)b;}
int down_comp(const void *a, const void *b){return *(int*)b - *(int*)a;}
int int_sort( const void * a , const void * b ) {return strcmp(( char * )a , ( char * )b );}
int count_digit(int a){int i=0;while(a!=0){a=a/10;i++;}return i;}
int euclid( int a, int b ){int temp;if(a<b){temp=a;a=b;b=temp;}if(b<1)return -1;if(a%b==0) return b;return euclid(b,a%b);}

int main(void){
 
    int a[13][13];
    int c[13];
    int n, m, x;
    int ans = INT_MAX;
    
    scanf("%d%d%d", &n, &m, &x);
    rep(i, n){
        scanf("%d", &c[i]);
        rep(j, m){
            scanf("%d", &a[i][j]);
        }
    }

    rep(s, 1<<n) {
        int cost = 0;
        int d[max] = {0};
        rep(i, n) {
            if (s>>i&1) {
                cost += c[i];
                rep(j, m){
                    d[j] += a[i][j];
                }
            }
        }

         bool ok = true;
           rep(j, m) {
             if (d[j] < x) {
               ok = false;
               break;
             }
           }
        
        if(ok) ans = fmin(cost, ans);
    }
    
    if (ans == INT_MAX)printf("%d", -1);
    else printf("%d", ans);

    return 0;
}
