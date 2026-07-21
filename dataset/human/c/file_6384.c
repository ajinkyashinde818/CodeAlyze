#include <stdio.h>

int main(void) {
    int i, n;
    long r, r_1, tmp, benefit;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%ld", &r);
        if (i==0) {
            tmp=r;
            r_1=r;
            continue;
        }
        if (i==1) {
            benefit=r-r_1;
            r_1=r;
            if ((r-tmp)<0) tmp=r;
            continue;
        }
        if ((r-r_1)<0) {
            if (tmp>r) tmp=r;
            r_1=r;
        } else if ((r-r_1)>=0) {
            if (benefit<=(r-tmp)) benefit=r-tmp;
            r_1=r;
        }
        // printf("%ld %ld\n", tmp, benefit);
    }
    printf("%ld\n", benefit);
    return 0;
}
