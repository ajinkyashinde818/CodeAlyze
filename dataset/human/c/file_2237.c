#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	char buf_str[500002];
	int q;
	int start_h = 230001;
	int end_h = start_h;
	scanf("%s", &buf_str[start_h]);
	scanf("%d", &q);

	int index = start_h;
	while (buf_str[end_h] != '\0')
		end_h++;
	start_h = start_h - 1;

	int dq;
	int f;
	char c;
	int flag = 1;

	index = 0;
	while (index <q)
	{
		scanf("%d", &dq);
		if (dq == 1)
		{
			flag = flag * (-1);
		}
		else if (dq == 2)
		{
			scanf("%d %c", &f, &c);
			if ((f == 1 && flag == 1) || (f == 2 && flag == -1))
			{
				buf_str[start_h] = c;
				start_h = start_h -1;
			}
			else if ((f == 2 && flag ==1) || (f == 1 && flag == -1))
			{
				buf_str[end_h] = c;
				buf_str[end_h+1] = '\0';
				end_h++;
			}
		}
		index++;
	}
	index = 0;
	char *r_str = &buf_str[start_h +1];
	if (flag == -1)
	{
		while (index < (end_h - start_h - 1))
		{
			putchar_unlocked(buf_str[end_h-1-index]);
			index++;
		}
		putchar_unlocked('\n');
	}
	else
		printf("%s\n",r_str);
	return (0);
}
