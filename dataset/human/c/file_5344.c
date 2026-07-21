#include <stdio.h>
#include <string.h>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ifb(N, n) if(N & (1 << n))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define V [0x1000] 
#define AV = malloc(0x8000) 
#define VZ(v) memset(v, 0, 0x1000)
#define addv(a,b) a = (unsigned long long)a + (unsigned long long)b
#define assv(a,b) a = (unsigned long long)b
#define vi 0x7fffffffffffffff

typedef void * v;
typedef unsigned long long ull;

int main(void) {
    int n, m, x;

    scanf("%d %d %d", &n, &m, &x);

    v cc V;
    v *aaa V;

    rep(i, n) {
        v c;
        scanf("%d", &c);
        cc[i] = c;
        v *aa AV;
        rep(j, m) {
            v a;
            scanf("%d", &a);
            assv(aa[j], a);
        }
        aaa[i] = aa;
    }


    v ans = vi;
    rep(b, 1 << n) {
        v t V;
        VZ(t);
        int sum = 0;
        rep(i, n) {
            ifb(b, i) {
                sum += cc[i];
                rep(j, m) {
                    addv(t[j], aaa[i][j]);
                }
            }
        }
        rep(i, m) {
            if(t[i] < x) goto owari;
        }
        ans = MIN(sum, ans);
owari:;
    }
    
    printf("%d", ans);
}
