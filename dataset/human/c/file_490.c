#include<stdio.h>
double abs(double p)
{
    if (p >= 0)
        return p;
    else
        return -p;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[200005];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    double sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    double min = 20000000000;
    double x = 0;
    for (i = 0; i < n - 1; i++)
    {
        x += a[i];
        if (abs(sum - x - x) < min)
            min = abs(sum - x - x);
    }
    printf("%.0lf\n",min);
    return 0;
}
