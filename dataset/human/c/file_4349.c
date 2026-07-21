#include <stdio.h>

int             main(void)
{
        int     n;
        int     d[101][2];
        int     flag = 0;
        int     i;

        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
                scanf("%d%d", &d[i][0], &d[i][1]);
        }
        for (i = 0; i < n; i++)
        {
                if (d[i][0] == d[i][1])
                {
                        flag++;
                        if (flag == 3)
                        {
                                printf("Yes\n");
                                return (0);
                        }
                }
                else
                {
                        flag = 0;
                }
        }
        printf("No\n");
        return (0);
}
