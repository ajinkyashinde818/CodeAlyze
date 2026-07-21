#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#ifdef TEST
struct test {
    int ans;
} td[] = {
    {},
};
#endif

void
solver(char *s, int q, int *t, int *f, char *c)
{
    int i;
    int top = 0;
    char pre[200001];
    char post[200001];
    int pre_p = 0, post_p = 0;

    bzero(pre, sizeof(pre));
    bzero(post, sizeof(post));

    for(i = 0; i < q; i++) {
        if(t[i] == 1) {
            top = 1 - top;
        }
        if(t[i] == 2) {
            if(f[i] == 1) {
                if(top == 0) {
                    pre[pre_p++] = c[i];
                } else {
                    post[post_p++] = c[i];
                }
            } else {
                if(top == 1) {
                    pre[pre_p++] = c[i];
                } else {
                    post[post_p++] = c[i];
                }
            }
        }
    }
    if(top == 0) {
        for(i = pre_p - 1; i >= 0; i--)
            printf("%c", pre[i]);
        printf("%s%s", s, post);
    } else {
        for(i = post_p - 1; i >= 0; i--)
            printf("%c", post[i]);

        for(i = strlen(s) - 1; i >= 0; i--)
            printf("%c", s[i]);

        printf("%s", pre);
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{
    char S[100001];
    char tmp[100];
    int Q;
    int T[200000];
    int F[200000];
    char C[200000];
    int i;

#ifdef TEST
    int tt;
    for(tt = 0; tt < sizeof(td) / sizeof(struct test); tt++) {
        solver();
        printf("%d\n", td[tt].ans);
    }
#endif
    scanf("%s", S);
    scanf("%d", &Q);
    for(i = 0; i < Q; i++) {
        scanf("%d", T + i);
        if(T[i] == 2) {
            scanf("%d %c", F + i, C + i);
        }
    }

    solver(S, Q, T, F, C);
    return 0;
}
