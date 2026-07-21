#include <stdio.h>
#include <stdlib.h>

#undef TEST

struct testData {
    long long N;
    long long M;
    long long a[100000];
    long long ans;
} td[] =
    {
        {
            2, 50,
            {6, 10},
            2,
        },
        {
            2, 50,
            {4, 10},
            0,
        },
        {
            1, 50,
            {6},
            8,
        },
        {
            3, 100,
            {14, 22, 40},
            0,
        },
        {
            5, 1000000000,
            {6, 6, 2, 6, 2},
            166666667,
        }
};

long long
gcd(long long x, long long y)
{
    long long r;
    while((r = x%y) != 0){
        x=y;
        y=r;
    }
    return y;
}

long long
lcm(long long x, long long y)
{
    return ((x*y)/gcd(x,y));
}

void
solver(long long n, long long m, long long *a)
{
    long long vlcm, maxa=0;
    int i;


    vlcm = a[0];
    maxa = a[0];

    for (i=1; i<n; i++) {
        if ((a[0]>>1)%2 != (a[i]>>1)%2) {
            printf("0\n");
            return;
        }

        vlcm = lcm(a[i], vlcm);
        if (maxa<a[i])  maxa=a[i];
    }

    if (vlcm/2>m) {
        printf("0\n");
        return;
    }
    for (i=0; i<n; i++) {
        if (((vlcm-a[i])/2)%a[i]!=0){
            printf("0\n");
            return;
        }
    }
//    printf("%ld %ld %ld\n", m, target, vlcm);
    printf("%lld\n", (m-vlcm/2)/vlcm+1);
}

int
main(int argc, char *argv[])
{
    long long N, M;
    long long a[100001];
    int i;

#ifdef TEST
    for (i=0; i<5; i++) {
        solver(td[i].N, td[i].M, td[i].a);
        printf("ans %lld\n", td[i].ans);
    }
#else
    scanf("%lld%lld", &N, &M);
    for (i=0; i<N; i++)
        scanf("%lld", a+i);
    
    solver(N, M, a);
#endif
    return 0;
}
