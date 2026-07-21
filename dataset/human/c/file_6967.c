#include <stdio.h>


int main(void)
{
	while (1)
	{
		int h, w;
		scanf("%d %d", &h, &w);
		int flg = 0;

		if (h == 0 && w == 0)
		{
			break;
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if ((x + flg) % 2 == 0)
				{
					printf("#");
				}
				else
				{
					printf(".");
				}

				if (x == (w - 1))
				{
					printf("\n");
					if (flg == 0)
					{
						flg = 1;
					}
					else
					{
						flg = 0;
					}
				}
			}
		}

                          printf("\n");
	}
}
