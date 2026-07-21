#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
double cst[1002][1002];
double dist[1002];
bool flag[1002];
double x[1002], y[1002], r[1002];
int main()
{
	scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
	r[0] = r[1] = 0;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%lf%lf%lf", &x[i + 2], &y[i + 2], &r[i + 2]);
	fill(flag, flag + 1002, false);
	num += 2;
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)cst[i][j] = max(0.0, sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - r[i] - r[j]);
	fill(dist, dist + num, 100000000000000000000000000000000000000000000000000000000000000000000000000.0);
	dist[0] = 0;
	for (int i = 0; i < num; i++)
	{
		double mini = 100000000000000000000000000000000000000000000000000000000.0;
		int rr;
		for (int j = 0; j < num; j++)
		{
			if ((!flag[j]) && mini>dist[j])
			{
				mini = dist[j];
				rr = j;
			}
		}
		flag[rr] = true;
		for (int j = 0; j < num; j++)dist[j] = min(dist[j], dist[rr] + cst[rr][j]);
	}
	printf("%.20lf\n", dist[1]);
}
