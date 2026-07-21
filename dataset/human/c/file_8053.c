#include<stdio.h>
int main() {
    long long a[333], b[333], c[333], d[333], t, i,r,p,cb,cd,ca,flag;
    scanf("%lld", &t);
    for (i = 0; i < t; i++) 
        scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
    for (i = 0; i < t; i++) {
        flag = 1;
        cb = b[i];
        cd = d[i];
        if (cb > cd) {
            p = cb;
            cb = cd;
            cd = p;
        }
        p = cb;
        while (cd%p != 0) {
            cb = cd % p;
            cd = p;
            p = cb;
        }
        ca = a[i] % b[i];
        ca=b[i]-p+(ca%p);
        if (a[i] < b[i])
            flag = 0;
        if (d[i] < b[i])
            flag = 0;
        if (ca > c[i])
            flag = 0;
        if (flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
