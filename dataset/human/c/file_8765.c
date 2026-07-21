#include<stdio.h>
long long int h[200005], l;
long long int abs(long long int n)
{
	if (n < 0)
		n *= -1;
	return n;
}
int comp_h(long long int a, long long int b)
{
	if (abs(h[a]) < abs(h[b]))return 1;
	return -1;
}
void swap_h(long long int a, long long int b)
{
	long long int f = h[a];
	h[a] = h[b];
	h[b] = f;
	return;
}
void f1(long long int ne)
{
	h[l] = ne;
	long long int p = l;
	l++;
	while (p > 0)
	{
		if (comp_h((p - 1) / 2, p) > 0)
			swap_h((p - 1) / 2, p);
		p = (p - 1) / 2;
	}
	return;
}
long long int f2()
{
	l--;
	swap_h(0, l);
	long long int p = 0;
	for (;;)
	{
		if (2 * p + 2 < l)
		{
			if (comp_h(2 * p + 1, 2 * p + 2) > 0)
			{
				if (comp_h(p, 2 * p + 2) > 0)
					swap_h(p, 2 * p + 2);
				p = 2 * p + 2;
			}
			else
			{
				if (comp_h(p, 2 * p + 1) > 0)
					swap_h(p, 2 * p + 1);
				p = 2 * p + 1;
			}
		}
		else if (2 * p + 1 < l)
		{
			if (comp_h(p, 2 * p + 1) > 0)
				swap_h(p, 2 * p + 1);
			p = 2 * p + 1;
		}
		else
			break;
	}
	return h[l];
}
int main()
{
	long long int n, k;
	scanf("%lld %lld", &n, &k);
	long long int i, j;
	long long int a[200005];
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	l = 0;
	for (i = 0; i < n; i++)
		f1(a[i]);
	for (i = 0; i < n; i++)
		a[i] = f2();
	long long int P = 1000000007;
	long long int v = 1;
	for (i = 0; i < k; i++)
		v = v * a[i] % P;
	if (v >= 0)
	{
		printf("%lld\n", v);
		return 0;
	}
	long long int cnt[3];
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
			cnt[0]++;
		else if (a[i] == 0)
			cnt[1]++;
		else
			cnt[2]++;
	}
	if (cnt[0] / 2 * 2 + cnt[2] < k || (k % 2 > 0 && cnt[2] == 0))
	{
		if (cnt[1] > 0)
		{
			printf("0\n");
			return 0;
		}
		v = 1;
		for (i = 0; i < k; i++)
			v = v * a[n - i - 1] % P;
		printf("%lld\n", (v + P) % P);
		return 0;
	}
	int s, t, p, q;
	s = k - 1;
	t = k - 1;
	while (a[s] * a[t] > 0 && t < n)
		t++;
	p = k - 1;
	while (a[p] * a[s] > 0 && p >= 0)
		p--;
	q = n + 1;
	if (p >= 0)
	{
		q = k;
		while (a[p] * a[q] > 0 && q < n)
			q++;
	}
	if (t < n && q < n)
	{
		if (abs(a[s] * a[q]) > abs(a[t] * a[p]))
		{
			v = 1;
			for (i = 0; i < p; i++)
				v = v * a[i] % P;
			for (i = p + 1; i < k; i++)
				v = v * a[i] % P;
			v = v * a[q] % P;
			v = (v + P) % P;
		}
		else
		{
			v = 1;
			for (i = 0; i < s; i++)
				v = v * a[i] % P;
			for (i = s + 1; i < k; i++)
				v = v * a[i] % P;
			v = v * a[t] % P;
			v = (v + P) % P;
		}
		printf("%lld\n", v);
		return 0;
	}
	if (t < n)
	{
		v = 1;
		for (i = 0; i < s; i++)
			v = v * a[i] % P;
		for (i = s + 1; i < k; i++)
			v = v * a[i] % P;
		v = v * a[t] % P;
		v = (v + P) % P;
		printf("%lld\n", v);
		return 0;
	}
	v = 1;
	for (i = 0; i < p; i++)
		v = v * a[i] % P;
	for (i = p + 1; i < k; i++)
		v = v * a[i] % P;
	v = v * a[q] % P;
	v = (v + P) % P;
	printf("%lld\n", v);
	return 0;
}
