#include<stdio.h>
int main()
{
	long long int n, c;
	scanf("%lld %lld", &n, &c);
	long long int i;
	long long int x[100005], v[100005];
	for (i = 0; i < n; i++)
		scanf("%lld %lld", &x[i], &v[i]);
	long long int y[100005];
	for (i = 0; i < n; i++)
		y[n - i - 1] = c - x[n - i - 1];
	long long int sv1[100005], sv2[100005];
	sv1[0] = 0;
	for (i = 0; i < n; i++)
		sv1[i + 1] = sv1[i] + v[i];
	sv2[n] = 0;
	for (i = n - 1; i >= 0; i--)
		sv2[i] = sv2[i + 1] + v[i];
	long long int ans = 0;
	long long int max1[100005], max2[100005];
	max1[0] = 0;
	for (i = 0; i < n; i++)
	{
		if (max1[i] < sv1[i + 1] - x[i])
			max1[i + 1] = sv1[i + 1] - x[i];
		else
			max1[i + 1] = max1[i];
	}
	max2[n] = 0;
	for (i = n - 1; i >= 0; i--)
	{
		if (max2[i + 1] < sv2[i] - y[i])
			max2[i] = sv2[i] - y[i];
		else
			max2[i] = max2[i + 1];
	}
	if (ans < max1[n])ans = max1[n];
	if (ans < max2[0])ans = max2[0];
	for (i = 0; i < n; i++)
		if (ans < sv1[i + 1] - 2 * x[i] + max2[i + 1])
			ans = sv1[i + 1] - 2 * x[i] + max2[i + 1];
	for (i = 0; i < n; i++)
		if (ans < sv2[i] - 2 * y[i] + max1[i])
			ans = sv2[i] - 2 * y[i] + max1[i];
	printf("%lld\n", ans);
	return 0;
}
