#include <stdio.h>
#include <string.h>

int main(void) {
    int Q, T, F, l, r, a, s, i;
    char S[100005], L[200005], R[200005], C;
    scanf("%s%d", S, &Q);
    a=0; l=0; r=0;
    for (i=0; i<Q; i++) {
        scanf("%d", &T);
        if (T==1) {
            a++;
            a%=2;
        }
        else {
            scanf("%d %c", &F, &C);
            if ((a+F)%2==1) {
                L[l]=C;
                l++;
            }
            else {
                R[r]=C;
                r++;
            }
        }
    }
    if (a==0) {
        for (i=0; i<l; i++) printf("%c", L[l-i-1]);
        printf("%s%s", S, R);
    }
    else {
        for (i=0; i<r; i++) {
            printf("%c", R[r-i-1]);
        }
        s=strlen(S);
        for (i=0; i<s; i++) {
            printf("%c", S[s-i-1]);
        }
        printf("%s", L);
    }
    
    /*
    printf("\n");
    printf("%s\n%s\n%s\n", L, S, R);
    printf("%d, %d, %d", a, l, r);
    */
    return 0;
}
