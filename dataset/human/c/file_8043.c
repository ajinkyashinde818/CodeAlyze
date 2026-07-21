#include<stdio.h>
int a[1003][1003];
int h[10000007], hl;
int comp_h(int x, int y)
{
	if (a[h[x] / 1003][h[x] % 1003] > a[h[y] / 1003][h[y] % 1003])
		return 1;
	else
		return -1;
}
void swap_h(int x, int y)
{
	int f = h[x];
	h[x] = h[y];
	h[y] = f;
	return;
}
void f1(int ne)
{
	h[hl] = ne;
	int p = hl;
	hl++;
	while (p > 0)
	{
		if (comp_h((p - 1) / 2, p) > 0)
			swap_h((p - 1) / 2, p);
		p = (p - 1) / 2;
	}
	return;
}
int f2()
{
	hl--;
	swap_h(0, hl);
	int p = 0;
	for (;;)
	{
		if (2 * p + 2 < hl)
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
		else if (2 * p + 1 < hl)
		{
			if (comp_h(p, 2 * p + 1) > 0)
				swap_h(p, 2 * p + 1);
			p = 2 * p + 1;
		}
		else
			break;
	}
	return h[hl];
}
int main()
{
	int h, w;
	scanf("%d %d", &h, &w);
	int ch, cw;
	scanf("%d %d", &ch, &cw);
	ch--;
	cw--;
	int dh, dw;
	scanf("%d %d", &dh, &dw);
	dh--;
	dw--;
	char s[1003][1003];
	int i, j;
	for (i = 0; i < h; i++)
		scanf("%s", s[i]);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			a[i][j] = -1;
	a[ch][cw] = 0;
	hl = 0;
	f1(1003 * ch + cw);
	while (hl > 0)
	{
		i = f2();
		j = i % 1003;
		i /= 1003;
		if (i - 2 >= 0)
		{
			if (j - 2 >= 0)
			{
				if (s[i - 2][j - 2] == '.')
				{
					if (a[i - 2][j - 2]<0 || a[i - 2][j - 2]>a[i][j] + 1)
					{
						a[i - 2][j - 2] = a[i][j] + 1;
						f1(1003 * (i - 2) + j - 2);
					}
				}
			}
			if (j - 1 >= 0)
			{
				if (s[i - 2][j - 1] == '.')
				{
					if (a[i - 2][j - 1]<0 || a[i - 2][j - 1]>a[i][j] + 1)
					{
						a[i - 2][j - 1] = a[i][j] + 1;
						f1(1003 * (i - 2) + j - 1);
					}
				}
			}
			if (s[i - 2][j] == '.')
			{
				if (a[i - 2][j]<0 || a[i - 2][j]>a[i][j] + 1)
				{
					a[i - 2][j] = a[i][j] + 1;
					f1(1003 * (i - 2) + j);
				}
			}
			if (j + 1 < w)
			{
				if (s[i - 2][j + 1] == '.')
				{
					if (a[i - 2][j + 1]<0 || a[i - 2][j + 1]>a[i][j] + 1)
					{
						a[i - 2][j + 1] = a[i][j] + 1;
						f1(1003 * (i - 2) + j + 1);
					}
				}
			}
			if (j + 2 < w)
			{
				if (s[i - 2][j + 2] == '.')
				{
					if (a[i - 2][j + 2]<0 || a[i - 2][j + 2]>a[i][j] + 1)
					{
						a[i - 2][j + 2] = a[i][j] + 1;
						f1(1003 * (i - 2) + j + 2);
					}
				}
			}
		}
		if (i - 1 >= 0)
		{
			if (j - 2 >= 0)
			{
				if (s[i - 1][j - 2] == '.')
				{
					if (a[i - 1][j - 2]<0 || a[i - 1][j - 2]>a[i][j] + 1)
					{
						a[i - 1][j - 2] = a[i][j] + 1;
						f1(1003 * (i - 1) + j - 2);
					}
				}
			}
			if (j - 1 >= 0)
			{
				if (s[i - 1][j - 1] == '.')
				{
					if (a[i - 1][j - 1]<0 || a[i - 1][j - 1]>a[i][j] + 1)
					{
						a[i - 1][j - 1] = a[i][j] + 1;
						f1(1003 * (i - 1) + j - 1);
					}
				}
			}
			if (s[i - 1][j] == '.')
			{
				if (a[i - 1][j]<0 || a[i - 1][j]>a[i][j])
				{
					a[i - 1][j] = a[i][j];
					f1(1003 * (i - 1) + j);
				}
			}
			if (j + 1 < w)
			{
				if (s[i - 1][j + 1] == '.')
				{
					if (a[i - 1][j + 1]<0 || a[i - 1][j + 1]>a[i][j] + 1)
					{
						a[i - 1][j + 1] = a[i][j] + 1;
						f1(1003 * (i - 1) + j + 1);
					}
				}
			}
			if (j + 2 < w)
			{
				if (s[i - 1][j + 2] == '.')
				{
					if (a[i - 1][j + 2]<0 || a[i - 1][j + 2]>a[i][j] + 1)
					{
						a[i - 1][j + 2] = a[i][j] + 1;
						f1(1003 * (i - 1) + j + 2);
					}
				}
			}
		}
		if (j - 2 >= 0)
		{
			if (s[i][j - 2] == '.')
			{
				if (a[i][j - 2]<0 || a[i][j - 2]>a[i][j] + 1)
				{
					a[i][j - 2] = a[i][j] + 1;
					f1(1003 * i + j - 2);
				}
			}
		}
		if (j - 1 >= 0)
		{
			if (s[i][j - 1] == '.')
			{
				if (a[i][j - 1]<0 || a[i][j - 1]>a[i][j])
				{
					a[i][j - 1] = a[i][j];
					f1(1003 * i + j - 1);
				}
			}
		}
		if (j + 1 < w)
		{
			if (s[i][j + 1] == '.')
			{
				if (a[i][j + 1]<0 || a[i][j + 1]>a[i][j])
				{
					a[i][j + 1] = a[i][j];
					f1(1003 * i + j + 1);
				}
			}
		}
		if (j + 2 < w)
		{
			if (s[i][j + 2] == '.')
			{
				if (a[i][j + 2]<0 || a[i][j + 2]>a[i][j] + 1)
				{
					a[i][j + 2] = a[i][j] + 1;
					f1(1003 * i + j + 2);
				}
			}
		}
		if (i + 1 < h)
		{
			if (j - 2 >= 0)
			{
				if (s[i + 1][j - 2] == '.')
				{
					if (a[i + 1][j - 2]<0 || a[i + 1][j - 2]>a[i][j] + 1)
					{
						a[i + 1][j - 2] = a[i][j] + 1;
						f1(1003 * (i + 1) + j - 2);
					}
				}
			}
			if (j - 1 >= 0)
			{
				if (s[i + 1][j - 1] == '.')
				{
					if (a[i + 1][j - 1]<0 || a[i + 1][j - 1]>a[i][j] + 1)
					{
						a[i + 1][j - 1] = a[i][j] + 1;
						f1(1003 * (i + 1) + j - 1);
					}
				}
			}
			if (s[i + 1][j] == '.')
			{
				if (a[i + 1][j]<0 || a[i + 1][j]>a[i][j])
				{
					a[i + 1][j] = a[i][j];
					f1(1003 * (i + 1) + j);
				}
			}
			if (j + 1 < w)
			{
				if (s[i + 1][j + 1] == '.')
				{
					if (a[i + 1][j + 1]<0 || a[i + 1][j + 1]>a[i][j] + 1)
					{
						a[i + 1][j + 1] = a[i][j] + 1;
						f1(1003 * (i + 1) + j + 1);
					}
				}
			}
			if (j + 2 < w)
			{
				if (s[i + 1][j + 2] == '.')
				{
					if (a[i + 1][j + 2]<0 || a[i + 1][j + 2]>a[i][j] + 1)
					{
						a[i + 1][j + 2] = a[i][j] + 1;
						f1(1003 * (i + 1) + j + 2);
					}
				}
			}
		}
		if (i + 2 < h)
		{
			if (j - 2 >= 0)
			{
				if (s[i + 2][j - 2] == '.')
				{
					if (a[i + 2][j - 2]<0 || a[i + 2][j - 2]>a[i][j] + 1)
					{
						a[i + 2][j - 2] = a[i][j] + 1;
						f1(1003 * (i + 2) + j - 2);
					}
				}
			}
			if (j - 1 >= 0)
			{
				if (s[i + 2][j - 1] == '.')
				{
					if (a[i + 2][j - 1]<0 || a[i + 2][j - 1]>a[i][j] + 1)
					{
						a[i + 2][j - 1] = a[i][j] + 1;
						f1(1003 * (i + 2) + j - 1);
					}
				}
			}
			if (s[i + 2][j] == '.')
			{
				if (a[i + 2][j]<0 || a[i + 2][j]>a[i][j] + 1)
				{
					a[i + 2][j] = a[i][j] + 1;
					f1(1003 * (i + 2) + j);
				}
			}
			if (j + 1 < w)
			{
				if (s[i + 2][j + 1] == '.')
				{
					if (a[i + 2][j + 1]<0 || a[i + 2][j + 1]>a[i][j] + 1)
					{
						a[i + 2][j + 1] = a[i][j] + 1;
						f1(1003 * (i + 2) + j + 1);
					}
				}
			}
			if (j + 2 < w)
			{
				if (s[i + 2][j + 2] == '.')
				{
					if (a[i + 2][j + 2]<0 || a[i + 2][j + 2]>a[i][j] + 1)
					{
						a[i + 2][j + 2] = a[i][j] + 1;
						f1(1003 * (i + 2) + j + 2);
					}
				}
			}
		}
	}
	printf("%d\n", a[dh][dw]);
	return 0;
}
