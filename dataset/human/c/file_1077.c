#include <stdio.h>
#include <string.h>

const char* mcxi = "mcxi";

int mcxi_to_int(const char* str)
{
    int i, res = 0, t = 1;

    for(i = 0; str[i]; i++)
        if(strchr(mcxi, str[i]))
        {
            switch(str[i])
            {
              case 'm': res += t * 1000; break;
              case 'c': res += t * 100; break;
              case 'x': res += t * 10; break;
              default: res += t;
            }
            t = 1;
        }
        else
            t = str[i] - '0';

    return res;
}

void print_mcxi(int n)
{
    int i;
    char buf[4];

    for(i = 3; i >= 0; i--, n /= 10)
        buf[i] = n % 10;

    for(i = 0; i < 4; i++)
        if(!buf[i])
            continue;
        else if(buf[i] == 1)
            putchar(mcxi[i]);
        else
            printf("%d%c", buf[i], mcxi[i]);

    puts("");
}

int main(void)
{
    char buf[9];
    int a, b;

    scanf("%*d%*c");

    while(~scanf("%s%*c", buf))
    {
        a = mcxi_to_int(buf);
        scanf("%s%*c", buf);
        b = mcxi_to_int(buf);
        print_mcxi(a + b);
    }

    return 0;
}
