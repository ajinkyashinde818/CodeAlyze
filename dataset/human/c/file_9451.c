#include<stdio.h>

int geshu(int ai, int day)
{
	int i;
	int  flag = 0;

	for (i = 1; i <= day; i=i+ai)
	{
		flag++;
	}

	return flag;
}


int main()
{
	int n;
	int a[100];
	int day;
	int rest;
	int i;
	int zgeshu;


	scanf("%d%d%d",&n,&day,&rest);
	zgeshu = rest;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		zgeshu = zgeshu + geshu(a[i], day);
	}
	
	printf("%d", zgeshu);

    return 0;
}
