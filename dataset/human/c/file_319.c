#include<stdio.h>
#include<math.h>
double x[1003], y[1003], r[1003];
double f(int i, int j)
{
	if (r[i] + r[j] > sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)))
		return 0.0;
	else
		return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) - r[i] - r[j];
}
double min[1003];
int h[1000006], l;
int comp_h(int a, int b)
{
	if (min[h[a]] > min[h[b]])
		return 1;
	else
		return -1;
}
void swap_h(int a, int b)
{
	int f = h[a];
	h[a] = h[b];
	h[b] = f;
	return;
}
void push(int ne)
{
	h[l] = ne;
	int p = l;
	l++;
	for (; p > 0; p = (p - 1) / 2)
		if (comp_h((p - 1) / 2, p) > 0)
			swap_h((p - 1) / 2, p);
	return;
}
int pop()
{
	l--;
	swap_h(0, l);
	int p = 0;
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
	double xs, ys, xt, yt;
	scanf("%lf %lf %lf %lf", &xs, &ys, &xt, &yt);
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
		scanf("%lf %lf %lf", &x[i + 1], &y[i + 1], &r[i + 1]);
	x[0] = xs;
	y[0] = ys;
	r[0] = 0;
	x[n + 1] = xt;
	y[n + 1] = yt;
	r[n + 1] = 0;
	for (i = 0; i < n + 2; i++)
		min[i] = 10000000000000;
	int used[1003];
	for (i = 0; i < n + 2; i++)
		used[i] = 0;
	l = 0;
	min[0] = 0;
	push(0);
	while (l > 0)
	{
		i = pop();
		if (used[i] > 0)
			continue;
		used[i]++;
		for (j = 0; j < n + 2; j++)
		{
			if (min[j] > min[i] + f(i, j))
			{
				min[j] = min[i] + f(i, j);
				if (used[j] == 0)
					push(j);
			}
		}
	}
	printf("%.20lf\n", min[n + 1]);
	return 0;
}
