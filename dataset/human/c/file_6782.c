#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define max(l,r) ((l)>(r)?l:r)
#define min(l,r) ((l)<(r)?l:r)
#define swap(l,r) {ll tp=l;l=r;r=tp;}
const ll MOD = 1000000007;
int upcmpii(const void *a, const void *b){
    return (*(int*)a == *(int*)b ? 0 : (*(int*)a > *(int*)b ? 1 : -1));
}
void sort_ui(int *a, int n){ qsort(a, n, sizeof(int), upcmpii);}

int main(){
    //input
    int n, k;
    scanf("%d%d", &n, &k);
    int a[201010];
    rep(i, n) scanf("%d", a+i);

    //solve
    sort_ui(a, n);
    if(k == 0) {
        printf("%d\n", a[n-1]);
    }else{
        int left = 0, right = a[n-1]+1;
        while(right - left > 1){
            ll tmp = 0;
            int mid = (right+left)/2;
            rep(i, n){
                if(a[i] > mid) {
                    tmp += (a[i]-1)/mid;
                }
            }
            if(tmp > k) left = mid;
            else right = mid;
        }
        printf("%d", right);
    }
}
