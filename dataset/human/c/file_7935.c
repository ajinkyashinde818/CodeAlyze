#include <stdio.h>

int MAX = 2147483647;

int D[20000000];
int n, n_;
int l;


int min(int a, int b)
{
    if(a < b) return a;
    else return b;
}


int initRMQ(int n)
{
    int n_ = 1;

    while(n_ < n)
        n_ *= 2;

    for(int i = 0; i < 2*n_ - 1; i++)
        D[i] = MAX;

    return n_;
}


void update(int k, int a)
{
    k += n_ - 1;
    D[k] = a;

    while(k > 0)
    {
        k = (int)((k - 1) / 2);
        D[k] = min(D[k*2 + 1], D[k*2 + 2]);
    }
}


int query(int a, int b, int k, int l, int r)
{
    if(r <= a || b <= l) return MAX;
    if(a <= l && r <= b) return D[k];

    int vl = query(a, b, k*2 + 1, l, (int)((l + r)/2));
    int vr = query(a, b, k*2 + 2, (int)((l + r)/2), r);

    return min(vl, vr);
}


int findMin(int a, int b)
{
    return query(a, b, 0, 0, n_);
}


int main(int argc, char const* argv[])
{
    scanf("%d %d", &n, &l);

    int A[1000000];

    for(int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        A[i] = a;
    }

    n_ = initRMQ(n);

    for(int i = 0; i < n; i++)
    {
        update(i, A[i]);
    }

    for(int i = 0; i < n-l; i++)
    {
        printf("%d ", findMin(i, i+l));
    }
    printf("%d\n", findMin(n-l, n));
}
