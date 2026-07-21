#include<stdio.h>

int main(void)
{
	int hei1, wid1, hei2, wid2;
	int area1, area2;

	scanf("%d %d %d %d", &hei1, &wid1, &hei2, &wid2);

	area1 = hei1*wid1;
	area2 = hei2*wid2;

	if (area1 > area2)printf("%d", area1);
	else printf("%d", area2);

	return 0;
}
