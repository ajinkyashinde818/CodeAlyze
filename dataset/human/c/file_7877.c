// AOJ 0519: Worst Reporter
// 2017.10.28 bal4u@uu
// 2018.1.20

#include <stdio.h>

int to[5001][100], hi[5001];
int q[5001], top, end;
int count[5001];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int tsort(int n)
{
    int i, j, k, f;

//  for (i = 0; i < n; i++) for (j = 0; j < hi[i]; j++) count[to[i][j]]++;

    top = end = 0;
    for (i = 0; i < n; i++) if (!count[i]) q[end++] = i;
    f = 0;
    while (top < end) {
		f |= (end - top) > 1;
		i = q[top++];
        printf("%d\n", i+1);
        for (j = 0; j < hi[i]; j++) {
            k = to[i][j];
            if (--count[k] == 0) q[end++] = k;
        }
    }
	return f;
}

int main()
{
	int n, m, a, b;

	n = in(), m = in();
	while (m--) {
		a = in()-1, b = in()-1;
		to[a][hi[a]++] = b;
		count[b]++;
	}
	putchar('0' + tsort(n));
	putchar('\n');
	return 0;
}
