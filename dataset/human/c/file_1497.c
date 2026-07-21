#include <stdio.h>
#include <string.h>

int main(void)
{
        char x[2],y[2];

        scanf("%s%s",x,y);

        if (strcmp(x,y)==0)
                printf("=\n");
        else if (strcmp(x,y)>0)
                printf(">\n");
        else
                printf("<\n");

        return 0;
}
