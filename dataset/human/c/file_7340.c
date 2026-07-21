#include<stdio.h>
long long int llmin(long long int a, long long int b)
{
	if (a < b)
		return a;
	else
		return b;
}
long long int llabs(long long int n)
{
	if (n < 0)
		n *= -1;
	return n;
}
int main()
{
	int a, b, q;
	scanf("%d %d %d", &a, &b, &q);
	int i;
	long long int s[100005], t[100005], x[100005];
	for (i = 0; i < a; i++)
		scanf("%lld", &s[i]);
	for (i = 0; i < b; i++)
		scanf("%lld", &t[i]);
	for (i = 0; i < q; i++)
		scanf("%lld", &x[i]);
	long long int ms[100005], mt[100005];
	int min, mid, max;
	for (i = 0; i < a; i++)
	{
		if (s[i] <= t[0])
			ms[i] = t[0] - s[i];
		else if (s[i] >= t[b - 1])
			ms[i] = s[i] - t[b - 1];
		else
		{
			min = 0;
			max = b - 1;
			while (max - min > 1)
			{
				mid = (max + min) / 2;
				if (t[mid] < s[i])
					min = mid;
				else
					max = mid;
			}
			ms[i] = llmin(s[i] - t[min], t[max] - s[i]);
		}
	}
	for (i = 0; i < b; i++)
	{
		if (t[i] <= s[0])
			mt[i] = s[0] - t[i];
		else if (t[i] >= s[a - 1])
			mt[i] = t[i] - s[a - 1];
		else
		{
			min = 0;
			max = a - 1;
			while (max - min > 1)
			{
				mid = (max + min) / 2;
				if (s[mid] < t[i])
					min = mid;
				else
					max = mid;
			}
			mt[i] = llmin(t[i] - s[min], s[max] - t[i]);
		}
	}
	long long int ans;
	for (i = 0; i < q; i++)
	{
		max = a - 1;
		min = 0;
		while (max - min > 1)
		{
			mid = (max + min) / 2;
			if (s[mid] < x[i])
				min = mid;
			else
				max = mid;
		}
		ans = llmin(llabs(x[i] - s[min]) + ms[min], llabs(x[i] - s[max]) + ms[max]);
		max = b - 1;
		min = 0;
		while (max - min > 1)
		{
			mid = (max + min) / 2;
			if (t[mid] < x[i])
				min = mid;
			else
				max = mid;
		}
		ans = llmin(ans, (llmin(llabs(x[i] - t[min]) + mt[min], llabs(x[i] - t[max]) + mt[max])));
		printf("%lld\n", ans);
	}
	return 0;
}
